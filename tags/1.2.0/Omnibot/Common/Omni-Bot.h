////////////////////////////////////////////////////////////////////////////////
// 
// $LastChangedBy$
// $LastChangedDate$
// $LastChangedRevision$
//
// about: Exported function definitions
//		In order for the game to call functions from the bot, we must export
//		the functions to the game itself and allow it to call them. 
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __OMNIBOT_H__
#define __OMNIBOT_H__

#include "Functions_Bot.h"
#include "Functions_Engine.h"
#include "Omni-Bot_Types.h"
#include "Omni-Bot_Events.h"
#include "MessageHelper.h"

// function: Bot_Initialise
//		Initializes the bot library and sets the bot up with the callbacks to 
//		the game in the form of function pointers to functions within the game.
omnibot_error BotInitialise(const Game_EngineFuncs_t *_pEngineFuncs, int _version);
// function: Bot_Shutdown
//		Shuts down and frees memory from the bot system
void BotShutdown();
// function: Bot_Update
//		Called regularly by the game in order for the bots to perform their "thinking"
void BotUpdate();
// function: Bot_ConsoleCommand
//		Any time commands from the game are executed, this will get called
//		to allow the bot to process it and perform any necessary actions.
int BotConsoleCommand(const char *_cmd, int _size);
// function: Bot_AddGoal
//		Allows the game to register a goal with the bot that the bots can use
void BotAddGoal(const GameEntity _ent, int _goaltype, int _team, const char *_tag, obUserData *_bud);
// function: Bot_AddBBRecord
//		Allows the game to enter blackboard records into the bots knowledge database.
void BotAddBBRecord(BlackBoard_Key _type, int _posterID, int _targetID, obUserData *_data);
// function: Bot_AddTargetEntity
//		This adds the provided entity to the bots threat list. 
//		This could be other bots/clients/projectiles
void BotAddThreatEntity(GameEntity _ent, EntityInfo *_info);
// function: Bot_SendTrigger
//		Allows the game to notify the bot of triggered events.
void BotSendTrigger(TriggerInfo *_triggerInfo);
// function: BotSendEvent
//		New Messagehelper based event handler.
void BotSendEvent(int _dest, const MessageHelper &_message);
// function: BotSendGlobalEvent
//		New Messagehelper based event handler.
void BotSendGlobalEvent(const MessageHelper &_message);

//SubscriberHandle Message_SubscribeToMsg(int _msg, pfnMessageFunction _func);
//void Message_Unsubscribe(const SubscriberHandle _handle);
//MessageHelper Message_BeginMessage(int _msgId, size_t _messageSize);
//MessageHelper Message_BeginMessageEx(int _msgId, void *_mem, size_t _messageSize);
//void Message_EndMessage(const MessageHelper &_helper);
//void Message_EndMessageEx(const MessageHelper &_helper);

#endif

