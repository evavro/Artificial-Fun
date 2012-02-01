
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

// insert states FightinDrunk, Fightin, and OutCold here.
