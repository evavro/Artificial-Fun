#ifndef BEWD_SOCCERTEAMMAKER_H
#define BEWD_SOCCERTEAMMAKER_H
#pragma warning (disable:4786)

//------------------------------------------------------------------------
//
//  Name:   BEWD_SoccerTeamMaker.h
//
//  Desc:   Factory class for SoccerTeam. 
//
//  Author: Robin Burke 2005 rburke@cs.depaul.edu
//
//------------------------------------------------------------------------

#include "../../TeamMaker.h"
#include "BEWD_SoccerTeam.h"
#include <string>
#include "../../Goal.h"
#include "../../SoccerPitch.h"

class BEWD_SoccerTeamMaker : public TeamMaker {
private:
   BEWD_SoccerTeamMaker();

   AbstSoccerTeam* makeTeam(Goal*        home_goal,
             Goal*        opponents_goal,
             SoccerPitch* pitch,
			 AbstSoccerTeam::team_color   color) const;
	
   // creation of static instance does automatic registration
    static const BEWD_SoccerTeamMaker registerThis;
};
#endif