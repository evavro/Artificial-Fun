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
	cout << "\n" << GetNameOfEntity(pBarFly->ID()) << " woke up from a long night of drinking and fighting";
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
	switch(msg.Msg)
  {
	case Msg_EnterBar:
		SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout << "\n" << "Message handled by " << GetNameOfEntity(pBarFly->ID()) 
     << " at time: " << Clock->GetCurrentTime();

		return true;
  }
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
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pBarFly->ID()) << " is hammered and lookin for a fight...";
}


void FightinDrunk::Execute(BarFly* pBarFly)
{  
    
}


void FightinDrunk::Exit(BarFly* pBarFly)
{
	// Insult miner bob, change state to fighting
	// send msg
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout << "/" << GetNameOfEntity(pBarFly->ID()) << " is going to kick some ass";

}


bool FightinDrunk::OnMessage(BarFly* pBarFly, const Telegram& msg)
{
  switch(msg.Msg)
  {
	case Msg_EnterBar:
		SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout << "\nMessage handled by " << GetNameOfEntity(pBarFly->ID()) 
     << " at time: " << Clock->GetCurrentTime();

		pBarFly->GetFSM()->ChangeState(Fightin::Instance());

		return true;
  }
  return false;
}

//------------------------------------------------------------------------

Fightin* Fightin::Instance()
{
  static Fightin instance;

  return &instance;
}


void Fightin::Enter(BarFly* pBarFly)
{
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pBarFly->ID()) << ": " << "I'm gonna kick your ass";

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
		SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout << "\nMessage handled by " << GetNameOfEntity(pBarFly->ID()) 
     << " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pBarFly->ID()) << " has just been punched in the face!";

		pBarFly->GetFSM()->ChangeState(OutCold::Instance());
		return true;
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
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pBarFly->ID()) << ": " << "Knocked out cold and sleeping like a baby";

	// Tell miner bob that we just got knocked out
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
	SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pBarFly->ID()) << ": " << "Waking up from being passed out drunk";
}


bool OutCold::OnMessage(BarFly* pBarFly, const Telegram& msg)
{
  return false;
}

//------------------------------------------------------------------------
