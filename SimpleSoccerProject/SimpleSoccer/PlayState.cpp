#include "PlayState.h"

PlayState::PlayState(void)
{
}

PlayState::~PlayState(void)
{
}

PlayState* PlayState::Instance()
{
  static PlayState instance;

  return &instance;
}


void PlayState::Enter(AbstSoccerTeam* team)
{
//#ifdef DEBUG_TEAM_STATES
  debug_con << team->Name() << " entering play state" << "";
//#endif

  // Can we make this only pertain to our team?

  //these define the home regions for this state of each of the players
  const int BlueRegions[TeamSize] = {1,9,11,7,4};
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


void PlayState::Execute(AbstSoccerTeam* team)
{
  //if this team is no longer in control, change states
  if (!team->InControl())
  {
    team->GetFSM()->ChangeState(MyDefending::Instance()); return;
  }

  //calculate the best position for any supporting attacker to move to
  team->DetermineBestSupportingPosition();
}

void PlayState::Exit(AbstSoccerTeam* team)
{
  //there is no supporting player for defense
  //team->SetSupportingPlayer(NULL);
}

// Inner controller Methods

void PlayState::parseStateString(string str)
{
	// implement CAJUN here to parse json objects
	// playerRegions.insert ( PR_Pair ("p1", 10 ) );
}

void PlayState::apply()
{

}

void PlayState::continueState()
{

}

bool PlayState::isStillValid()
{

}
