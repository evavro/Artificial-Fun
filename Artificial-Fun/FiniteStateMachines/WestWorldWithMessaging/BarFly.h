#ifndef BARFLY_H
#define BARFLY_H

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
		m_pStateMachine = new StateMachine<BarFly>(this);3
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
  int    Intoxication()const{return m_iIntoxication;}
  void   SetIntoxication(int intoxLevel){m_iIntoxication=intoxLevel;}
  void   IncrementIntoxication(const int value);
  void   DecrementIntoxication(const int value);
  bool   Drunk() const;
  bool   Sober() const;
};

#endif
