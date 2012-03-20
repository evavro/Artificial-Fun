#ifndef ABSTSTEERINGBEHAVIORS_H
#define ABSTSTEERINGBEHAVIORS_H
#pragma warning (disable:4786)
//------------------------------------------------------------------------
//
//  Name:   AbstSteeringBehavior.h
//
//  Desc:   class to encapsulate steering behaviors for a Raven_Bot
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
// RB 2/25/2006 Abstractified
//------------------------------------------------------------------------
#include <vector>
#include <windows.h>
#include <string>
#include <list>
#include "2d/Vector2D.h"
#include "constants.h"

class AbstRaven_Bot;
class Wall2D;
class BaseGameEntity;
class Raven_Game;


//------------------------------------------------------------------------

class AbstSteering
{
public:
  
  enum summing_method{weighted_average, prioritized, dithered};

protected:

  enum behavior_type
  {
    none               = 0x00000,
    seek               = 0x00002,
    arrive             = 0x00008,
    wander             = 0x00010,
    separation         = 0x00040,
    wall_avoidance     = 0x00200,
  };

protected:

  
  //a pointer to the owner of this instance
  AbstRaven_Bot*     m_pRaven_Bot; 
  
  //pointer to the world data
  Raven_Game*    m_pWorld;
  
  //the steering force created by the combined effect of all
  //the selected behaviors
  Vector2D       m_vSteeringForce;
 
  //these can be used to keep track of friends, pursuers, or prey
  AbstRaven_Bot*     m_pTargetAgent1;
  AbstRaven_Bot*     m_pTargetAgent2;

  //the current target
  Vector2D    m_vTarget;


  //a vertex buffer to contain the feelers rqd for wall avoidance  
  std::vector<Vector2D> m_Feelers;
  
  //the length of the 'feeler/s' used in wall detection
  double                 m_dWallDetectionFeelerLength;


  //the current position on the wander circle the agent is
  //attempting to steer towards
  Vector2D     m_vWanderTarget; 

  //explained above
  double        m_dWanderJitter;
  double        m_dWanderRadius;
  double        m_dWanderDistance;


  //multipliers. These can be adjusted to effect strength of the  
  //appropriate behavior.
  double        m_dWeightSeparation;
  double        m_dWeightWander;
  double        m_dWeightWallAvoidance;
  double        m_dWeightSeek;
  double        m_dWeightArrive;


  //how far the agent can 'see'
  double        m_dViewDistance;

  //binary flags to indicate whether or not a behavior should be active
  int           m_iFlags;

  
  //Arrive makes use of these to determine how quickly a Raven_Bot
  //should decelerate to its target
  enum Deceleration{slow = 3, normal = 2, fast = 1};

  //default
  Deceleration m_Deceleration;

  //is cell space partitioning to be used or not?
  bool          m_bCellSpaceOn;
 
  //what type of method is used to sum any active behavior
  summing_method  m_SummingMethod;


  //this function tests if a specific bit of m_iFlags is set
  bool      On(behavior_type bt){return (m_iFlags & bt) == bt;}

  bool      AccumulateForce(Vector2D &sf, Vector2D ForceToAdd);

  //creates the antenna utilized by the wall avoidance behavior
  void      CreateFeelers();



   /* .......................................................

                    BEGIN BEHAVIOR DECLARATIONS

      .......................................................*/


  //this behavior moves the agent towards a target position
  virtual Vector2D Seek(const Vector2D &target);

  //this behavior is similar to seek but it attempts to arrive 
  //at the target with a zero velocity
  virtual Vector2D Arrive(const Vector2D    &target,
                  const Deceleration deceleration);

  //this behavior makes the agent wander about randomly
  virtual Vector2D Wander();

  //this returns a steering force which will keep the agent away from any
  //walls it may encounter
  virtual Vector2D WallAvoidance(const std::vector<Wall2D*> &walls);

  
  virtual Vector2D Separation(const std::list<AbstRaven_Bot*> &agents);


    /* .......................................................

                       END BEHAVIOR DECLARATIONS

      .......................................................*/

  //calculates and sums the steering forces from any active behaviors
  virtual Vector2D CalculatePrioritized();

  
public:

  AbstSteering(Raven_Game* world, AbstRaven_Bot* agent);

  virtual ~AbstSteering();

  //calculates and sums the steering forces from any active behaviors
  virtual Vector2D Calculate();

  //calculates the component of the steering force that is parallel
  //with the Raven_Bot heading
  double    ForwardComponent();

  //calculates the component of the steering force that is perpendicuar
  //with the Raven_Bot heading
  double    SideComponent();


  void      SetTarget(Vector2D t){m_vTarget = t;}
  Vector2D  Target()const{return m_vTarget;}

  void      SetTargetAgent1(AbstRaven_Bot* Agent){m_pTargetAgent1 = Agent;}
  void      SetTargetAgent2(AbstRaven_Bot* Agent){m_pTargetAgent2 = Agent;}


  Vector2D  Force()const{return m_vSteeringForce;}

  void      SetSummingMethod(summing_method sm){m_SummingMethod = sm;}


  void SeekOn(){m_iFlags |= seek;}
  void ArriveOn(){m_iFlags |= arrive;}
  void WanderOn(){m_iFlags |= wander;}
  void SeparationOn(){m_iFlags |= separation;}
  void WallAvoidanceOn(){m_iFlags |= wall_avoidance;}

  void SeekOff()  {if(On(seek))   m_iFlags ^=seek;}
  void ArriveOff(){if(On(arrive)) m_iFlags ^=arrive;}
  void WanderOff(){if(On(wander)) m_iFlags ^=wander;}
  void SeparationOff(){if(On(separation)) m_iFlags ^=separation;}
  void WallAvoidanceOff(){if(On(wall_avoidance)) m_iFlags ^=wall_avoidance;}

  bool SeekIsOn(){return On(seek);}
  bool ArriveIsOn(){return On(arrive);}
  bool WanderIsOn(){return On(wander);}
  bool SeparationIsOn(){return On(separation);}
  bool WallAvoidanceIsOn(){return On(wall_avoidance);}

  const std::vector<Vector2D>& GetFeelers()const{return m_Feelers;}
  
  double WanderJitter()const{return m_dWanderJitter;}
  double WanderDistance()const{return m_dWanderDistance;}
  double WanderRadius()const{return m_dWanderRadius;}

  double SeparationWeight()const{return m_dWeightSeparation;}

};




#endif