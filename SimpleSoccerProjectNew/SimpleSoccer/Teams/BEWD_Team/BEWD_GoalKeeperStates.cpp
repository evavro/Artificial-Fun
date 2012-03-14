#include "BEWD_GoalKeeperStates.h"
#include "Debug/DebugConsole.h"
#include "../../SoccerPitch.h"
#include "../../PlayerBase.h"
#include "../../GoalKeeper.h"
#include "../../SteeringBehaviors.h"
#include "BEWD_SoccerTeam.h"
#include "../../Goal.h"
#include "2D/geometry.h"
#include "../../FieldPlayer.h"
#include "../../ParamLoader.h"
#include "Messaging/Telegram.h"
#include "Messaging/MessageDispatcher.h"
#include "../../SoccerMessages.h"


//uncomment to send state info to debug window
//#define GOALY_STATE_INFO_ON


//--------------------------- GlobalKeeperState -------------------------------
//-----------------------------------------------------------------------------

BEWD_GlobalKeeperState* BEWD_GlobalKeeperState::Instance()
{
  static BEWD_GlobalKeeperState instance;

  return &instance;
}


bool BEWD_GlobalKeeperState::OnMessage(GoalKeeper* keeper, const Telegram& telegram)
{
  switch(telegram.Msg)
  {
    case Msg_GoHome:
    {
      keeper->SetDefaultHomeRegion();
      
      keeper->GetFSM()->ChangeState(BEWD_ReturnHome::Instance());
    }

    break;

    case Msg_ReceiveBall:
      {
        keeper->GetFSM()->ChangeState(BEWD_InterceptBall::Instance());
      }

      break;

  }//end switch

  return false;
}


//--------------------------- TendGoal -----------------------------------
//
//  This is the main state for the goalkeeper. When in this state he will
//  move left to right across the goalmouth using the 'interpose' steering
//  behavior to put himself between the ball and the back of the net.
//
//  If the ball comes within the 'goalkeeper range' he moves out of the
//  goalmouth to attempt to intercept it. (see next state)
//------------------------------------------------------------------------

BEWD_TendGoal* BEWD_TendGoal::Instance()
{
  static BEWD_TendGoal instance;

  return &instance;
}


void BEWD_TendGoal::Enter(GoalKeeper* keeper)
{
  //turn interpose on
  keeper->Steering()->InterposeOn(Prm.GoalKeeperTendingDistance);

  //interpose will position the agent between the ball position and a target
  //position situated along the goal mouth. This call sets the target
  keeper->Steering()->SetTarget(keeper->GetRearInterposeTarget());
}

void BEWD_TendGoal::Execute(GoalKeeper* keeper)
{
  //the rear interpose target will change as the ball's position changes
  //so it must be updated each update-step 
  keeper->Steering()->SetTarget(keeper->GetRearInterposeTarget());

  //if the ball comes in range the keeper traps it and then changes state
  //to put the ball back in play
  if (keeper->BallWithinKeeperRange())
  {
    keeper->Ball()->Trap();

    keeper->Pitch()->SetGoalKeeperHasBall(true);

    keeper->GetFSM()->ChangeState(BEWD_PutBallBackInPlay::Instance());

    return;
  }

  //if ball is within a predefined distance, the keeper moves out from
  //position to try and intercept it.
  if (keeper->BallWithinRangeForIntercept() && !keeper->Team()->InControl())
  {
    keeper->GetFSM()->ChangeState(BEWD_InterceptBall::Instance());
  }

  //if the keeper has ventured too far away from the goal-line and there
  //is no threat from the opponents he should move back towards it
  if (keeper->TooFarFromGoalMouth() && keeper->Team()->InControl())
  {
    keeper->GetFSM()->ChangeState(BEWD_ReturnHome::Instance());

    return;
  }
}


void BEWD_TendGoal::Exit(GoalKeeper* keeper)
{
  keeper->Steering()->InterposeOff();
}


//------------------------- ReturnHome: ----------------------------------
//
//  In this state the goalkeeper simply returns back to the center of
//  the goal region before changing state back to TendGoal
//------------------------------------------------------------------------

BEWD_ReturnHome* BEWD_ReturnHome::Instance()
{
  static BEWD_ReturnHome instance;

  return &instance;
}


