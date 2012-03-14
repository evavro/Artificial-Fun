#include "BEWD_SoccerTeamMaker.h"


const BEWD_SoccerTeamMaker BEWD_SoccerTeamMaker::registerThis;

BEWD_SoccerTeamMaker::BEWD_SoccerTeamMaker() : TeamMaker("BEWD_SoccerTeam") {}

AbstSoccerTeam* BEWD_SoccerTeamMaker::makeTeam(Goal* home_goal,
             Goal*        opponents_goal,
             SoccerPitch* pitch,
			 AbstSoccerTeam::team_color   color) const
   { 
      return new BEWD_SoccerTeam(home_goal, opponents_goal, pitch, color); 
   }