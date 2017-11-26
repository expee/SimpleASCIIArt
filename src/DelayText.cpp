#include "../include/DelayText.h"

DelayText::DelayText():
	m_delay(-1)
{
	
}

DelayText::~DelayText()
{
	
}

void DelayText::SetDelayAmount_ms(int delay)
{
	m_delay = delay;
}