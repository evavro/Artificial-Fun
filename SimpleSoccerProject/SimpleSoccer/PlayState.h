#include <hash_map>
#include <string>

#include "../../AbstSoccerTeam.h"
#include "../../PlayerBase.h"
#include "Messaging/MessageDispatcher.h"
#include "../../SoccerMessages.h"
#include "../../constants.h"
#include "../../SoccerPitch.h"
#include "../../FieldPlayer.h"
#include "misc/json/elements.h"
#include "misc/json/reader.h"

#pragma once

using namespace std;
using namespace stdext;

class PlayState : public State<AbstSoccerTeam>
{
	private:
		hash_map <FieldPlayer, int> playerRegions;
		hash_map <FieldPlayer, int> :: const_iterator playerRegions_AcIter, playerRegions_RcIter;
		typedef pair <string, int> PR_Pair;

		// take in json object here
		PlayState(AbstSoccerTeam* team);
		~PlayState(void);

	public:
		enum trans { PASS, CHASE_PASS };

		// Take in a vector of string arrays ("pl", "100,50")

		static PlayState* Instance();

		void Enter(AbstSoccerTeam* team);
		void Execute(AbstSoccerTeam* team);
		void Exit(AbstSoccerTeam* team);
		bool OnMessage(AbstSoccerTeam*, const Telegram&){return false;}

		void parseStateString(string);
		void apply();
		void continueState();
		bool isStillValid();
};
