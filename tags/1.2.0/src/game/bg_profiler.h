#ifndef NQ_BG_PROFILER_H
#define NQ_BG_PROFILER_H

#include "g_local.h"

// Turn on the profiling support....
#ifndef WIN32
#define NQ_USE_PROFILER
#endif
#ifdef NQ_USE_PROFILER

extern void BG_ProfilerBlockStartTimer(int block_id, qboolean recursive);
extern void BG_ProfilerBlockStopTimer(int block_id);
extern void BG_ProfilerBlockSetName(int block_id, char const* name);

#else

#define BG_ProfilerBlockStartTimer(X, Y) /* X Y */
#define BG_ProfilerBlockStopTimer(X) /* X */
#define BG_ProfilerBlockSetName(X, Y) /* X Y */

#endif // NQ_USE_PROFILER

#define PROFILE_RUN_FRAME_STAGE_1		0
#define PROFILE_RUN_FRAME_STAGE_2		1
#define PROFILE_RUN_FRAME_STAGE_3		2
#define PROFILE_RUN_FRAME_STAGE_4		3
#define PROFILE_RUN_FRAME_STAGE_5		4
#define PROFILE_RUN_FRAME_STAGE_6		5
#define PROFILE_RUN_FRAME_STAGE_7		6
#define PROFILE_RUN_FRAME_STAGE_8		7

#define PROFILE_RUN_ENTITY_STAGE_1		8
#define PROFILE_RUN_ENTITY_STAGE_2		9
#define PROFILE_RUN_ENTITY_STAGE_3		10
#define PROFILE_RUN_ENTITY_STAGE_4		11
#define PROFILE_RUN_ENTITY_STAGE_5		12
#define PROFILE_RUN_ENTITY_STAGE_6		13
#define PROFILE_RUN_ENTITY_STAGE_7		14
#define PROFILE_RUN_ENTITY_STAGE_8		15
#define PROFILE_RUN_ENTITY_STAGE_9		16
#define PROFILE_RUN_ENTITY_STAGE_10		17

#define PROFILER_G_Script_ScriptRun		18
#define PROFILER_G_RunMissile			19
#define PROFILER_G_RunThink				20
#define PROFILER_G_RunFlamechunk		21
#define PROFILER_G_RunItem				22
#define PROFILER_G_RunMover				23
#define PROFILER_G_RunClient			24

