#ifndef ET_BOTSCRIPTOR_H
#define ET_BOTSCRIPTOR_H
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


class ET_BotScriptor : public Scriptor
{
private:
  
  ET_BotScriptor();

  //copy ctor and assignment should be private
  ET_BotScriptor(const ET_BotScriptor&);
  ET_BotScriptor& operator=(const ET_BotScriptor&);

public:

  static ET_BotScriptor* Instance();

};

#endif

 
  

