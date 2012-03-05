#include "SoccerMessages.h"


inline std::string MessageToString(int msg)
{
  switch (msg)
  {
  case Msg_ReceiveBall:
    
    return "Msg_ReceiveBall";

  case Msg_PassToMe:
    
    return "Msg_PassToMe";

  case Msg_SupportAttacker:

    return "Msg_SupportAttacker";

  case Msg_DefendGoal:

    return "Msg_DefendGoal";

  case Msg_GoHome:

    return "Msg_GoHome";

  case Msg_MoveToRegion:

	return "Msg_MoveToRegion";

  case Msg_Wait:

    return "Msg_Wait";

  default:

	return "INVALID MESSAGE!!";
  }
}
