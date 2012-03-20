#ifndef GOAL_THINK_H
#define GOAL_THINK_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Goal_Think .h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class to arbitrate between a collection of high level goals, and
//          to process those goals.
//-----------------------------------------------------------------------------
#include <vector>
#include <string>
#include "2d/Vector2D.h"
#include "Goals/Goal_Composite.h"
#include "../AbstRaven_Bot.h"
#include "Goal_Evaluator.h"



class Goal_Think : public Goal_Composite<AbstRaven_Bot>
{
protected:
  
  typedef std::vector<Goal_Evaluator*>   GoalEvaluators;
  
  GoalEvaluators  m_Evaluators;

public:

  Goal_Think(AbstRaven_Bot* pBot);
  ~Goal_Think();

  //this method iterates through each goal evaluator and selects the one
  //that has the highest score as the current goal
  virtual void Arbitrate();

  //returns true if the given goal is not at the front of the subgoal list
  bool notPresent(unsigned int GoalType)const;

  //the usual suspects
  virtual int  Process();
  virtual void Activate();
  virtual void Terminate(){}
  
  //top level goal types
  virtual void AddGoal_MoveToPosition(Vector2D pos);
  virtual void AddGoal_GetItem(unsigned int ItemType);
  virtual void AddGoal_Explore();
  virtual void AddGoal_AttackTarget();

  //this adds the MoveToPosition goal to the *back* of the subgoal list.
  virtual void QueueGoal_MoveToPosition(Vector2D pos);

  //this renders the evaluations (goal scores) at the specified location
  void  RenderEvaluations(int left, int top)const;
  void  Render();


};


#endif