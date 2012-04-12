#ifndef ETBOTMAKER_H
#define ETBOTMAKER_H
#pragma warning (disable:4786)

//------------------------------------------------------------------------
//
//  Name:   ET_BotMaker.h
//
//  Desc:   Factory class for ET_BotMaker. 
//
//  Author: Robin Burke 2006 rburke@cs.depaul.edu
//
//------------------------------------------------------------------------

#include "../../BotMaker.h"
#include "../../AbstRaven_Bot.h"
#include "ET_Bot.h"
#include <string>
#include "../../Raven_Game.h"

class ET_BotMaker : public BotMaker {
private:
   ET_BotMaker();

   AbstRaven_Bot* makeBot(Raven_Game* world, Vector2D pos) const;
	
   // creation of static instance does automatic registration
    static const ET_BotMaker registerThis;
};
#endif