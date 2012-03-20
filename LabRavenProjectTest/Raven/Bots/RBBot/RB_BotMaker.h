#ifndef RBBOTMAKER_H
#define RBBOTMAKER_H
#pragma warning (disable:4786)

//------------------------------------------------------------------------
//
//  Name:   RB_BotMaker.h
//
//  Desc:   Factory class for RB_BotMaker. 
//
//  Author: Robin Burke 2006 rburke@cs.depaul.edu
//
//------------------------------------------------------------------------

#include "../../BotMaker.h"
#include "../../AbstRaven_Bot.h"
#include "RB_Bot.h"
#include <string>
#include "../../Raven_Game.h"

class RB_BotMaker : public BotMaker {
private:
   RB_BotMaker();

   AbstRaven_Bot* makeBot(Raven_Game* world, Vector2D pos) const;
	
   // creation of static instance does automatic registration
    static const RB_BotMaker registerThis;
};
#endif