#ifndef RB_BOTSTEERINGBEHAVIORS_H
#define RB_BOTSTEERINGBEHAVIORS_H
#pragma warning (disable:4786)
//------------------------------------------------------------------------
//
//  Name:   RB_BotSteeringBehavior.h
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

class RB_BotSteering : public AbstSteering
{
  
public:

  RB_BotSteering(Raven_Game* world, AbstRaven_Bot* agent);

  virtual ~RB_BotSteering();

};




#endif