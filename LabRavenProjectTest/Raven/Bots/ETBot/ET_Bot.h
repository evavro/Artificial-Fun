#ifndef ET_BOT_H
#define ET_BOT_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   ET_Bot.h
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
#include "ET_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "ET_BotScriptor.h"


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




class ET_Bot : public AbstRaven_Bot
{
protected:
	//bots shouldn't be copied, only created or respawned
  ET_Bot(const ET_Bot&);
  ET_Bot& operator=(const ET_Bot&);
  ET_BotScriptor* m_pScript;

public:
  
  ET_Bot(Raven_Game* world, Vector2D pos);
  virtual ~ET_Bot();

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