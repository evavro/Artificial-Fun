#ifndef MYKEEPERSTATES_H
#define MYKEEPERSTATES_H
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


class MyGlobalKeeperState: public State<GoalKeeper>
{
private:
  
  MyGlobalKeeperState(){}

public:

  //this is a singleton
  static MyGlobalKeeperState* Instance();

  void Enter(GoalKeeper* keeper){}

  void Execute(GoalKeeper* keeper){}

  void Exit(GoalKeeper* keeper){}

  bool OnMessage(GoalKeeper*, const Telegram&);
};

//-----------------------------------------------------------------------------

class MyTendGoal: public State<GoalKeeper>
{
private:
  
  MyTendGoal(){}

public:

  //this is a singleton
  static MyTendGoal* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper);

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyInterceptBall: public State<GoalKeeper>
{
private:
  
  MyInterceptBall(){}

public:

  //this is a singleton
  static MyInterceptBall* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper);

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyReturnHome: public State<GoalKeeper>
{
private:
  
  MyReturnHome(){}

public:

  //this is a singleton
  static MyReturnHome* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper);

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyPutBallBackInPlay: public State<GoalKeeper>
{
private:
  
  MyPutBallBackInPlay(){}

public:

  //this is a singleton
  static MyPutBallBackInPlay* Instance();

  void Enter(GoalKeeper* keeper);

  void Execute(GoalKeeper* keeper);

  void Exit(GoalKeeper* keeper){}

  bool OnMessage(GoalKeeper*, const Telegram&){return false;}
};
#endif