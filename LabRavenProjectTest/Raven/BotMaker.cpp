#include "BotMaker.h"
#include <string>
#include <map>
#include "AbstRaven_Bot.h"
#include "Debug/DebugConsole.h"

MakerMap* BotMaker::registry;

BotMaker::BotMaker (std::string className)
	{
		if (registry == NULL)
			registry = new MakerMap();
		registry->insert( std::make_pair(className, this) );
	}

	AbstRaven_Bot* BotMaker::newBot (std::string className, Raven_Game* world, Vector2D pos)

{
	MakerMap::iterator iter = registry->find(className);
	if (iter != registry->end())
	// Get the TeamMaker object and call the factory method
	{
		BotMaker* maker = (*iter).second;
		return maker->makeBot(world, pos);
	} else
	{
		debug_con << "No such bot class registered: " << className;
		return NULL;
	}
}