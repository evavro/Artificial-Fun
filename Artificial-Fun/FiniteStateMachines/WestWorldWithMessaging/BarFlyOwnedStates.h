#ifndef BARFLY_OWNED_STATES_H
#define BARFLY_OWNED_STATES_H

#include "FSM/State.h"


class BarFly;
//------------------------------------------------------------------------
// Carousing: In the Carousing state, Henry will raise his intoxication
//  level by one at each update. When it reaches the drunkeness threshold
//  of 10, he will change his state to FightinDrunk.
//------------------------------------------------------------------------
class Carousing : public State<BarFly>
{
private:
	Carousing(){}
	//copy ctor and assignment should be private
	Carousing(const Carousing&);
	Carousing& operator=(const Carousing&);

public:
	//this is a singleton
  	static Carousing* Instance();

	virtual void Enter(BarFly* barfly);
	virtual void Execute(BarFly* barfly);
	virtual void Exit(BarFly* barfly);

	virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};

class FightinDrunk : public State<BarFly>
{
private:
	FightinDrunk(){}
	//copy ctor and assignment should be private
	FightinDrunk(const FightinDrunk&);
	FightinDrunk& operator=(const FightinDrunk&);

public:
	//this is a singleton
  	static FightinDrunk* Instance();

	virtual void Enter(BarFly* barfly);
	virtual void Execute(BarFly* barfly);
	virtual void Exit(BarFly* barfly);

	virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};

class Fightin : public State<BarFly>
{
private:
	Fightin(){}
	//copy ctor and assignment should be private
	Fightin(const Fightin&);
	Fightin& operator=(const Fightin&);

public:
	//this is a singleton
  	static Fightin* Instance();

	virtual void Enter(BarFly* barfly);
	virtual void Execute(BarFly* barfly);
	virtual void Exit(BarFly* barfly);

	virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};

class OutCold : public State<BarFly>
{
private:
	OutCold(){}
	//copy ctor and assignment should be private
	OutCold(const OutCold&);
	OutCold& operator=(const OutCold&);

public:
	//this is a singleton
  	static OutCold* Instance();

	virtual void Enter(BarFly* barfly);
	virtual void Execute(BarFly* barfly);
	virtual void Exit(BarFly* barfly);

	virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};


// insert states FightinDrunk, Fightin, and OutCold here.

#endif