#include "RB_TargetingSystem.h"
#include "../../AbstRaven_Bot.h"
#include "../../Raven_SensoryMemory.h"



//-------------------------------- ctor ---------------------------------------
//-----------------------------------------------------------------------------
RB_TargetingSystem::RB_TargetingSystem(AbstRaven_Bot* owner):
	AbstTargetingSystem(owner)
{}



//----------------------------- Update ----------------------------------------
// Differs from Buckland's only that we use the "Bully" tactic: target whichever
// bot is weakest (when we have a choice.)
//-----------------------------------------------------------------------------
void RB_TargetingSystem::Update()
{
  int LowestHealthSoFar = MaxInt;
  m_pCurrentTarget       = 0;

  //grab a list of all the opponents the owner can sense
  std::list<AbstRaven_Bot*> SensedBots;
  SensedBots = m_pOwner->GetSensoryMem()->GetListOfRecentlySensedOpponents();
  
  std::list<AbstRaven_Bot*>::const_iterator curBot = SensedBots.begin();
  for (curBot; curBot != SensedBots.end(); ++curBot)
  {
    //make sure the bot is alive and that it is not the owner
    if ((*curBot)->isAlive() && (*curBot != m_pOwner) )
    {
      //double dist = Vec2DDistanceSq((*curBot)->Pos(), m_pOwner->Pos());
		int health = (*curBot)->Health();

      if (health < LowestHealthSoFar)
      {
        LowestHealthSoFar = health;
        m_pCurrentTarget = *curBot;
      }
    }
  }
}
