#include "BarFly.h"

// TODO: We have to implement HandleMessage
bool BarFly::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}

void BarFly::Update()
{
	SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	m_pStateMachine->Update();
}

void BarFly::IncrementIntoxication(const int value)
{
	m_iIntoxication += value;
	if (m_iIntoxication > MaxIntoxication()) m_iIntoxication = MaxIntoxication();
}

void BarFly::DecrementIntoxication(const int value)
{
	m_iIntoxication -= value;
	if (m_iIntoxication < 0) m_iIntoxication = 0;
}

bool BarFly::Drunk()const
{
	if (m_iIntoxication >= MaxDrunk){ return true; }

	return false;
}

bool BarFly::Sober()const
{
	if (m_iIntoxication == 0){ return true; }

		return false;
}
