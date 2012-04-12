#include "ET_BotMaker.h"


const ET_BotMaker ET_BotMaker::registerThis;

ET_BotMaker::ET_BotMaker() : BotMaker("ET_Bot") {}

AbstRaven_Bot* ET_BotMaker::makeBot(Raven_Game* world, Vector2D pos) const
   { 
      return new ET_Bot(world, pos); 
   }