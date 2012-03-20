#ifndef BLASTER_H
#define BLASTER_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Weapon_Blaster.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   
//-----------------------------------------------------------------------------
#include "Raven_Weapon.h"


class  AbstRaven_Bot;



class Blaster : public Raven_Weapon
{
private:

  void  InitializeFuzzyModule();
  
public:

  Blaster(AbstRaven_Bot*   owner);


  void  Render();

  void  ShootAt(Vector2D pos);

  double GetDesirability(double DistToTarget);
};



#endif