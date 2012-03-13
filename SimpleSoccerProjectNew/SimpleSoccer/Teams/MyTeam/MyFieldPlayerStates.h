#ifndef MYFIELDPLAYERSTATES_H
#define MYFIELDPLAYERSTATES_H
//------------------------------------------------------------------------
//
//  Name: FieldPlayerStates.h
//
//  Desc: States for the field players of Simple Soccer. See my book
//        for detailed descriptions
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "FSM/State.h"
#include "Messaging/Telegram.h"
#include "../../constants.h"


class FieldPlayer;
class SoccerPitch;


//------------------------------------------------------------------------
class MyGlobalPlayerState : public State<FieldPlayer>
{
private:
  
  MyGlobalPlayerState(){}

public:

  //this is a singleton
  static MyGlobalPlayerState* Instance();

  void Enter(FieldPlayer* player){}

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player){}

  bool OnMessage(FieldPlayer*, const Telegram&);
};

//------------------------------------------------------------------------
class MyChaseBall : public State<FieldPlayer>
{
private:
  
 MyChaseBall(){}

public:

  //this is a singleton
  static MyChaseBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyDribble : public State<FieldPlayer>
{
private:
  
  MyDribble(){}

public:

  //this is a singleton
  static MyDribble* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player){}

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};


//------------------------------------------------------------------------
class MyReturnToHomeRegion: public State<FieldPlayer>
{
private:
  
  MyReturnToHomeRegion(){}

public:

  //this is a singleton
  static MyReturnToHomeRegion* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyWait: public State<FieldPlayer>
{
private:
  
  MyWait(){}

public:

  //this is a singleton
  static MyWait* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyKickBall: public State<FieldPlayer>
{
private:
  
  MyKickBall(){}

public:

  //this is a singleton
  static MyKickBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player){}

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class MyReceiveBall: public State<FieldPlayer>
{
private:
  
  MyReceiveBall(){}

public:

  //this is a singleton
  static MyReceiveBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};


//------------------------------------------------------------------------
class MySupportAttacker: public State<FieldPlayer>
{
private:
  
  MySupportAttacker(){}

public:

  //this is a singleton
  static MySupportAttacker* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};
#endif