#pragma once

class PlayState
{
public:
	enum trans { PASS, CHASE_PASS };

	// Take in a vector of string arrays ("pl", "100,50")
	PlayState(void);
	~PlayState(void);
};
