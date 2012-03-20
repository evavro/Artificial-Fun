#ifndef RB_WEAPONSYSTEM
#define RB_WEAPONSYSTEM
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Raven_WeaponSystem.h
//
//  Author: Mat Buckland (ai-junkie.com)
//
//  Desc:   class to manage all operations specific to weapons and their
//          deployment
//
//-----------------------------------------------------------------------------
#include <map>
#include "2d/vector2d.h"
#include "../../AbstWeaponSystem.h"

class AbstRaven_Bot;
class Raven_Weapon;



class RB_WeaponSystem : public AbstWeaponSystem
{

public:

  RB_WeaponSystem(AbstRaven_Bot* owner,
                     double      ReactionTime,
                     double      AimAccuracy,
                     double      AimPersistance);

	void          SelectWeapon();
};

#endif