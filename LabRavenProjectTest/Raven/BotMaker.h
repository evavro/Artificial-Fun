#ifndef BOTMAKER_H
#define BOTMAKER_H
#pragma warning (disable:4786)

//------------------------------------------------------------------------
//
//  Name:   BotMaker.h
//
//  Desc:   Abstract class for factory classes. Allows dynamic registry of
//          new bots. Probably overkill, but it is the "right way" to do it.
//
//  Author: Robin Burke 2006 rburke@cs.depaul.edu
//
//------------------------------------------------------------------------

#include "AbstRaven_Bot.h"
#include <string>
#include <map>

using namespace std;

class BotMaker;

typedef map<string, BotMaker*> MakerMap;

class BotMaker {
public:
	static AbstRaven_Bot* newBot(string className, Raven_Game* world, Vector2D pos);

	static MakerMap* registry;
protected:
	BotMaker (string className);

	virtual AbstRaven_Bot* makeBot(Raven_Game* world, Vector2D pos) const=0;
};

#endif