#ifndef TRIGGER_SOUNDNOTIFY_H
#define TRIGGER_SOUNDNOTIFY_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:     Trigger_SoundNotify.h
//
//  Author:   Mat Buckland
//
//  Desc:     whenever an agent makes a sound -- such as when a weapon fires --
//            this trigger can be used to notify other bots of the event.
//
//            This type of trigger has a circular trigger region and a lifetime
//            of 1 update-step
//
//-----------------------------------------------------------------------------
#include "Triggers/Trigger_LimitedLifetime.h"
#include "../AbstRaven_Bot.h"



class Trigger_SoundNotify : public Trigger_LimitedLifetime<AbstRaven_Bot>
{
private:

  //a pointer to the bot that has made the sound
  AbstRaven_Bot*  m_pSoundSource;

public:

  Trigger_SoundNotify(AbstRaven_Bot* source, double range);


  void  Try(AbstRaven_Bot*);

  void  Render(){}

};




#endif