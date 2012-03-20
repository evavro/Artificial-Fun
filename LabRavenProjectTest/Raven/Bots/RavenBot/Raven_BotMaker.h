#ifndef RAVENBOTMAKER_H
#define RAVENBOTMAKER_H
#pragma warning (disable:4786)

//------------------------------------------------------------------------
//
//  Name:   Raven_BotMaker.h
//
//  Desc:   Factory class for Raven_BotMaker. 
//
//  Author: Robin Burke 2006 rburke@cs.depaul.edu
//
//------------------------------------------------------------------------

#include "../../BotMaker.h"
#include "../../AbstRaven_Bot.h"
#include "Raven_Bot.h"
#include <string>
#include "../../Raven_Game.h"

class Raven_BotMaker : public BotMaker {
private:
   Raven_BotMaker();

   AbstRaven_Bot* makeBot(Raven_Game* world, Vector2D pos) const;
	
   // creation of static instance does automatic registration
    static const Raven_BotMaker registerThis;
};
#endif