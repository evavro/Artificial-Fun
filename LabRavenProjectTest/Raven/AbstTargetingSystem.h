#ifndef ABSTTARGETING_SYSTEM_H
#define ABSTTARGETING_SYSTEM_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   AbstTargetingSystem.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class to select a target from the opponents currently in a bot's
//          perceptive memory.
// 2/25/2006 RB
// Abstractified for student use in the tournament.
//-----------------------------------------------------------------------------
#include "2d/Vector2D.h"
#include <list>


class AbstRaven_Bot;

class AbstTargetingSystem
{
protected:

  //the owner of this system
  AbstRaven_Bot*  m_pOwner;

  //the current target (this will be null if there is no target assigned)
  AbstRaven_Bot*  m_pCurrentTarget;

public:

  AbstTargetingSystem(AbstRaven_Bot* owner);

  //each time this method is called the opponents in the owner's sensory 
  //memory are examined and the closest  is assigned to m_pCurrentTarget.
  //if there are no opponents that have had their memory records updated
  //within the memory span of the owner then the current target is set
  //to null
  virtual void       Update() = 0;

  //returns true if there is a currently assigned target
  bool       isTargetPresent()const{return m_pCurrentTarget != 0;}

  //returns true if the target is within the field of view of the owner
  virtual bool       isTargetWithinFOV()const;

  //returns true if there is unobstructed line of sight between the target
  //and the owner
  virtual bool       isTargetShootable()const;

  //returns the position the target was last seen. Throws an exception if
  //there is no target currently assigned
  virtual Vector2D   GetLastRecordedPosition()const;

  //returns the amount of time the target has been in the field of view
  virtual double      GetTimeTargetHasBeenVisible()const;

  //returns the amount of time the target has been out of view
  virtual double      GetTimeTargetHasBeenOutOfView()const;
  
  //returns a pointer to the target. null if no target current.
  AbstRaven_Bot* GetTarget()const{return m_pCurrentTarget;}

  //sets the target pointer to null
  void       ClearTarget(){m_pCurrentTarget=0;}
};




#endif
