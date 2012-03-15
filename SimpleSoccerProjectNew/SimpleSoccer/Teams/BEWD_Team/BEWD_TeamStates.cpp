#include "BEWD_TeamStates.h"
#include "../../AbstSoccerTeam.h"
#include "../../PlayerBase.h"
#include "Messaging/MessageDispatcher.h"
#include "../../SoccerMessages.h"
#include "../../constants.h"
#include "../../SoccerPitch.h"

//uncomment to send state info to debug window
#define DEBUG_TEAM_STATES
#include "Debug/DebugConsole.h"

//************************************************************************ ATTACKING

BEWD_Attacking* BEWD_Attacking::Instance()
{
  static BEWD_Attacking instance;

  return &instance;
}


void BEWD_Attacking::Enter(AbstSoccerTeam* team)
{
//#ifdef DEBUG_TEAM_STATES
  //debug_con << team->Name() << " entering BEWD_Attacking state" << "";
//#endif

  //these define the home regions for this state of each of the players
  const int BlueRegions[TeamSize] = {1,1,1,10,10};
  const int RedRegions[TeamSize] = {16,8,6,10,13};

  //set up the player's home regions
  if (team->Color() == AbstSoccerTeam::blue)
  {
    team->ChangePlayerHomeRegions(BlueRegions);
  }
  else
  {
    team->ChangePlayerHomeRegions(RedRegions);
  }

  //if a player is in either the Wait or ReturnToHomeRegion states, its
  //steering target must be updated to that of its new home region to enable
  //it to move into the correct position.
  team->UpdateTargetsOfWaitingPlayers();
}


void BEWD_Attacking::Execute(AbstSoccerTeam* team)
{
  //if this team is no longer in control change states
  if (!team->InControl())
  {
    team->GetFSM()->ChangeState(BEWD_Defending::Instance()); return;
  }

  //calculate the best position for any supporting attacker to move to
  team->DetermineBestSupportingPosition();
}

void BEWD_Attacking::Exit(AbstSoccerTeam* team)
{
  //there is no supporting player for defense
  team->SetSupportingPlayer(NULL);
}



//************************************************************************ DEFENDING

BEWD_Defending* BEWD_Defending::Instance()
{
  static BEWD_Defending instance;

  return &instance;
}

void BEWD_Defending::Enter(AbstSoccerTeam* team)
{
#ifdef DEBUG_TEAM_STATES
  //debug_con << team->Name() << " entering BEWD_Defending state" << "";
#endif

  //these define the home regions for this state of each of the players
  const int BlueRegions[TeamSize] = {1,1,1,4,4};
  const int RedRegions[TeamSize] = {16,13,13,13,13};

  //set up the player's home regions
  if (team->Color() == AbstSoccerTeam::blue)
  {
    team->ChangePlayerHomeRegions(BlueRegions);
  }
  else
  {
    team->ChangePlayerHomeRegions(RedRegions);
  }
  
  //if a player is in either the Wait or ReturnToHomeRegion states, its
  //steering target must be updated to that of its new home region
  team->UpdateTargetsOfWaitingPlayers();
}

void BEWD_Defending::Execute(AbstSoccerTeam* team)
{
  //if in control change states
  if (team->InControl())
  {
    team->GetFSM()->ChangeState(BEWD_Attacking::Instance()); return;
  }
}


void BEWD_Defending::Exit(AbstSoccerTeam* team)
{
#ifdef DEBUG_TEAM_STATES
  //debug_con << team->Name() << " exiting BEWD_Defending state" << "";
#endif
}


//************************************************************************ KICKOFF
BEWD_PrepareForKickOff* BEWD_PrepareForKickOff::Instance()
{
  static BEWD_PrepareForKickOff instance;

  return &instance;
}

void BEWD_PrepareForKickOff::Enter(AbstSoccerTeam* team)
{
  //reset key player pointers
  team->SetControllingPlayer(NULL);
  team->SetSupportingPlayer(NULL);
  team->SetReceiver(NULL);
  team->SetPlayerClosestToBall(NULL);

  // TODO: Implement play generator here

  //send Msg_GoHome to each player.
  team->ReturnAllFieldPlayersToHome();
}

void BEWD_PrepareForKickOff::Execute(AbstSoccerTeam* team)
{
  //if both teams in position, start the game
  if (team->AllPlayersAtHome() && team->Opponents()->AllPlayersAtHome() ||
		(team->AllPlayersAtHome() && team->Pitch()->OneTeamReady()))
  {
    team->GetFSM()->ChangeState(BEWD_Defending::Instance());
  }
}

void BEWD_PrepareForKickOff::Exit(AbstSoccerTeam* team)
{
	if (team->Color() == AbstSoccerTeam::blue)
		team->Pitch()->SetBlueTeamReady();
	else
		team->Pitch()->SetRedTeamReady();
}