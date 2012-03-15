#ifndef PlayGenerator_H
#define PlayGenerator_H
#pragma once

#include <string>
#include <vector>
#include "Play.h"


// This class will act as a controller, containing all of the possible plays that our team can select @ kickoff
class PlayGenerator
{
private:
	std::vector<Play> plays;

	const int successWeight = 5;
	const int failedWeight = 2;

public:
	PlayGenerator(void);
	~PlayGenerator(void);

	void ParseJSON(const JSONNode & node);

	void ApplyRandomDeterminedPlay();
	void ApplyRandomAdaptivePlay();
	void AnalyzeOpponentBehavior();
	void MarkSucccessfulPlay(Play*);
	void MarkFailedPlay(Play*);
};
