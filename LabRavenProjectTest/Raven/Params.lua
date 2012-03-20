
-------------------------[[ General game parameters ]]-------------------------
-------------------------------------------------------------------------------

--the number of bots the game instantiates

NumBots = 3

BotNames = {}

BotNames[1] = "Raven_Bot"
BotNames[2] = "Raven_Bot"
BotNames[3] = "RB_Bot"


--this is the maximum number of search cycles allocated to *all* current path
-- planning searches per update
MaxSearchCyclesPerUpdateStep = 1000

--the name of the default map
StartMap = "maps/Raven_DM1.map"

--cell space partitioning defaults
NumCellsX = 10
NumCellsY = 10

--how long the graves remain on screen
GraveLifetime = 5

--Game duration (minutes)
GameDuration = 3


-------------------------[[ bot parameters ]]----------------------------------
-------------------------------------------------------------------------------

Bot_MaxHealth = 100
Bot_MaxSpeed  = 1
Bot_Mass      = 1
Bot_MaxForce  = 1.0
Bot_MaxHeadTurnRate = 0.2
Bot_Scale       = 0.8

--special movement speeds (unused)
Bot_MaxSwimmingSpeed = Bot_MaxSpeed * 0.2
Bot_MaxCrawlingSpeed = Bot_MaxSpeed * 0.6

--the bot's field of view (in degrees)
Bot_FOV = 180

--the bot's reaction time (in seconds)
Bot_ReactionTime = 0.2

--how accurate the bots are at aiming. 0 is very accurate, (the value represents
-- the max deviation in range (in radians))
Bot_AimAccuracy = 0.1

--how long a flash is displayed when the bot is hit
HitFlashTime = 0.2

--the number of times a second the triggers are updated
Bot_TriggerUpdateFreq = 8


-------------------------[[ giver-trigger parameters ]]-----------------------------
-------------------------------------------------------------------------------

--how close a bot must be to a giver-trigger for it to affect it
DefaultGiverTriggerRange = 10

--how many seconds before a giver-trigger reactivates itself
Health_RespawnDelay  = 10
Weapon_RespawnDelay  = 15


-------------------------[[ weapon parameters ]]-------------------------------
-------------------------------------------------------------------------------

Blaster_FiringFreq       = 3
Blaster_MaxSpeed		 = 5
Blaster_DefaultRounds    = 0 --not used, a blaster always has ammo
Blaster_MaxRoundsCarried = 0 --as above
Blaster_IdealRange		   = 50
Blaster_SoundRange	     = 100

Bolt_MaxSpeed    = 5
Bolt_Mass        = 1
Bolt_MaxForce    = 100.0
Bolt_Scale       = Bot_Scale
Bolt_Damage      = 1



RocketLauncher_FiringFreq       = 1.5
RocketLauncher_DefaultRounds      = 15
RocketLauncher_MaxRoundsCarried = 50
RocketLauncher_IdealRange  = 150
RocketLauncher_SoundRange  = 400

Rocket_BlastRadius = 20
Rocket_MaxSpeed    = 3
Rocket_Mass        = 1
Rocket_MaxForce    = 10.0
Rocket_Scale       = Bot_Scale
Rocket_Damage      = 5
Rocket_ExplosionDecayRate = 2.0   --how fast the explosion occurs (in secs)


RailGun_FiringFreq       = 1
RailGun_DefaultRounds      = 15
RailGun_MaxRoundsCarried = 50
RailGun_IdealRange  = 200
RailGun_SoundRange  = 400

Slug_MaxSpeed    = 5000
Slug_Mass        = 0.1
Slug_MaxForce    = 10000.0
Slug_Scale       = Bot_Scale
Slug_Persistance = 0.2
Slug_Damage      = 10



ShotGun_FiringFreq       = 1
ShotGun_DefaultRounds      = 15
ShotGun_MaxRoundsCarried = 50
ShotGun_NumBallsInShell  = 10
ShotGun_Spread           = 0.05
ShotGun_IdealRange  = 100
ShotGun_SoundRange  = 400

Pellet_MaxSpeed    = 5000
Pellet_Mass        = 0.1
Pellet_MaxForce    = 1000.0
Pellet_Scale       = Bot_Scale
Pellet_Persistance = 0.1
Pellet_Damage      = 1


  