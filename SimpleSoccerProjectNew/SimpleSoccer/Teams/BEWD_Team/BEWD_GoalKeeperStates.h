#ifndef BEWD_KEEPERSTATES_H
#define BEWD_KEEPERSTATES_H
//------------------------------------------------------------------------
//
//  Name: GoalKeeperStates.h
//
//  Desc:   Declarations of all the states used by a Simple Soccer
//          goalkeeper
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include "FSM/State.h"
#include "Messaging/Telegram.h"
#include "../../constants.h"


class GoalKeeper;
class SoccerPitch;


class BEWD_GlobalKeeperState: public State<GoalKeeper>
{
private:
  
  BEWD_GlobalKeeperState(){}

public:

  //this is a singleton
  static BEWD_GlobalKeeperState* Instance();

  void Enter(GoalKeeper* keeper){}

  void Execute(GoalKeeper* keeper){}

  void Exit(GoalKeeper* keeper){}

  bool OnMessage(GoalKeeper*, const Telegram&);
};

//-----------------------------------------------------------------------------

class BEWD_TendGoal: public State<GoalKeeper>
{
private:
  
  BEWD_TendGoal(){}

public:

  //this is a singleton
  static BEWD_TendGoal* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper);

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_InterceptBall: public State<GoalKeeper>
{
private:
  
  BEWD_InterceptBall(){}

public:

  //this is a singleton
  static BEWD_InterceptBall* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper);

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_ReturnHome: public State<GoalKeeper>
{
private:
  
  BEWD_ReturnHome(){}

public:

  //this is a singleton
  static BEWD_ReturnHome* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper);

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_PutBallBackInPlay: public State<GoalKeeper>
{
private:
  
  BEWD_PutBallBackInPlay(){}

public:

  //this is a singleton
  static BEWD_PutBallBackInPlay* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper){}

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};
#endif