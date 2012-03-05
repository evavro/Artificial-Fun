#ifndef SOCCER_MESSAGES_H
#define SOCCER_MESSAGES_H

#define MOVE_TO_REGION 100

#include <string>

enum MessageType
{
  Msg_ReceiveBall,
  Msg_PassToMe,
  Msg_SupportAttacker,
  Msg_DefendGoal,
  Msg_GoHome,
  Msg_MoveToRegion,
  Msg_Wait
};

//converts an enumerated value to a string
inline std::string MessageToString(int msg);


#endif
