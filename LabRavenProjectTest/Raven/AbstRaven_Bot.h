#ifndef ABSTRAVEN_BOT_H
#define ABSTRAVEN_BOT_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   AbstRaven_Bot.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:
// 2/24/2006 RB Added for tournament purposes
//-----------------------------------------------------------------------------
#include <vector>
#include <iosfwd>
#include <map>
#include <string>

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "AbstTargetingSystem.h"


class Raven_PathPlanner;
class AbstSteering;
class Raven_Game;
class Regulator;
class Raven_Weapon;
struct Telegram;
class Raven_Bot;
class Goal_Think;
class AbstWeaponSystem;
class Raven_SensoryMemory;




class AbstRaven_Bot : public MovingEntity
{
protected:

  enum Status{alive, dead, spawning};

protected:
	
  static const double TIME_FACTOR;
  // execution time (for scoring)
  LARGE_INTEGER		m_time;

  //alive, dead or spawning?
  Status                             m_Status;

  //a pointer to the world data
  Raven_Game*                        m_pWorld;

  //this object handles the arbitration and processing of high level goals
  Goal_Think*                        m_pBrain;

  //this is a class that acts as the bots sensory memory. Whenever this
  //bot sees or hears an opponent, a record of the event is updated in the 
  //memory.
  Raven_SensoryMemory*               m_pSensoryMem;

  //the bot uses this object to steer
  AbstSteering*                    m_pSteering;

  //the bot uses this to plan paths
  Raven_PathPlanner*                 m_pPathPlanner;

  //this is responsible for choosing the bot's current target
  AbstTargetingSystem*             m_pTargSys;

  //this handles all the weapons. and has methods for aiming, selecting and
  //shooting them
  AbstWeaponSystem*                m_pWeaponSys;

  //A regulator object limits the update frequency of a specific AI component
  Regulator*                         m_pWeaponSelectionRegulator;
  Regulator*                         m_pGoalArbitrationRegulator;
  Regulator*                         m_pTargetSelectionRegulator;
  Regulator*                         m_pTriggerTestRegulator;
  Regulator*                         m_pVisionUpdateRegulator;

  //the bot's health. Every time the bot is shot this value is decreased. If
  //it reaches zero then the bot dies (and respawns)
  int                                m_iHealth;
  
  //the bot's maximum health value. It starts its life with health at this value
  int                                m_iMaxHealth;

  //each time this bot kills another this value is incremented
  int                                m_iScore;
  int								m_iDeaths;
  
  //the direction the bot is facing (and therefore the direction of aim). 
  //Note that this may not be the same as the bot's heading, which always
  //points in the direction of the bot's movement
  Vector2D                           m_vFacing;

  //a bot only perceives other bots within this field of view
  double                             m_dFieldOfView;
  
  //to show that a player has been hit it is surrounded by a thick 
  //red circle for a fraction of a second. This variable represents
  //the number of update-steps the circle gets drawn
  int                                m_iNumUpdatesHitPersistant;

  //set to true when the bot is hit, and remains true until 
  //m_iNumUpdatesHitPersistant becomes zero. (used by the render method to
  //draw a thick red circle around a bot to indicate it's been hit)
  bool                               m_bHit;

  //set to true when a human player takes over control of the bot
  bool                               m_bPossessed;

  //a vertex buffer containing the bot's geometry
  std::vector<Vector2D>              m_vecBotVB;
  //the buffer for the transformed vertices
  std::vector<Vector2D>              m_vecBotVBTrans;


  //bots shouldn't be copied, only created or respawned
  AbstRaven_Bot(const Raven_Bot&);
  AbstRaven_Bot& operator=(const Raven_Bot&);

  //this method is called from the update method. It calculates and applies
  //the steering force for this time-step.
  void          UpdateMovement();

  //initializes the bot's VB with its geometry
  void          SetUpVertexBuffer();


public:
  
	AbstRaven_Bot(Raven_Game* world, Vector2D pos);
  virtual ~AbstRaven_Bot();

