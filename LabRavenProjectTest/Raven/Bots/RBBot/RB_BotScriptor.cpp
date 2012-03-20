#include "RB_BotScriptor.h"

RB_BotScriptor* RB_BotScriptor::Instance()
{
  static RB_BotScriptor instance;

  return &instance;
}



RB_BotScriptor::RB_BotScriptor():Scriptor()
{
  RunScriptFile("Bots/RBBot/RB_Bot.lua");
}