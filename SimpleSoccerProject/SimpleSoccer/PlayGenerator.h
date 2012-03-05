#ifndef PlayGenerator_H
#define PlayGenerator_H
#pragma once

#include <string>
#include <vector>
#include "Play.h"

class PlayGenerator
{
private:
	vector<Play> plays;
	// vector Play plays;

	const int successWeight = 5;
	const int failedWeight = 2;

public:
	PlayGenerator(void);
	~PlayGenerator(void);

	void applyRandomDeterminedPlay();
	void applyRandomAdaptivePlay();
	void analyzeOpponentBehavior();
	void markSucccessfulPlay(Play*);
	void markFailedPlay(Play*);
};