#define PROFILE_ENTITY_TYPE_BASE		25
#define PROFILE_ENTITY_TYPE_ET_GENERAL				(PROFILE_ENTITY_TYPE_BASE + ET_GENERAL)
#define PROFILE_ENTITY_TYPE_ET_PLAYER				(PROFILE_ENTITY_TYPE_BASE + ET_PLAYER)
#define PROFILE_ENTITY_TYPE_ET_ITEM					(PROFILE_ENTITY_TYPE_BASE + ET_ITEM)
#define PROFILE_ENTITY_TYPE_ET_MISSILE				(PROFILE_ENTITY_TYPE_BASE + ET_MISSILE)
#define PROFILE_ENTITY_TYPE_ET_MOVER				(PROFILE_ENTITY_TYPE_BASE + ET_MOVER)
#define PROFILE_ENTITY_TYPE_ET_BEAM					(PROFILE_ENTITY_TYPE_BASE + ET_BEAM)
#define PROFILE_ENTITY_TYPE_ET_PORTAL				(PROFILE_ENTITY_TYPE_BASE + ET_PORTAL)
#define PROFILE_ENTITY_TYPE_ET_SPEAKER				(PROFILE_ENTITY_TYPE_BASE + ET_SPEAKER)
#define PROFILE_ENTITY_TYPE_ET_PUSH_TRIGGER			(PROFILE_ENTITY_TYPE_BASE + ET_PUSH_TRIGGER)
#define PROFILE_ENTITY_TYPE_ET_TELEPORT_TRIGGER		(PROFILE_ENTITY_TYPE_BASE + ET_TELEPORT_TRIGGER)
#define PROFILE_ENTITY_TYPE_ET_INVISIBLE			(PROFILE_ENTITY_TYPE_BASE + ET_INVISIBLE)
#define PROFILE_ENTITY_TYPE_ET_CONCUSSIVE_TRIGGER	(PROFILE_ENTITY_TYPE_BASE + ET_CONCUSSIVE_TRIGGER)
#define PROFILE_ENTITY_TYPE_ET_OID_TRIGGER			(PROFILE_ENTITY_TYPE_BASE + ET_OID_TRIGGER)
#define PROFILE_ENTITY_TYPE_ET_EXPLOSIVE_INDICATOR	(PROFILE_ENTITY_TYPE_BASE + ET_EXPLOSIVE_INDICATOR)
#define PROFILE_ENTITY_TYPE_ET_EXPLOSIVE			(PROFILE_ENTITY_TYPE_BASE + ET_EXPLOSIVE)
#define PROFILE_ENTITY_TYPE_ET_EF_SPOTLIGHT			(PROFILE_ENTITY_TYPE_BASE + ET_EF_SPOTLIGHT)
#define PROFILE_ENTITY_TYPE_ET_ALARMBOX				(PROFILE_ENTITY_TYPE_BASE + ET_ALARMBOX)
#define PROFILE_ENTITY_TYPE_ET_CORONA				(PROFILE_ENTITY_TYPE_BASE + ET_CORONA)
#define PROFILE_ENTITY_TYPE_ET_TRAP					(PROFILE_ENTITY_TYPE_BASE + ET_TRAP)
#define PROFILE_ENTITY_TYPE_ET_GAMEMODEL			(PROFILE_ENTITY_TYPE_BASE + ET_GAMEMODEL)
#define PROFILE_ENTITY_TYPE_ET_FOOTLOCKER			(PROFILE_ENTITY_TYPE_BASE + ET_FOOTLOCKER)
#define PROFILE_ENTITY_TYPE_ET_FLAMEBARREL			(PROFILE_ENTITY_TYPE_BASE + ET_FLAMEBARREL)
#define PROFILE_ENTITY_TYPE_ET_FP_PARTS				(PROFILE_ENTITY_TYPE_BASE + ET_FP_PARTS)
#define PROFILE_ENTITY_TYPE_ET_FIRE_COLUMN			(PROFILE_ENTITY_TYPE_BASE + ET_FIRE_COLUMN)
#define PROFILE_ENTITY_TYPE_ET_FIRE_COLUMN_SMOKE	(PROFILE_ENTITY_TYPE_BASE + ET_FIRE_COLUMN_SMOKE)
#define PROFILE_ENTITY_TYPE_ET_RAMJET				(PROFILE_ENTITY_TYPE_BASE + ET_RAMJET)
#define PROFILE_ENTITY_TYPE_ET_FLAMETHROWER_CHUNK	(PROFILE_ENTITY_TYPE_BASE + ET_FLAMETHROWER_CHUNK)
#define PROFILE_ENTITY_TYPE_ET_EXPLO_PART			(PROFILE_ENTITY_TYPE_BASE + ET_EXPLO_PART)
#define PROFILE_ENTITY_TYPE_ET_PROP					(PROFILE_ENTITY_TYPE_BASE + ET_PROP)
#define PROFILE_ENTITY_TYPE_ET_AI_EFFECT			(PROFILE_ENTITY_TYPE_BASE + ET_AI_EFFECT)
#define PROFILE_ENTITY_TYPE_ET_CAMERA				(PROFILE_ENTITY_TYPE_BASE + ET_CAMERA)
#define PROFILE_ENTITY_TYPE_ET_MOVERSCALED			(PROFILE_ENTITY_TYPE_BASE + ET_MOVERSCALED)
#define PROFILE_ENTITY_TYPE_ET_CONSTRUCTIBLE_INDICATOR	(PROFILE_ENTITY_TYPE_BASE + ET_CONSTRUCTIBLE_INDICATOR)
#define PROFILE_ENTITY_TYPE_ET_CONSTRUCTIBLE		(PROFILE_ENTITY_TYPE_BASE + ET_CONSTRUCTIBLE)
#define PROFILE_ENTITY_TYPE_ET_CONSTRUCTIBLE_MARKER	(PROFILE_ENTITY_TYPE_BASE + ET_CONSTRUCTIBLE_MARKER)
#define PROFILE_ENTITY_TYPE_ET_BOMB					(PROFILE_ENTITY_TYPE_BASE + ET_BOMB)
#define PROFILE_ENTITY_TYPE_ET_WAYPOINT				(PROFILE_ENTITY_TYPE_BASE + ET_WAYPOINT)
#define PROFILE_ENTITY_TYPE_ET_BEAM_2				(PROFILE_ENTITY_TYPE_BASE + ET_BEAM_2)
#define PROFILE_ENTITY_TYPE_ET_TANK_INDICATOR		(PROFILE_ENTITY_TYPE_BASE + ET_TANK_INDICATOR)
#define PROFILE_ENTITY_TYPE_ET_TANK_INDICATOR_DEAD 	(PROFILE_ENTITY_TYPE_BASE + ET_TANK_INDICATOR_DEAD)
#define PROFILE_ENTITY_TYPE_ET_BOTGOAL_INDICATOR	(PROFILE_ENTITY_TYPE_BASE + ET_BOTGOAL_INDICATOR)
#define PROFILE_ENTITY_TYPE_ET_CORPSE				(PROFILE_ENTITY_TYPE_BASE + ET_CORPSE)
#define PROFILE_ENTITY_TYPE_ET_SMOKER				(PROFILE_ENTITY_TYPE_BASE + ET_SMOKER)
#define PROFILE_ENTITY_TYPE_ET_TEMPHEAD				(PROFILE_ENTITY_TYPE_BASE + ET_TEMPHEAD)
#define PROFILE_ENTITY_TYPE_ET_MG_BARREL			(PROFILE_ENTITY_TYPE_BASE + ET_MG42_BARREL)
#define PROFILE_ENTITY_TYPE_ET_TEMPLEGS				(PROFILE_ENTITY_TYPE_BASE + ET_TEMPLEGS)
#define PROFILE_ENTITY_TYPE_ET_TRIGGER_MULTIPLE		(PROFILE_ENTITY_TYPE_BASE + ET_TRIGGER_MULTIPLE)
#define PROFILE_ENTITY_TYPE_ET_TRIGGER_FLAGONLY		(PROFILE_ENTITY_TYPE_BASE + ET_TRIGGER_FLAGONLY)
#define PROFILE_ENTITY_TYPE_ET_TRIGGER_FLAGONLY_MULTIPLE	(PROFILE_ENTITY_TYPE_BASE + ET_TRIGGER_FLAGONLY_MULTIPLE)
#define PROFILE_ENTITY_TYPE_ET_GAMEMANAGER			(PROFILE_ENTITY_TYPE_BASE + ET_GAMEMANAGER)
#define PROFILE_ENTITY_TYPE_ET_AAGUN				(PROFILE_ENTITY_TYPE_BASE + ET_AAGUN)
#define PROFILE_ENTITY_TYPE_ET_CABINET_H			(PROFILE_ENTITY_TYPE_BASE + ET_CABINET_H)
#define PROFILE_ENTITY_TYPE_ET_CABINET_A			(PROFILE_ENTITY_TYPE_BASE + ET_CABINET_A)
#define PROFILE_ENTITY_TYPE_ET_HEALER				(PROFILE_ENTITY_TYPE_BASE + ET_HEALER)
#define PROFILE_ENTITY_TYPE_ET_SUPPLIER				(PROFILE_ENTITY_TYPE_BASE + ET_SUPPLIER)
#define PROFILE_ENTITY_TYPE_ET_LANDMINE_HINT		(PROFILE_ENTITY_TYPE_BASE + ET_LANDMINE_HINT)
#define PROFILE_ENTITY_TYPE_ET_ATTRACTOR_HINT		(PROFILE_ENTITY_TYPE_BASE + ET_ATTRACTOR_HINT)
#define PROFILE_ENTITY_TYPE_ET_SNIPER_HINT			(PROFILE_ENTITY_TYPE_BASE + ET_SNIPER_HINT)
#define PROFILE_ENTITY_TYPE_ET_LANDMINESPOT_HINT	(PROFILE_ENTITY_TYPE_BASE + ET_LANDMINESPOT_HINT)
#define PROFILE_ENTITY_TYPE_ET_COMMANDMAP_MARKER	(PROFILE_ENTITY_TYPE_BASE + ET_COMMANDMAP_MARKER)
#define PROFILE_ENTITY_TYPE_ET_WOLF_OBJECTIVE		(PROFILE_ENTITY_TYPE_BASE + ET_WOLF_OBJECTIVE)
#define PROFILE_ENTITY_TYPE_ET_MISSILECAM			(PROFILE_ENTITY_TYPE_BASE + ET_MISSILECAM)
#define PROFILE_ENTITY_EVENT						(PROFILE_ENTITY_TYPE_BASE + ET_EVENTS)

