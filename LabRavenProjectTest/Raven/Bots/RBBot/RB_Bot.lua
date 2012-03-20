
-------------------------[[ bot parameters ]]----------------------------------
-------------------------------------------------------------------------------

-- originally constants in Raven_SteeringBehaviors
--the radius of the constraining circle for the wander behavior
WanderRad    = 1.2
--distance the wander circle is projected in front of the agent
WanderDist   = 2.0
--the maximum amount of displacement along the circle each frame
WanderJitterPerSec = 20.0

--the number of times a second a bot 'thinks' about weapon selection
Bot_WeaponSelectionFrequency = 5

--the number of times a second a bot 'thinks' about changing strategy
Bot_GoalAppraisalUpdateFreq = 2

--the number of times a second a bot updates its target info
Bot_TargetingUpdateFreq = 5

--the number of times a second a bot updates its vision
Bot_VisionUpdateFreq = 0

--note that a frequency of -1 will disable the feature and a frequency of zero
--will ensure the feature is updated every bot update

--how long (in seconds) the bot will keep pointing its weapon at its target
--after the target goes out of view
Bot_AimPersistance = 0.5


--how long (in seconds) a bot's sensory memory persists
Bot_MemorySpan = 5

--goal tweakers
Bot_HealthGoalTweaker     = 1.2
Bot_ShotgunGoalTweaker    = 0.6
Bot_RailgunGoalTweaker    = 0.5
Bot_RocketLauncherTweaker = 0.6
Bot_ExploreTweaker		  = 0.2
Bot_AggroGoalTweaker      = 0.8

-------------------------[[ steering parameters ]]-----------------------------
-------------------------------------------------------------------------------


--use these values to tweak the amount that each steering force
--contributes to the total steering force
SeparationWeight       =   10.0
WallAvoidanceWeight     =  10.0
WanderWeight            =  1.0
SeekWeight              =  0.5
ArriveWeight            =  1.0

--how close a neighbour must be before an agent considers it
--to be within its neighborhood (for separation)
ViewDistance            =  15.0

--max feeler length (was 25 * Bot_Scale)
-- but Bot_Scale is defined globally and not accessible here
WallDetectionFeelerLength = 20.0

--used in path following. Determines how close a bot must be to a waypoint
--before it seeks the next waypoint
WaypointSeekDist   = 5
