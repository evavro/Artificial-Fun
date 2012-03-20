#ifndef RB_BOT_H
#define RB_BOT_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   RB_Bot.h
//
//  Author: Robin Burke
//
//  Desc:
//-----------------------------------------------------------------------------
#include <vector>
#include <iosfwd>
#include <map>

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "RB_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "RB_BotScriptor.h"


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




class RB_Bot : public AbstRaven_Bot
{
protected:
	//bots shouldn't be copied, only created or respawned
  RB_Bot(const RB_Bot&);
  RB_Bot& operator=(const RB_Bot&);
  RB_BotScriptor* m_pScript;

public:
  
  RB_Bot(Raven_Game* world, Vector2D pos);
  virtual ~RB_Bot();

  //the usual suspects
  std::string  const GetName() const;
  void         DoUpdate();
  bool         HandleMessage(const Telegram& msg);

  void			SelectBodyPen();
  void			SelectHeadPen();

  bool canDodgeRight(Vector2D& PositionToDodge, Vector2D destination)const;
  bool canDodgeLeft(Vector2D& PositionToDodge, Vector2D destination)const;
};

#endif