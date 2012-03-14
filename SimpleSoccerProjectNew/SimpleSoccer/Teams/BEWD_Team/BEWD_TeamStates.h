#ifndef BEWD_TEAMSTATES_H
#define BEWD_TEAMSTATES_H

//------------------------------------------------------------------------
//
//  Name: TeamStates.h
//
//  Desc: State prototypes for soccer team states
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>

#include "FSM/State.h"
#include "Messaging/Telegram.h"
#include "../../constants.h"


class AbstSoccerTeam;


//------------------------------------------------------------------------
class BEWD_Attacking : public State<AbstSoccerTeam>
{ 
private:
  
  BEWD_Attacking(){}

public:

  //this is a singleton
  static BEWD_Attacking* Instance();

  void Enter(AbstSoccerTeam* team);

  void Execute(AbstSoccerTeam* team);

  void Exit(AbstSoccerTeam* team);

  bool OnMessage(AbstSoccerTeam*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_Defending : public State<AbstSoccerTeam>
{ 
private:
  
  BEWD_Defending(){}

public:

    //this is a singleton
  static BEWD_Defending* Instance();

  void Enter(AbstSoccerTeam* team);

  void Execute(AbstSoccerTeam* team);

  void Exit(AbstSoccerTeam* team);

  bool OnMessage(AbstSoccerTeam*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class BEWD_PrepareForKickOff : public State<AbstSoccerTeam>
{ 
private:
  
  BEWD_PrepareForKickOff(){}

public:

    //this is a singleton
  static BEWD_PrepareForKickOff* Instance();
  
  void Enter(AbstSoccerTeam* team);

  void Execute(AbstSoccerTeam* team);

  void Exit(AbstSoccerTeam* team);

  bool OnMessage(AbstSoccerTeam*, const Telegram&){return false;}
};


#endif