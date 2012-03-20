#ifndef RBGOAL_THINK_H
#define RBGOAL_THINK_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   RBGoal_Think .h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class to arbitrate between a collection of high level goals, and
//          to process those goals.
//-----------------------------------------------------------------------------
#include <vector>
#include <string>
#include "2d/Vector2D.h"
#include "../../Goals/Goal_Think.h"
#include "../../AbstRaven_Bot.h"
#include "../../Goals/Goal_Evaluator.h"



class RBGoal_Think : public Goal_Think
{


public:

  RBGoal_Think(AbstRaven_Bot* pBot);
  ~RBGoal_Think();

};


#endif