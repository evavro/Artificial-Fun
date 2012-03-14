#ifndef BEWD_FIELDPLAYERSTATES_H
#define BEWD_FIELDPLAYERSTATES_H
//------------------------------------------------------------------------
//
//  Name: FieldPlayerStates.h
//
//  Desc: States for the field players of Simple Soccer. See BEWD_ book
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
class BEWD_GlobalPlayerState : public State<FieldPlayer>
{
private:
  
  BEWD_GlobalPlayerState(){}

public:

  //this is a singleton
  static BEWD_GlobalPlayerState* Instance();

  void Enter(FieldPlayer* player){}

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player){}

  bool OnMessage(FieldPlayer*, const Telegram&);
};

//------------------------------------------------------------------------
class BEWD_ChaseBall : public State<FieldPlayer>
{
private:
  
 BEWD_ChaseBall(){}

public:

  //this is a singleton
  static BEWD_ChaseBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_Dribble : public State<FieldPlayer>
{
private:
  
  BEWD_Dribble(){}

public:

  //this is a singleton
  static BEWD_Dribble* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player){}

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};


//------------------------------------------------------------------------
class BEWD_ReturnToHomeRegion: public State<FieldPlayer>
{
private:
  
  BEWD_ReturnToHomeRegion(){}

public:

  //this is a singleton
  static BEWD_ReturnToHomeRegion* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_Wait: public State<FieldPlayer>
{
private:
  
  BEWD_Wait(){}

public:

  //this is a singleton
  static BEWD_Wait* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_KickBall: public State<FieldPlayer>
{
private:
  
  BEWD_KickBall(){}

public:

  //this is a singleton
  static BEWD_KickBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player){}

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_ReceiveBall: public State<FieldPlayer>
{
private:
  
  BEWD_ReceiveBall(){}

public:

  //this is a singleton
  static BEWD_ReceiveBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};


//------------------------------------------------------------------------
class BEWD_SupportAttacker: public State<FieldPlayer>
{
private:
  
  BEWD_SupportAttacker(){}

public:

  //this is a singleton
  static BEWD_SupportAttacker* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_FakeOutDribble: public State<FieldPlayer>
{
private:
  
  BEWD_FakeOutDribble(){}

public:

  //this is a singleton
  static BEWD_FakeOutDribble* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};



//------------------------------------------------------------------------
class BEWD_FieldInterceptBall: public State<FieldPlayer>
{
private:

	BEWD_FieldInterceptBall(){}

public:

  //this is a singleton
  static BEWD_FieldInterceptBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};



//------------------------------------------------------------------------
class BEWD_MoveToRegion: public State<FieldPlayer>
{
private:

	BEWD_MoveToRegion() {}
	BEWD_MoveToRegion(int region){}

public:

  //this is a singleton
  static BEWD_MoveToRegion* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};
#endif