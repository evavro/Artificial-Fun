#ifndef RAVEN_BOTSCRIPTOR_H
#define RAVEN_BOTSCRIPTOR_H
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



#define script Raven_Scriptor::Instance()

class Raven_BotScriptor : public Scriptor
{
private:
  
  Raven_BotScriptor();

  //copy ctor and assignment should be private
  Raven_BotScriptor(const Raven_BotScriptor&);
  Raven_BotScriptor& operator=(const Raven_BotScriptor&);

public:

  static Raven_BotScriptor* Instance();

};

#endif

 
  

