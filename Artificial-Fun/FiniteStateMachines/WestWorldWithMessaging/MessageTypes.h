#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_EnterBar,
  Msg_Insult,
  Msg_Punch
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_EnterBar:

	return "EnteredBar";

  case Msg_Insult:

	return "Insult";

  case Msg_Punch:

	return "Punch";

  default:

    return "Not recognized!";
  }
}

#endif