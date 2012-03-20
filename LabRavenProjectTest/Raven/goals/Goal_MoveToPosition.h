#ifndef GOAL_MOVE_POS_H
#define GOAL_MOVE_POS_H
#pragma warning (disable:4786)

#include "misc/Stream_Utility_Functions.h"
#include "Goals/Goal_Composite.h"
#include "2D/Vector2D.h"
#include "../AbstRaven_Bot.h"
#include "Raven_Goal_Types.h"



class Goal_MoveToPosition : public Goal_Composite<AbstRaven_Bot>
{
protected:

  //the position the bot wants to reach
  Vector2D m_vDestination;

public:

  Goal_MoveToPosition(AbstRaven_Bot* pBot,
                      Vector2D   pos):
  
            Goal_Composite<AbstRaven_Bot>(pBot,
                                      goal_move_to_position),
            m_vDestination(pos)
  {}

 //the usual suspects
  void Activate();
  int  Process();
  void Terminate(){}

  //this goal is able to accept messages
  bool HandleMessage(const Telegram& msg);

  void Render();
};





#endif
