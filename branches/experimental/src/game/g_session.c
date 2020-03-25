/*
=======================================================================

  SESSION DATA

Session data is the only data that stays persistant across level loads
and tournament restarts.
=======================================================================
*/

#include "g_local.h"
#include "../../etmain/ui/menudef.h"

/*
================
G_WriteClientSessionData

Called on game shutdown
================
*/
void G_WriteClientSessionData( gclient_t *client, qboolean restart )
{
#ifdef MV_SUPPORT
	int mvc = G_smvGenerateClientList(g_entities + (client - level.clients));
#endif

	const char	*s;

	// OSP -- stats reset check
	// tjw: stopped saving weapon stats between rounds so always
	//      reset stats.
	//if(level.fResetStats) G_deleteStats(client - level.clients);
	G_deleteStats(client - level.clients);

	// jet Pilot - Added killingSpree
#ifdef MV_SUPPORT
	//		 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
	s = va("%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %u",
#else
	//		 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
	s = va("%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %u",
#endif
		client->sess.sessionTeam,						// 0
		client->sess.spectatorTime,						// 1
		client->sess.spectatorState,					// 2
		client->sess.spectatorClient,					// 3
		client->sess.playerType,						// 4
		client->sess.playerWeapon,						// 5
		client->sess.playerWeapon2,						// 6
		client->sess.latchPlayerType,					// 7
		client->sess.latchPlayerWeapon,					// 8
		client->sess.latchPlayerWeapon2,				// 9
		client->sess.coach_team,						// 10
		client->sess.deaths,							// 11
		client->sess.game_points,						// 12
		client->sess.kills,								// 13
		client->sess.referee,							// 14
		client->sess.spec_invite,						// 15
		client->sess.spec_team,							// 16
		client->sess.suicides,							// 17
		client->sess.team_kills,						// 18
		client->sess.newton,							// 19
#ifdef MV_SUPPORT
		(mvc & 0xFFFF),									// 20
		((mvc >> 16) & 0xFFFF),							// 21
#endif
		client->sess.muted_by,							// 22	//20
		client->sess.muted,								// 23	//21
		client->sess.auto_mute_time,					// 24	//22
		client->sess.ignoreClients[0],					// 25	//23
		client->sess.ignoreClients[1],					// 26	//24
		client->pers.enterTime,							// 27	//25
		restart ? client->sess.spawnObjectiveIndex : 0,	// 28	//26
		client->sess.rifleNade,							// 29	//27
		client->sess.executions,						// 30	//28
		client->sess.killingSpree,						// 31	//29
		client->sess.uci								// 32	//30	mcwf GeoIP
		);


	trap_Cvar_Set( va( "session%i", client - level.clients ), s );

	// Arnout: store the clients stats (7) and medals (7)
	// addition: but only if it isn't a forced map_restart (done by someone on the console)
	// tjw: go ahead and write them if the server has g_XPSave with the 2 flag
	if ( !(g_gametype.integer == GT_WOLF_STOPWATCH  && (g_XPSave.integer & XPSF_DISABLE_STOPWATCH)) ) {
		if( !(restart && !level.warmupTime) || (g_XPSave.integer & XPSF_NR_MAPRESET)) {
			s = va( "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %i %i %i %i %i %i %i",
				client->sess.skillpoints[0],
				client->sess.skillpoints[1],
				client->sess.skillpoints[2],
				client->sess.skillpoints[3],
				client->sess.skillpoints[4],
				client->sess.skillpoints[5],
				client->sess.skillpoints[6],
				client->sess.medals[0],
				client->sess.medals[1],
				client->sess.medals[2],
				client->sess.medals[3],
				client->sess.medals[4],
				client->sess.medals[5],
				client->sess.medals[6]
				);

			trap_Cvar_Set( va( "sessionstats%i", client - level.clients ), s );
		}
	}
}

/*
================
G_ClientSwap

Client swap handling
================
*/
void G_ClientSwap(gclient_t *client)
{
	int flags = 0;

	if(client->sess.sessionTeam == TEAM_AXIS) client->sess.sessionTeam = TEAM_ALLIES;
	else if(client->sess.sessionTeam == TEAM_ALLIES) client->sess.sessionTeam = TEAM_AXIS;

	// Swap spec invites as well
	if(client->sess.spec_invite & TEAM_AXIS) flags |= TEAM_ALLIES;
	if(client->sess.spec_invite & TEAM_ALLIES) flags |= TEAM_AXIS;

	client->sess.spec_invite = flags;

	// Swap spec follows as well
	flags = 0;
	if(client->sess.spec_team & TEAM_AXIS) flags |= TEAM_ALLIES;
	if(client->sess.spec_team & TEAM_ALLIES) flags |= TEAM_AXIS;

	client->sess.spec_team = flags;
}

extern int rankTable[NUM_EXPERIENCE_LEVELS];

/*
==================
G_CalcRank

jaquboss, new function
==================
*/
void G_CalcRank( gclient_t* client )
{
	int i, cnt = 0;
	int next=0;

	client->sess.rank = 0;

	for( i = 0; i < SK_NUM_SKILLS; ++i ) {
		G_SetPlayerSkill( client, i );
		cnt += client->sess.skill[ i ];
	}

	for ( i = NUM_EXPERIENCE_LEVELS-1; i > 0; i-- ) {
		next = rankTable[i-1];
		if ( cnt >= next && client->sess.rank < NUM_EXPERIENCE_LEVELS-1  ) {
			client->sess.rank = i;
			break;
		}
	}
}


/*
================
G_ReadSessionData

Called on a reconnect
================
*/
void G_ReadSessionData( gclient_t *client )
{
#ifdef MV_SUPPORT
	int mvc_l, mvc_h;
#endif
	char s[MAX_STRING_CHARS];
	qboolean test;
	qboolean load = qfalse;

	trap_Cvar_VariableStringBuffer( va( "session%i", client - level.clients ), s, sizeof(s) );

	// jet Pilot - added killingSpree
	// Jaybird - fixed to match with writesessiondata

#ifdef MV_SUPPORT
	//			 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
	sscanf( s, "%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %u",
#else
	//			 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
	sscanf( s, "%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %u",
#endif
		(int *)&client->sess.sessionTeam,		// 0
		&client->sess.spectatorTime,			// 1
		(int *)&client->sess.spectatorState,	// 2
		&client->sess.spectatorClient,			// 3
		&client->sess.playerType,				// 4
		&client->sess.playerWeapon,				// 5
		&client->sess.playerWeapon2,			// 6
		&client->sess.latchPlayerType,			// 7
		&client->sess.latchPlayerWeapon,		// 8
		&client->sess.latchPlayerWeapon2,		// 9
		&client->sess.coach_team,				// 10
		&client->sess.deaths,					// 11
		&client->sess.game_points,				// 12
		&client->sess.kills,					// 13
		&client->sess.referee,					// 14
		&client->sess.spec_invite,				// 15
		&client->sess.spec_team,				// 16
		&client->sess.suicides,					// 17
		&client->sess.team_kills,				// 18
		&client->sess.newton,					// 19
#ifdef MV_SUPPORT
		&mvc_l,									// 20
		&mvc_h,									// 21
#endif
		&client->sess.muted_by,					// 22   //20
		(int *)&client->sess.muted,				// 23	//21
		&client->sess.auto_mute_time,			// 24	//22
		&client->sess.ignoreClients[0],			// 25	//23
		&client->sess.ignoreClients[1],			// 26	//24
		&client->pers.enterTime,				// 27	//25
		&client->sess.spawnObjectiveIndex,		// 28	//26
		&client->sess.rifleNade,				// 29	//27
		&client->sess.executions,				// 30	//28
		&client->sess.killingSpree,				// 31	//29
		&client->sess.uci						// 32,	//30	mcwf GeoIP
		);

#ifdef MV_SUPPORT
	// OSP -- reinstate MV clients
	client->pers.mvReferenceList = (mvc_h << 16) | mvc_l;
	// OSP
#endif

	if(g_gametype.integer == GT_WOLF_CAMPAIGN) {
		// tjw: only load scores back in if this map isn't starting a new campaign
		load = !(g_campaigns[level.currentCampaign].current == 0 || level.newCampaign);
	}

	if(g_gametype.integer == GT_WOLF_LMS) {
		// tjw: only load scores back if this isn't the first round
		load = (g_currentRound.integer != 0);
	}

	switch(g_gametype.integer) {
		case GT_WOLF_CAMPAIGN:
		case GT_WOLF_LMS:
		case GT_WOLF_STOPWATCH:
		case GT_WOLF:
		case GT_WOLF_MAPVOTE:
			if(g_XPSave.integer & XPSF_NR_EVER) {
				load = qtrue;
			}
			if((g_XPSave.integer & XPSF_NR_MAPRESET) && g_reset.integer) {
				load = qtrue;
			}
			if ( g_gametype.integer == GT_WOLF_STOPWATCH  && (g_XPSave.integer & XPSF_DISABLE_STOPWATCH) ) {
				load = qfalse;
			}
	}

	if(load) {
		trap_Cvar_VariableStringBuffer( va( "sessionstats%i", client - level.clients ), s, sizeof(s) );
		// Arnout: read the clients stats (7) and medals (7)
		sscanf( s, "%f %f %f %f %f %f %f %i %i %i %i %i %i %i",
			&client->sess.skillpoints[0],
			&client->sess.skillpoints[1],
			&client->sess.skillpoints[2],
			&client->sess.skillpoints[3],
			&client->sess.skillpoints[4],
			&client->sess.skillpoints[5],
			&client->sess.skillpoints[6],
			&client->sess.medals[0],
			&client->sess.medals[1],
			&client->sess.medals[2],
			&client->sess.medals[3],
			&client->sess.medals[4],
			&client->sess.medals[5],
			&client->sess.medals[6]
			);
	}

	G_CalcRank( client );

	test = (g_altStopwatchMode.integer != 0 || g_currentRound.integer == 1);

	if(g_gametype.integer == GT_WOLF_STOPWATCH && g_gamestate.integer != GS_PLAYING && test) {
		G_ClientSwap(client);
	}

	if ( g_swapteams.integer ) {
		trap_Cvar_Set( "g_swapteams", "0" );
		G_ClientSwap(client);
	}

	{
		int j;

		client->sess.startxptotal = 0;
		for( j = 0; j < SK_NUM_SKILLS; ++j ) {
			client->sess.startskillpoints[j] = client->sess.skillpoints[j];
			client->sess.startxptotal += client->sess.skillpoints[j];
		}
	}
}


/*
================
G_InitSessionData

Called on a first-time connect
================
*/
void G_InitSessionData( gclient_t *client, char *userinfo )
{
	clientSession_t	*sess = &client->sess;

	// initial team determination
	sess->sessionTeam			= TEAM_SPECTATOR;

	sess->spectatorState		= SPECTATOR_FREE;
	sess->spectatorTime			= level.time;

	// DHM - Nerve
	sess->latchPlayerType		= sess->playerType = 0;
	sess->latchPlayerWeapon 	= sess->playerWeapon = 0;
	sess->latchPlayerWeapon2	= sess->playerWeapon2 = 0;
	sess->rifleNade	 = 0;

	sess->spawnObjectiveIndex	= 0;
	// dhm - end

	memset( sess->ignoreClients, 0, sizeof(sess->ignoreClients) );
	sess->muted					= qfalse;
	sess->auto_mute_time		= -1;
	memset( sess->skill, 0, sizeof(sess->skill) );
	memset( sess->skillpoints, 0, sizeof(sess->skillpoints) );
	// CHRUKER: b017 - startskillpoints didn't get reset
	memset( sess->startskillpoints, 0, sizeof(sess->startskillpoints) );
	memset( sess->medals, 0, sizeof(sess->medals) );
	sess->rank					= 0;
	// CHRUKER: b017 - startxptotal didn't get reset
	sess->startxptotal			= 0;

	// OSP
	sess->coach_team			= 0;
	sess->referee				= (client->pers.localClient) ? RL_REFEREE : RL_NONE;
	sess->spec_invite			= 0;
	sess->spec_team				= 0;
	G_deleteStats(client - level.clients);
	// OSP

	sess->uci = 0; //mcwf GeoIP

	G_WriteClientSessionData( client, qfalse );
}

/*
==================
G_InitWorldSession
==================
*/
void G_InitWorldSession( void )
{
	char	s[MAX_STRING_CHARS];
	int		gt;
	int		i, j;

	trap_Cvar_VariableStringBuffer( "session", s, sizeof(s) );
	gt = atoi( s );

	// if the gametype changed since the last session, don't use any
	// client sessions
	if ( g_gametype.integer != gt ) {
		level.newSession = qtrue;
		level.fResetStats = qtrue;
		G_Printf( "Gametype changed, clearing session data.\n" );

	}
	else {
		char *tmp = s;
		qboolean test = (g_altStopwatchMode.integer != 0 || g_currentRound.integer == 1);


#define GETVAL(x) if((tmp = strchr(tmp, ' ')) == NULL) return; x = atoi(++tmp);

		// Get team lock stuff
		GETVAL(gt);
		teamInfo[TEAM_AXIS].spec_lock = (gt & TEAM_AXIS) ? qtrue : qfalse;
		teamInfo[TEAM_ALLIES].spec_lock = (gt & TEAM_ALLIES) ? qtrue : qfalse;
		GETVAL(level.nextBanner);

		// See if we need to clear player stats
		// FIXME: deal with the multi-map missions
		if(g_gametype.integer != GT_WOLF_CAMPAIGN) {
			if((tmp = strchr(va("%s", tmp), ' ')) != NULL) {
				tmp++;
				trap_GetServerinfo(s, sizeof(s));
				if(Q_stricmp(tmp, Info_ValueForKey(s, "mapname"))) {
					level.fResetStats = qtrue;
					G_Printf("Map changed, clearing player stats.\n");
				}
			}
		}

		// OSP - have to make sure spec locks follow the right teams
		if(g_gametype.integer == GT_WOLF_STOPWATCH && g_gamestate.integer != GS_PLAYING && test) {
			G_swapTeamLocks();
		}

		if(g_swapteams.integer) {
			G_swapTeamLocks();
		}
	}

	for( i = 0; i < MAX_FIRETEAMS; ++i ) {
		char *p, *c;

		trap_Cvar_VariableStringBuffer( va("fireteam%i", i), s, sizeof(s) );

		p = Info_ValueForKey( s, "k" ); // "id" -> "k"
		j = atoi(p);
		if(!*p || j == -1) {
			level.fireTeams[i].inuse = qfalse;
		}
		else {
			level.fireTeams[i].inuse = qtrue;
		}
		level.fireTeams[i].ident = j + 1;

		p = Info_ValueForKey( s, "p" );
		level.fireTeams[i].priv = !atoi( p ) ? qfalse : qtrue;

		p = Info_ValueForKey( s, "i" );

		j = 0;
		if(p && *p) {
			c = p;
			for(c = strchr(c, ' ')+1; c && *c; ) {
				char str[8];
				char* l = strchr(c, ' ');
				if(!l) {
					break;
				}
				Q_strncpyz( str, c, l - c + 1 );
				str[l - c] = '\0';
				level.fireTeams[i].joinOrder[j++] = atoi(str);
				c = l + 1;
			}
		}

		for( ;j < g_maxclients.integer; ++j ) {
			level.fireTeams[i].joinOrder[j] = -1;
		}
		G_UpdateFireteamConfigString(&level.fireTeams[i]);
	}
}

/*
==================
G_WriteSessionData
==================
*/
void G_WriteSessionData( qboolean restart )
{
	int		i;
	char	strServerInfo[MAX_INFO_STRING];
	int		j;

	trap_GetServerinfo(strServerInfo, sizeof(strServerInfo));

	trap_Cvar_Set("session", va("%i %i %d %s", g_gametype.integer,
		(teamInfo[TEAM_AXIS].spec_lock * TEAM_AXIS | teamInfo[TEAM_ALLIES].spec_lock * TEAM_ALLIES),
		level.nextBanner, Info_ValueForKey(strServerInfo, "mapname")));

	// Keep stats for all players in sync
	for( i = 0; !level.fResetStats && i < level.numConnectedClients; ++i ) {
		if((g_gamestate.integer == GS_WARMUP_COUNTDOWN &&
		  ((g_gametype.integer == GT_WOLF_STOPWATCH && level.clients[level.sortedClients[i]].sess.rounds >= 2) ||
		   (g_gametype.integer != GT_WOLF_STOPWATCH && level.clients[level.sortedClients[i]].sess.rounds >= 1))))
			   level.fResetStats = qtrue;
	}

	for( i = 0; i < level.numConnectedClients; ++i ) {
		if(level.clients[level.sortedClients[i]].pers.connected == CON_CONNECTED) {
			G_WriteClientSessionData(&level.clients[level.sortedClients[i]], restart);
		}
		else if(level.fResetStats) {
			// For slow connecters and a short warmup
			G_deleteStats(level.sortedClients[i]);
		}
	}

	for( i = 0; i < MAX_FIRETEAMS; ++i ) {
		char buffer[MAX_STRING_CHARS];
		if(!level.fireTeams[i].inuse) {
			Com_sprintf(buffer, MAX_STRING_CHARS, "\\k\\-1"); // id -> k
		}
		else {
			char buffer2[MAX_STRING_CHARS];

			*buffer2 = '\0';

			for( j = 0; j < g_maxclients.integer; ++j ) {
				char p[8];
				Com_sprintf(p, 8, " %i", level.fireTeams[i].joinOrder[j]);
				Q_strcat(buffer2, MAX_STRING_CHARS, p);
			}
			// id -> k
			Com_sprintf(buffer, MAX_STRING_CHARS, "\\k\\%i\\i\\%s\\p\\%i", level.fireTeams[i].ident - 1, buffer2, level.fireTeams[i].priv ? 1 : 0 );
		}

		trap_Cvar_Set(va("fireteam%i", i), buffer);
	}
}
