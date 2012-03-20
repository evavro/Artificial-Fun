#include "RB_BotMaker.h"


const RB_BotMaker RB_BotMaker::registerThis;

RB_BotMaker::RB_BotMaker() : BotMaker("RB_Bot") {}

AbstRaven_Bot* RB_BotMaker::makeBot(Raven_Game* world, Vector2D pos) const
   { 
      return new RB_Bot(world, pos); 
   }