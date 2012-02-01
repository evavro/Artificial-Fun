#ifndef BARFLY_H
#define BARFLY_H
/*
 * BarFly.h
 * a Barfly
 *
 * Thomas Sell && Erik Vavro
 */

#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "BarflyOwnedStates.h"
#include "fsm/StateMachine.h"

// maximun drunkiness
const int MaxDrunk = 5;

class BarFly : public BaseGameEntity
{
private:
  //an instance of the state machine class
	StateMachine<BarFly>* m_pStateMachine;
	int m_iIntoxication;

public:
	BarFly(int id): m_iIntoxication(0), BaseGameEntity(id)
	{
		//set up the state machine
		m_pStateMachine = new StateMachine<BarFly>(this);
		m_pStateMachine->SetCurrentState(Carousing::Instance());
	}

	~BarFly(){
		delete m_pStateMachine;
	}

	//this must be implemented
  void          Update();

	//so must this
  virtual bool  HandleMessage(const Telegram& msg);
  StateMachine<BarFly>* GetFSM()const{return m_pStateMachine;}
    //----------------------------------------------------accessors
  int	 MaxIntoxication()const{return MaxDrunk;}
  int    Intoxication()const{return m_iIntoxication;}
  void   SetIntoxication(int intoxLevel){m_iIntoxication=intoxLevel;}
  void   IncrementIntoxication(const int value);
  void   DecrementIntoxication(const int value);
  bool   Drunk() const;
  bool   Sober() const;
};

#endif
