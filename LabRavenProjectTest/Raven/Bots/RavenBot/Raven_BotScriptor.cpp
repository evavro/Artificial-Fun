#include "Raven_BotScriptor.h"

Raven_BotScriptor* Raven_BotScriptor::Instance()
{
  static Raven_BotScriptor instance;

  return &instance;
}



Raven_BotScriptor::Raven_BotScriptor():Scriptor()
{
  RunScriptFile("Bots/RavenBot/Raven_Bot.lua");
}