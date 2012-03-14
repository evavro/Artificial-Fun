#include "BEWD_SoccerTeam.h"
#include "../../SoccerPitch.h"
#include "../../Goal.h"
#include "../../PlayerBase.h"
#include "../../GoalKeeper.h"
#include "../../FieldPlayer.h"
#include "misc/utils.h"
#include "../../SteeringBehaviors.h"
#include "BEWD_FieldPlayerStates.h"
#include "BEWD_GoalKeeperStates.h"
#include "../../ParamLoader.h"
#include "2D/geometry.h"
#include "Game/EntityManager.h"
#include "Messaging/MessageDispatcher.h"
#include "../../SoccerMessages.h"
#include "BEWD_TeamStates.h"
#include "Debug/DebugConsole.h"
#include <windows.h>

using std::vector;


BEWD_SoccerTeam::BEWD_SoccerTeam(Goal*        home_goal,
                       Goal*        opponents_goal,
                       SoccerPitch* pitch,
					   team_color   color): AbstSoccerTeam(home_goal, opponents_goal, pitch, color)
{
	InitStateMachine();
	CreatePlayers();
	RegisterPlayers();
	InitPlayers();

  //create the sweet spot calculator
  m_pSupportSpotCalc = new SupportSpotCalculator(Prm.NumSupportSpotsX,
                                                 Prm.NumSupportSpotsY,
                                                 this);
}


//----------------------- dtor -------------------------------------------
//
//------------------------------------------------------------------------
BEWD_SoccerTeam::~BEWD_SoccerTeam()
{

  delete m_pSupportSpotCalc;
}

void BEWD_SoccerTeam::InitStateMachine()
{
  m_pStateMachine = new StateMachine<AbstSoccerTeam>(this);

  m_pStateMachine->SetCurrentState(BEWD_Defending::Instance());
  m_pStateMachine->SetPreviousState(BEWD_Defending::Instance());
  m_pStateMachine->SetGlobalState(NULL);
}

void BEWD_SoccerTeam::InitPlayers()
{
  //set default steering behaviors
  std::vector<PlayerBase*>::iterator it = m_Players.begin();

  for (it; it != m_Players.end(); ++it)
  {
    (*it)->Steering()->SeparationOn();   
  }
}



//------------------------- CreatePlayers --------------------------------
//
//  creates the players
//------------------------------------------------------------------------
void BEWD_SoccerTeam::CreatePlayers()
{
  if (Color() == blue)
  {
    
	//goalkeeper
    m_Players.push_back(new GoalKeeper(this,
                               1,
                               BEWD_TendGoal::Instance(),
							   BEWD_GlobalKeeperState::Instance(),
                               Vector2D(0,1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale));

 
    //create the players
    m_Players.push_back(new FieldPlayer(this,
                               4,
                               BEWD_Wait::Instance(),
							   BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::attacker));



        m_Players.push_back(new FieldPlayer(this,
                               7,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::attacker));


 


        m_Players.push_back(new FieldPlayer(this,
                               8,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::defender));


        m_Players.push_back(new FieldPlayer(this,
                               6,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                              PlayerBase::defender));

  }

  else
  {

     
     //goalkeeper
    m_Players.push_back(new GoalKeeper(this,
                               16,
                               BEWD_TendGoal::Instance(),
                               BEWD_GlobalKeeperState::Instance(),
                               Vector2D(0,-1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale));


    m_Players.push_back(new FieldPlayer(this,
                               9,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,-1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::attacker));

    m_Players.push_back(new FieldPlayer(this,
                               11,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,-1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::attacker));


 
    m_Players.push_back(new FieldPlayer(this,
                               12,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,-1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::defender));


    m_Players.push_back(new FieldPlayer(this,
                               14,
                               BEWD_Wait::Instance(),
                               BEWD_GlobalPlayerState::Instance(),
                               Vector2D(0,-1),
                               Vector2D(0.0, 0.0),
                               Prm.PlayerMass,
                               Prm.PlayerMaxForce,
                               Prm.PlayerMaxSpeedWithoutBall,
                               Prm.PlayerMaxTurnRate,
                               Prm.PlayerScale,
                               PlayerBase::defender));
                      
  }
}

void BEWD_SoccerTeam::prepareForKickoff ()
{
	GetFSM()->ChangeState(BEWD_PrepareForKickOff::Instance());
}

//---------------------- UpdateTargetsOfWaitingPlayers ------------------------
//
//  
void BEWD_SoccerTeam::UpdateTargetsOfWaitingPlayers()const
{
  std::vector<PlayerBase*>::const_iterator it = m_Players.begin();

  for (it; it != m_Players.end(); ++it)
  {  
    if ( (*it)->Role() != PlayerBase::goal_keeper )
    {
      //cast to a field player
      FieldPlayer* plyr = static_cast<FieldPlayer*>(*it);
      
      if ( plyr->GetFSM()->isInState(*BEWD_Wait::Instance()))
	  {
		  plyr->GetFSM()->ChangeState(BEWD_ChaseBall::Instance());
	  }
	  else if(plyr->GetFSM()->isInState(*BEWD_ReturnToHomeRegion::Instance()) )
      {
        plyr->Steering()->SetTarget(plyr->HomeRegion()->Center());
      }
    }
  }
}