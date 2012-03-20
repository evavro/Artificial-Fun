#ifndef RB_BOTSCRIPTOR_H
#define RB_BOTSCRIPTOR_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Raven_Scriptor
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   A Singleton Scriptor class for use with the Raven project
//-----------------------------------------------------------------------------
#include "Script/scriptor.h"


class RB_BotScriptor : public Scriptor
{
private:
  
  RB_BotScriptor();

  //copy ctor and assignment should be private
  RB_BotScriptor(const RB_BotScriptor&);
  RB_BotScriptor& operator=(const RB_BotScriptor&);

public:

  static RB_BotScriptor* Instance();

};

#endif

 
  

