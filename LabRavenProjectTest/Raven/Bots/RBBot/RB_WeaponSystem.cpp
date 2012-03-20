#include "RB_WeaponSystem.h"
#include "../../armory/Weapon_RocketLauncher.h"
#include "../../armory/Weapon_RailGun.h"
#include "../../armory/Weapon_ShotGun.h"
#include "../../armory/Weapon_Blaster.h"
#include "../../AbstRaven_Bot.h"
#include "misc/utils.h"
#include "RB_BotScriptor.h"
#include "../../Raven_Game.h"
#include "../../Raven_UserOptions.h"
#include "2D/transformations.h"



//------------------------- ctor ----------------------------------------------
//-----------------------------------------------------------------------------
RB_WeaponSystem::RB_WeaponSystem(AbstRaven_Bot* owner,
                                       double ReactionTime,
                                       double AimAccuracy,
                                       double AimPersistance): 
	AbstWeaponSystem(owner, ReactionTime, AimAccuracy, AimPersistance)

{

}

//-------------------------------- SelectWeapon -------------------------------
// Differs from Buckland's only in that we change weapons on when we can see
// the opponent.
//-----------------------------------------------------------------------------
void RB_WeaponSystem::SelectWeapon()
{ 
  //if a target is present use fuzzy logic to determine the most desirable 
  //weapon.
  if (m_pOwner->GetTargetSys()->isTargetPresent() && m_pOwner->GetTargetSys()->isTargetWithinFOV())
  {
    //calculate the distance to the target
    double DistToTarget = Vec2DDistance(m_pOwner->Pos(), m_pOwner->GetTargetSys()->GetTarget()->Pos());

    //for each weapon in the inventory calculate its desirability given the 
    //current situation. The most desirable weapon is selected
    double BestSoFar = MinDouble;

    WeaponMap::const_iterator curWeap;
    for (curWeap=m_WeaponMap.begin(); curWeap != m_WeaponMap.end(); ++curWeap)
    {
      //grab the desirability of this weapon (desirability is based upon
      //distance to target and ammo remaining)
      if (curWeap->second)
      {
        double score = curWeap->second->GetDesirability(DistToTarget);

        //if it is the most desirable so far select it
        if (score > BestSoFar)
        {
          BestSoFar = score;

          //place the weapon in the bot's hand.
          m_pCurrentWeapon = curWeap->second;
        }
      }
    }
  }

  else
  {
    m_pCurrentWeapon = m_WeaponMap[type_blaster];
  }
}