#define PROFILE_EV_NONE								(PROFILE_ENTITY_EVENT + EV_NONE)
#define PROFILE_EV_FOOTSTEP							(PROFILE_ENTITY_EVENT + EV_FOOTSTEP)
#define PROFILE_EV_FOOTSTEP_METAL					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_METAL)
#define PROFILE_EV_FOOTSTEP_WOOD					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_WOOD)
#define PROFILE_EV_FOOTSTEP_GRASS					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_GRASS)
#define PROFILE_EV_FOOTSTEP_GRAVEL					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_GRAVEL)
#define PROFILE_EV_FOOTSTEP_ROOF					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_ROOF)
#define PROFILE_EV_FOOTSTEP_SNOW					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_SNOW)
#define PROFILE_EV_FOOTSTEP_CARPET					(PROFILE_ENTITY_EVENT + EV_FOOTSTEP_CARPET)
#define PROFILE_EV_FOOTSPLASH						(PROFILE_ENTITY_EVENT + EV_FOOTSPLASH)
#define PROFILE_EV_FOOTWADE							(PROFILE_ENTITY_EVENT + EV_FOOTWADE)
#define PROFILE_EV_SWIM								(PROFILE_ENTITY_EVENT + EV_SWIM)
#define PROFILE_EV_STEP_4							(PROFILE_ENTITY_EVENT + EV_STEP_4)
#define PROFILE_EV_STEP_8							(PROFILE_ENTITY_EVENT + EV_STEP_8)
#define PROFILE_EV_STEP_12							(PROFILE_ENTITY_EVENT + EV_STEP_12)
#define PROFILE_EV_STEP_16							(PROFILE_ENTITY_EVENT + EV_STEP_16)
#define PROFILE_EV_FALL_SHORT						(PROFILE_ENTITY_EVENT + EV_FALL_SHORT)
#define PROFILE_EV_FALL_MEDIUM						(PROFILE_ENTITY_EVENT + EV_FALL_MEDIUM)
#define PROFILE_EV_FALL_FAR							(PROFILE_ENTITY_EVENT + EV_FALL_FAR)
#define PROFILE_EV_FALL_NDIE					(PROFILE_ENTITY_EVENT + EV_FALL_NDIE)
#define PROFILE_EV_FALL_DMG_10					(PROFILE_ENTITY_EVENT + EV_FALL_DMG_10)
#define PROFILE_EV_FALL_DMG_15					(PROFILE_ENTITY_EVENT + EV_FALL_DMG_15)
#define PROFILE_EV_FALL_DMG_25					(PROFILE_ENTITY_EVENT + EV_FALL_DMG_25)
#define PROFILE_EV_FALL_DMG_50					(PROFILE_ENTITY_EVENT + EV_FALL_DMG_50)
#define PROFILE_EV_JUMP					(PROFILE_ENTITY_EVENT + EV_JUMP)
#define PROFILE_EV_WATER_TOUCH					(PROFILE_ENTITY_EVENT + EV_WATER_TOUCH)
#define PROFILE_EV_WATER_LEAVE					(PROFILE_ENTITY_EVENT + EV_WATER_LEAVE)
#define PROFILE_EV_WATER_UNDER					(PROFILE_ENTITY_EVENT + EV_WATER_UNDER)
#define PROFILE_EV_WATER_CLEAR					(PROFILE_ENTITY_EVENT + EV_WATER_CLEAR)
#define PROFILE_EV_ITEM_PICKUP					(PROFILE_ENTITY_EVENT + EV_ITEM_PICKUP)
#define PROFILE_EV_ITEM_PICKUP_QUIET					(PROFILE_ENTITY_EVENT + EV_ITEM_PICKUP_QUIET)
#define PROFILE_EV_GLOBAL_ITEM_PICKUP					(PROFILE_ENTITY_EVENT + EV_GLOBAL_ITEM_PICKUP)
#define PROFILE_EV_NOAMMO					(PROFILE_ENTITY_EVENT + EV_NOAMMO)
#define PROFILE_EV_WEAPONSWITCHED					(PROFILE_ENTITY_EVENT + EV_WEAPONSWITCHED)
#define PROFILE_EV_EMPTYCLIP					(PROFILE_ENTITY_EVENT + EV_EMPTYCLIP)
#define PROFILE_EV_FILL_CLIP					(PROFILE_ENTITY_EVENT + EV_FILL_CLIP)
#define PROFILE_EV_MG42_FIXED					(PROFILE_ENTITY_EVENT + EV_MG42_FIXED)
#define PROFILE_EV_WEAP_OVERHEAT					(PROFILE_ENTITY_EVENT + EV_WEAP_OVERHEAT)
#define PROFILE_EV_CHANGE_WEAPON					(PROFILE_ENTITY_EVENT + EV_CHANGE_WEAPON)
#define PROFILE_EV_CHANGE_WEAPON_2					(PROFILE_ENTITY_EVENT + EV_CHANGE_WEAPON_2)
#define PROFILE_EV_FIRE_WEAPON					(PROFILE_ENTITY_EVENT + EV_FIRE_WEAPON)
#define PROFILE_EV_FIRE_WEAPONB					(PROFILE_ENTITY_EVENT + EV_FIRE_WEAPONB)
#define PROFILE_EV_FIRE_WEAPON_LASTSHOT					(PROFILE_ENTITY_EVENT + EV_FIRE_WEAPON_LASTSHOT)
#define PROFILE_EV_NOFIRE_UNDERWATER					(PROFILE_ENTITY_EVENT + EV_NOFIRE_UNDERWATER)
#define PROFILE_EV_FIRE_WEAPON_MG42					(PROFILE_ENTITY_EVENT + EV_FIRE_WEAPON_MG42)
#define PROFILE_EV_FIRE_WEAPON_MOUNTEDMG42					(PROFILE_ENTITY_EVENT + EV_FIRE_WEAPON_MOUNTEDMG42)
#define PROFILE_EV_ITEM_RESPAWN					(PROFILE_ENTITY_EVENT + EV_ITEM_RESPAWN)
#define PROFILE_EV_ITEM_POP					(PROFILE_ENTITY_EVENT + EV_ITEM_POP)
#define PROFILE_EV_PLAYER_TELEPORT_IN					(PROFILE_ENTITY_EVENT + EV_PLAYER_TELEPORT_IN)
#define PROFILE_EV_PLAYER_TELEPORT_OUT					(PROFILE_ENTITY_EVENT + EV_PLAYER_TELEPORT_OUT)
#define PROFILE_EV_GRENADE_BOUNCE					(PROFILE_ENTITY_EVENT + EV_GRENADE_BOUNCE)
#define PROFILE_EV_GENERAL_SOUND					(PROFILE_ENTITY_EVENT + EV_GENERAL_SOUND)
#define PROFILE_EV_GENERAL_SOUND_VOLUME					(PROFILE_ENTITY_EVENT + EV_GENERAL_SOUND_VOLUME)
#define PROFILE_EV_GLOBAL_SOUND					(PROFILE_ENTITY_EVENT + EV_GLOBAL_SOUND)
#define PROFILE_EV_GLOBAL_CLIENT_SOUND					(PROFILE_ENTITY_EVENT + EV_GLOBAL_CLIENT_SOUND)
#define PROFILE_EV_GLOBAL_TEAM_SOUND					(PROFILE_ENTITY_EVENT + EV_GLOBAL_TEAM_SOUND)
#define PROFILE_EV_FX_SOUND					(PROFILE_ENTITY_EVENT + EV_FX_SOUND)
#define PROFILE_EV_BULLET_HIT_FLESH					(PROFILE_ENTITY_EVENT + EV_BULLET_HIT_FLESH)
#define PROFILE_EV_BULLET_HIT_WALL					(PROFILE_ENTITY_EVENT + EV_BULLET_HIT_WALL)
#define PROFILE_EV_MISSILE_HIT					(PROFILE_ENTITY_EVENT + EV_MISSILE_HIT)
#define PROFILE_EV_MISSILE_MISS					(PROFILE_ENTITY_EVENT + EV_MISSILE_MISS)
#define PROFILE_EV_RAILTRAIL					(PROFILE_ENTITY_EVENT + EV_RAILTRAIL)
#define PROFILE_EV_VENOM					(PROFILE_ENTITY_EVENT + EV_VENOM)
#define PROFILE_EV_BULLET					(PROFILE_ENTITY_EVENT + EV_BULLET)
#define PROFILE_EV_LOSE_HAT					(PROFILE_ENTITY_EVENT + EV_LOSE_HAT)
#define PROFILE_EV_PAIN					(PROFILE_ENTITY_EVENT + EV_PAIN)
#define PROFILE_EV_CROUCH_PAIN					(PROFILE_ENTITY_EVENT + EV_CROUCH_PAIN)
#define PROFILE_EV_DEATH1					(PROFILE_ENTITY_EVENT + EV_DEATH1)
#define PROFILE_EV_DEATH2					(PROFILE_ENTITY_EVENT + EV_DEATH2)
#define PROFILE_EV_DEATH3					(PROFILE_ENTITY_EVENT + EV_DEATH3)
#define PROFILE_EV_DEATH4					(PROFILE_ENTITY_EVENT + EV_DEATH4)
#define PROFILE_EV_OBITUARY					(PROFILE_ENTITY_EVENT + EV_OBITUARY)
#define PROFILE_EV_STOPSTREAMINGSOUND					(PROFILE_ENTITY_EVENT + EV_STOPSTREAMINGSOUND)
#define PROFILE_EV_POWERUP_QUAD					(PROFILE_ENTITY_EVENT + EV_POWERUP_QUAD)
#define PROFILE_EV_POWERUP_BATTLESUIT					(PROFILE_ENTITY_EVENT + EV_POWERUP_BATTLESUIT)
#define PROFILE_EV_POWERUP_REGEN					(PROFILE_ENTITY_EVENT + EV_POWERUP_REGEN)
#define PROFILE_EV_GIB_PLAYER					(PROFILE_ENTITY_EVENT + EV_GIB_PLAYER)
#define PROFILE_EV_DEBUG_LINE					(PROFILE_ENTITY_EVENT + EV_DEBUG_LINE)
#define PROFILE_EV_STOPLOOPINGSOUND					(PROFILE_ENTITY_EVENT + EV_STOPLOOPINGSOUND)
#define PROFILE_EV_TAUNT					(PROFILE_ENTITY_EVENT + EV_TAUNT)
#define PROFILE_EV_SMOKE					(PROFILE_ENTITY_EVENT + EV_SMOKE)
#define PROFILE_EV_SPARKS					(PROFILE_ENTITY_EVENT + EV_SPARKS)
#define PROFILE_EV_SPARKS_ELECTRIC					(PROFILE_ENTITY_EVENT + EV_SPARKS_ELECTRIC)
#define PROFILE_EV_EXPLODE					(PROFILE_ENTITY_EVENT + EV_EXPLODE)
#define PROFILE_EV_RUBBLE					(PROFILE_ENTITY_EVENT + EV_RUBBLE)
#define PROFILE_EV_EFFECT					(PROFILE_ENTITY_EVENT + EV_EFFECT)
#define PROFILE_EV_MORTAREFX					(PROFILE_ENTITY_EVENT + EV_MORTAREFX)
#define PROFILE_EV_SPINUP					(PROFILE_ENTITY_EVENT + EV_SPINUP)
#define PROFILE_EV_SNOW_ON					(PROFILE_ENTITY_EVENT + EV_SNOW_ON)
#define PROFILE_EV_SNOW_OFF					(PROFILE_ENTITY_EVENT + EV_SNOW_OFF)
#define PROFILE_EV_MISSILE_MISS_SMALL					(PROFILE_ENTITY_EVENT + EV_MISSILE_MISS_SMALL)
#define PROFILE_EV_MISSILE_MISS_LARGE					(PROFILE_ENTITY_EVENT + EV_MISSILE_MISS_LARGE)
#define PROFILE_EV_MORTAR_IMPACT					(PROFILE_ENTITY_EVENT + EV_MORTAR_IMPACT)
#define PROFILE_EV_MORTAR_MISS					(PROFILE_ENTITY_EVENT + EV_MORTAR_MISS)
#define PROFILE_EV_SPIT_HIT					(PROFILE_ENTITY_EVENT + EV_SPIT_HIT)
#define PROFILE_EV_SPIT_MISS					(PROFILE_ENTITY_EVENT + EV_SPIT_MISS)
#define PROFILE_EV_SHARD					(PROFILE_ENTITY_EVENT + EV_SHARD)
#define PROFILE_EV_JUNK					(PROFILE_ENTITY_EVENT + EV_JUNK)
#define PROFILE_EV_EMITTER					(PROFILE_ENTITY_EVENT + EV_EMITTER)
#define PROFILE_EV_OILPARTICLES					(PROFILE_ENTITY_EVENT + EV_OILPARTICLES)
#define PROFILE_EV_OILSLICK					(PROFILE_ENTITY_EVENT + EV_OILSLICK)
#define PROFILE_EV_OILSLICKREMOVE					(PROFILE_ENTITY_EVENT + EV_OILSLICKREMOVE)
#define PROFILE_EV_MG42EFX					(PROFILE_ENTITY_EVENT + EV_MG42EFX)
#define PROFILE_EV_SNOWFLURRY					(PROFILE_ENTITY_EVENT + EV_SNOWFLURRY)
#define PROFILE_EV_CONCUSSIVE					(PROFILE_ENTITY_EVENT + EV_CONCUSSIVE)
#define PROFILE_EV_DUST					(PROFILE_ENTITY_EVENT + EV_DUST)
#define PROFILE_EV_RUMBLE_EFX					(PROFILE_ENTITY_EVENT + EV_RUMBLE_EFX)
#define PROFILE_EV_GUNSPARKS					(PROFILE_ENTITY_EVENT + EV_GUNSPARKS)
#define PROFILE_EV_FLAMETHROWER_EFFECT					(PROFILE_ENTITY_EVENT + EV_FLAMETHROWER_EFFECT)
#define PROFILE_EV_MG42BULLET_HIT_FLESH					(PROFILE_ENTITY_EVENT + EV_MG42BULLET_HIT_FLESH)
#define PROFILE_EV_MG42BULLET_HIT_WALL					(PROFILE_ENTITY_EVENT + EV_MG42BULLET_HIT_WALL)
#define PROFILE_EV_SHAKE					(PROFILE_ENTITY_EVENT + EV_SHAKE)
#define PROFILE_EV_DISGUISE_SOUND					(PROFILE_ENTITY_EVENT + EV_DISGUISE_SOUND)
#define PROFILE_EV_BUILDDECAYED_SOUND					(PROFILE_ENTITY_EVENT + EV_BUILDDECAYED_SOUND)
#define PROFILE_EV_FIRE_WEAPON_AAGUN					(PROFILE_ENTITY_EVENT + EV_FIRE_WEAPON_AAGUN)
#define PROFILE_EV_DEBRIS					(PROFILE_ENTITY_EVENT + EV_DEBRIS)
#define PROFILE_EV_ALERT_SPEAKER					(PROFILE_ENTITY_EVENT + EV_ALERT_SPEAKER)
#define PROFILE_EV_POPUPMESSAGE					(PROFILE_ENTITY_EVENT + EV_POPUPMESSAGE)
#define PROFILE_EV_ARTYMESSAGE					(PROFILE_ENTITY_EVENT + EV_ARTYMESSAGE)
#define PROFILE_EV_AIRSTRIKEMESSAGE					(PROFILE_ENTITY_EVENT + EV_AIRSTRIKEMESSAGE)
#define PROFILE_EV_MEDIC_CALL					(PROFILE_ENTITY_EVENT + EV_MEDIC_CALL)
#define PROFILE_EV_FIREWORKS					(PROFILE_ENTITY_EVENT + EV_FIREWORKS)
#define PROFILE_EV_SHOTGUN_PUMP					(PROFILE_ENTITY_EVENT + EV_SHOTGUN_PUMP)
#define PROFILE_EV_SPAWN					(PROFILE_ENTITY_EVENT + EV_SPAWN)
#define PROFILE_EV_BODY_DP					(PROFILE_ENTITY_EVENT + EV_BODY_DP)
#define PROFILE_EV_BOUNCE_SOUND					(PROFILE_ENTITY_EVENT + EV_BOUNCE_SOUND)
#define PROFILE_EV_KICK					(PROFILE_ENTITY_EVENT + EV_KICK)
#define PROFILE_EV_WOLFKICK_MISS					(PROFILE_ENTITY_EVENT + EV_WOLFKICK_MISS)
#define PROFILE_EV_WOLFKICK_HIT_FLESH					(PROFILE_ENTITY_EVENT + EV_WOLFKICK_HIT_FLESH)
#define PROFILE_EV_WOLFKICK_HIT_WALL					(PROFILE_ENTITY_EVENT + EV_WOLFKICK_HIT_WALL)
#define PROFILE_EV_THROWKNIFE					(PROFILE_ENTITY_EVENT + EV_THROWKNIFE)
#define PROFILE_EV_SHOVE_SOUND					(PROFILE_ENTITY_EVENT + EV_SHOVE_SOUND)
#define PROFILE_EV_BOT_DEBUG_LINE					(PROFILE_ENTITY_EVENT + EV_BOT_DEBUG_LINE)
#define PROFILE_EV_BOT_DEBUG_RADIUS					(PROFILE_ENTITY_EVENT + EV_BOT_DEBUG_RADIUS)
#define PROFILE_EV_WEAPALT				(PROFILE_ENTITY_EVENT + EV_WEAPALT)

#endif  // NQ_BG_PROFILER_H
