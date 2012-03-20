#include "Raven_BotMaker.h"


const Raven_BotMaker Raven_BotMaker::registerThis;

Raven_BotMaker::Raven_BotMaker() : BotMaker("Raven_Bot") {}

AbstRaven_Bot* Raven_BotMaker::makeBot(Raven_Game* world, Vector2D pos) const
   { 
      return new Raven_Bot(world, pos); 
   }