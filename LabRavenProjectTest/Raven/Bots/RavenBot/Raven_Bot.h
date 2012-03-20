#ifndef RAVEN_BOT_H
#define RAVEN_BOT_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Raven_Bot.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:
//-----------------------------------------------------------------------------
#include <vector>
#include <iosfwd>
#include <map>

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "Raven_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "Raven_BotScriptor.h"


class Raven_PathPlanner;
class Raven_Steering;
class Raven_Game;
class Regulator;
class Raven_Weapon;
struct Telegram;
class Raven_Bot;
class Goal_Think;
class Raven_WeaponSystem;
class Raven_SensoryMemory;




class Raven_Bot : public AbstRaven_Bot
{

protected:
	//bots shouldn't be copied, only created or respawned
  Raven_Bot(const Raven_Bot&);
  Raven_Bot& operator=(const Raven_Bot&);

  Raven_BotScriptor* m_pScript;

public:
  
	Raven_Bot(Raven_Game* world, Vector2D pos);
  virtual ~Raven_Bot();

  //the usual suspects
  std::string  const GetName() const;
  void         DoUpdate();
  bool         HandleMessage(const Telegram& msg);
  virtual void			SelectBodyPen();
  virtual void			SelectHeadPen();
};




#endif