void BEWD_ReturnHome::Enter(GoalKeeper* keeper)
{
  keeper->Steering()->ArriveOn();
}

void BEWD_ReturnHome::Execute(GoalKeeper* keeper)
{
  keeper->Steering()->SetTarget(keeper->HomeRegion()->Center());

  //if close enough to home or the opponents get control over the ball,
  //change state to tend goal
  if (keeper->InHomeRegion() || !keeper->Team()->InControl())
  {
    keeper->GetFSM()->ChangeState(BEWD_TendGoal::Instance());
  }
}

void BEWD_ReturnHome::Exit(GoalKeeper* keeper)
{
  keeper->Steering()->ArriveOff();
}



//----------------- InterceptBall ----------------------------------------
//
//  In this state the GP will attempt to intercept the ball using the
//  pursuit steering behavior, but he only does so so long as he remains
//  within his home region.
//------------------------------------------------------------------------

BEWD_InterceptBall* BEWD_InterceptBall::Instance()
{
  static BEWD_InterceptBall instance;

  return &instance;
}


void BEWD_InterceptBall::Enter(GoalKeeper* keeper)
{
  keeper->Steering()->PursuitOn();  

    #ifdef GOALY_STATE_INFO_ON
    //debug_con << "Goaly " << keeper->ID() << " enters InterceptBall" <<  "";
    #endif
}

void BEWD_InterceptBall::Execute(GoalKeeper* keeper)
{ 
  //if the goalkeeper moves to far away from the goal he should return to his
  //home region UNLESS he is the closest player to the ball, in which case,
  //he should keep trying to intercept it.
  if (keeper->TooFarFromGoalMouth() && !keeper->isClosestPlayerOnPitchToBall())
  {
    keeper->GetFSM()->ChangeState(BEWD_ReturnHome::Instance());

    return;
  }
  
  //if the ball becomes in range of the goalkeeper's hands he traps the 
  //ball and puts it back in play
  if (keeper->BallWithinKeeperRange())
  {
    keeper->Ball()->Trap();
    
    keeper->Pitch()->SetGoalKeeperHasBall(true);

    keeper->GetFSM()->ChangeState(BEWD_PutBallBackInPlay::Instance());

    return;
  }
}

void BEWD_InterceptBall::Exit(GoalKeeper* keeper)
{
  keeper->Steering()->PursuitOff();
}



//--------------------------- PutBallBackInPlay --------------------------
//
//------------------------------------------------------------------------

BEWD_PutBallBackInPlay* BEWD_PutBallBackInPlay::Instance()
{
  static BEWD_PutBallBackInPlay instance;

  return &instance;
}

void BEWD_PutBallBackInPlay::Enter(GoalKeeper* keeper)
{
  //let the team know that the keeper is in control
  keeper->Team()->SetControllingPlayer(keeper);

  //send all the players home
  keeper->Team()->Opponents()->ReturnAllFieldPlayersToHome();
  keeper->Team()->ReturnAllFieldPlayersToHome();
}


void BEWD_PutBallBackInPlay::Execute(GoalKeeper* keeper)
{
  PlayerBase*  receiver = NULL;
  Vector2D     BallTarget;
    
  //test if there are players further forward on the field we might
  //be able to pass to. If so, make a pass.
  if (keeper->Team()->FindPass(keeper,
                              receiver,
                              BallTarget,
                              Prm.MaxPassingForce,
                              Prm.GoalkeeperMinPassDist))
  {     
    //make the pass   
    keeper->Ball()->Kick(Vec2DNormalize(BallTarget - keeper->Ball()->Pos()),
                         Prm.MaxPassingForce);

    //goalkeeper no longer has ball 
    keeper->Pitch()->SetGoalKeeperHasBall(false);

    //let the receiving player know the ball's comin' at him
    Dispatcher->DispatchMsg(SEND_MSG_IMMEDIATELY,
                          keeper->ID(),
                          receiver->ID(),
                          Msg_ReceiveBall,
                          &BallTarget);
    
    //go back to tending the goal   
    keeper->GetFSM()->ChangeState(BEWD_TendGoal::Instance());

    return;
  }  

  keeper->SetVelocity(Vector2D());
}