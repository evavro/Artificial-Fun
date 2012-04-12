#ifndef ET_BOTSTEERINGBEHAVIORS_H
#define ET_BOTSTEERINGBEHAVIORS_H
#pragma warning (disable:4786)
//------------------------------------------------------------------------
//
//  Name:   ET_BotSteeringBehavior.h
//
//  Desc:   class to encapsulate steering behaviors for a Raven_Bot
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <vector>
#include <windows.h>
#include <string>
#include <list>
#include "2d/Vector2D.h"
#include "../../constants.h"
#include "../../AbstSteeringBehaviors.h"

class AbstRaven_Bot;
class Wall2D;
class BaseGameEntity;
class Raven_Game;

//------------------------------------------------------------------------

class ET_BotSteering : public AbstSteering
{
  
public:

  ET_BotSteering(Raven_Game* world, AbstRaven_Bot* agent);

  virtual ~ET_BotSteering();

};




#endif