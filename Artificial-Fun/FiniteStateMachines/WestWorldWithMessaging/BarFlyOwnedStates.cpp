#include "BarFlyOwnedStates.h"
#include "fsm/State.h"
#include "BarFly.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//------------------------------------------------------------------------methods for EnterMineAndDigForNugget
Carousing* Carousing::Instance()
{
  static Carousing instance;

  return &instance;
}


void Carousing::Enter(BarFly* pBarFly)
{
	// send message ?
	cout << GetNameOfEntity(pBarFly->ID()) << " woke up from a long night of drinking and fighting";
}


void Carousing::Execute(BarFly* pBarFly)
{  
    if(!pBarFly->Drunk()) {
		pBarFly->IncrementIntoxication(1);
	} else {
		pBarFly->GetFSM()->ChangeState(FightinDrunk::Instance());
	}
}


void Carousing::Exit(BarFly* pBarFly)
{
	
}


bool Carousing::OnMessage(BarFly* pBarFly, const Telegram& msg)
{
  //send msg to global message handler
  return false;
}

//------------------------------------------------------------------------

FightinDrunk* FightinDrunk::Instance()
{
  static FightinDrunk instance;

  return &instance;
}


void FightinDrunk::Enter(BarFly* pBarFly)
{
	cout << GetNameOfEntity(pBarFly->ID()) << " is hammered and lookin for a fight...";
}


void FightinDrunk::Execute(BarFly* pBarFly)
{  
    
}


void FightinDrunk::Exit(BarFly* pBarFly)
{
	// Insult miner bob, change state to fighting
	// send msg
	cout << GetNameOfEntity(pBarFly->ID()) << " is going to kick some ass";

	/*//let the wife know I'm home
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pMiner->ID(),        //ID of sender
                              ent_Elsa,            //ID of recipient
                              Msg_HiHoneyImHome,   //the message
                              NO_ADDITIONAL_INFO);*/

	//pBarFly->GetFSM()->ChangeState(Fightin::Instance());
}


bool FightinDrunk::OnMessage(BarFly* pBarFly, const Telegram& msg)
{
  switch(msg.Msg)
  {
	case Msg_EnterBar:
		pBarFly->GetFSM()->ChangeState(Fightin::Instance());
  }

  return true;
}

//------------------------------------------------------------------------

Fightin* Fightin::Instance()
{
  static Fightin instance;

  return &instance;
}


void Fightin::Enter(BarFly* pBarFly)
{

	// Let the person who just entered the bar know we want to fight by insulting them
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                               pBarFly->ID(),
                               ent_Miner_Bob,
                               Msg_Insult,
                               NO_ADDITIONAL_INFO);
}


void Fightin::Execute(BarFly* pBarFly)
{  

}


void Fightin::Exit(BarFly* pBarFly)
{

}


bool Fightin::OnMessage(BarFly* pBarFly, const Telegram& msg)
{
  switch(msg.Msg)
  {
	case Msg_Punch:
		cout << "\n" << GetNameOfEntity(pBarFly->ID()) << " has just been punched in the face!";

		pBarFly->GetFSM()->ChangeState(OutCold::Instance());
  }
  return false;
}

//------------------------------------------------------------------------

OutCold* OutCold::Instance()
{
  static OutCold instance;

  return &instance;
}


void OutCold::Enter(BarFly* pBarFly)
{

	// Let the person who just entered the bar know we want to fight by insulting them
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                               pBarFly->ID(),
                               ent_Miner_Bob,
                               Msg_Insult,
                               NO_ADDITIONAL_INFO);
}


void OutCold::Execute(BarFly* pBarFly)
{  
	if(pBarFly->Intoxication() > 0) {
		pBarFly->DecrementIntoxication(1);
	} else {
		pBarFly->GetFSM()->ChangeState(Carousing::Instance());
	}
}


void OutCold::Exit(BarFly* pBarFly)
{
	cout << "\n" << GetNameOfEntity(pBarFly->ID()) << " is waking up from being passed out drunk";
}


bool OutCold::OnMessage(BarFly* pBarFly, const Telegram& msg)
{
  return false;
}

//------------------------------------------------------------------------