  //the usual suspects
  virtual void         Render();
  void         Update();
  virtual void	DoUpdate () = 0;
  virtual bool         HandleMessage(const Telegram& msg) = 0;
  void         Write(std::ostream&  os)const{/*not implemented*/}
  void         Read (std::ifstream& is){/*not implemented*/}

  //this rotates the bot's heading until it is facing directly at the target
  //position. Returns false if not facing at the target.
  virtual bool          RotateFacingTowardPosition(Vector2D target);
 
  //methods for accessing attribute data
  int           Health()const{return m_iHealth;}
  int           MaxHealth()const{return m_iMaxHealth;}
  void          ReduceHealth(unsigned int val);
  void          IncreaseHealth(unsigned int val);
  void          RestoreHealthToMaximum() {m_iHealth = m_iMaxHealth;}

  int           Score()const{return m_iScore;}
  void          IncrementScore(){++m_iScore;}
  int			Deaths()const{return m_iDeaths;}

  Vector2D      Facing()const{return m_vFacing;}
  double        FieldOfView()const{return m_dFieldOfView;}

  bool          isPossessed()const{return m_bPossessed;}
  bool          isDead()const{return m_Status == dead;}
  bool          isAlive()const{return m_Status == alive;}
  bool          isSpawning()const{return m_Status == spawning;}
  
  void          SetSpawning(){m_Status = spawning;}
  void          SetDead(){m_Status = dead;}
  void          SetAlive(){m_Status = alive;}

  LARGE_INTEGER	GetTime () const {return m_time;}
  void			AddTime (LONGLONG delta) { m_time.QuadPart += delta; }
  void			AddTime (LARGE_INTEGER delta) { AddTime(delta.QuadPart); }
  double		GetFloatTime () const {return m_time.QuadPart / TIME_FACTOR; }

  //returns a value indicating the time in seconds it will take the bot
  //to reach the given position at its current speed.
  double        CalculateTimeToReachPosition(Vector2D pos)const; 

  //returns true if the bot is close to the given position
  bool          isAtPosition(Vector2D pos)const;


  //interface for human player
  void          FireWeapon(Vector2D pos);
  void          ChangeWeapon(unsigned int type);
  void          TakePossession();
  void          Exorcise();

  //spawns the bot at the given position
  virtual void          Spawn(Vector2D pos);
  
  //returns true if this bot is ready to test against all triggers
  virtual bool          isReadyForTriggerUpdate()const;

  //returns true if the bot has line of sight to the given position.
  virtual bool          hasLOSto(Vector2D pos)const;

  //returns true if this bot can move directly to the given position
  //without bumping into any walls
  virtual bool          canWalkTo(Vector2D pos)const;

  //similar to above. Returns true if the bot can move between the two
  //given positions without bumping into any walls
  virtual bool          canWalkBetween(Vector2D from, Vector2D to)const;

  //returns true if there is space enough to step in the indicated direction
  //If true PositionOfStep will be assigned the offset position
  virtual bool          canStepLeft(Vector2D& PositionOfStep)const;
  virtual bool          canStepRight(Vector2D& PositionOfStep)const;
  virtual bool          canStepForward(Vector2D& PositionOfStep)const;
  virtual bool          canStepBackward(Vector2D& PositionOfStep)const;

  
  Raven_Game* const                  GetWorld(){return m_pWorld;} 
  AbstSteering* const              GetSteering(){return m_pSteering;}
  Raven_PathPlanner* const           GetPathPlanner(){return m_pPathPlanner;}
  Goal_Think* const                  GetBrain(){return m_pBrain;}
  const AbstTargetingSystem* const GetTargetSys()const{return m_pTargSys;}
  AbstTargetingSystem* const       GetTargetSys(){return m_pTargSys;}
  AbstRaven_Bot* const                   GetTargetBot()const{return m_pTargSys->GetTarget();}
  AbstWeaponSystem* const          GetWeaponSys()const{return m_pWeaponSys;}
  Raven_SensoryMemory* const         GetSensoryMem()const{return m_pSensoryMem;}

  // RB Added so that different bots can be rendered in different colors
  virtual void			SelectBodyPen() = 0;
  virtual void			SelectHeadPen() = 0;

  virtual std::string const GetName () const = 0;
};




#endif