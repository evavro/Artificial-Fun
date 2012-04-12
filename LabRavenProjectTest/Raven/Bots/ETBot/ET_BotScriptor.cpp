#include "ET_BotScriptor.h"

ET_BotScriptor* ET_BotScriptor::Instance()
{
  static ET_BotScriptor instance;

  return &instance;
}



ET_BotScriptor::ET_BotScriptor():Scriptor()
{
  RunScriptFile("Bots/ETBot/ET_Bot.lua");
}