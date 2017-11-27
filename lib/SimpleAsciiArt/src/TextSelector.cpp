#include <TextSelector.h>
#include <stdio.h>
#include <cstring>

using namespace std;

TextSelector::TextSelector()
{
	
}

TextSelector::~TextSelector()
{
	DeleteTextSet();
}

void TextSelector::SetText(const char* text, unsigned char level)
{
	DeleteTextSet();
	m_level = level;
	m_interval = 0xff / level;
	m_textSet = new char[level];
	memcpy(m_textSet, text, level);
}

char TextSelector::SelectText(unsigned char grayScalelevel)
{
	return m_textSet[(grayScalelevel / m_interval >= m_level) ? (m_level - 1) :(grayScalelevel / m_interval)];
}

void TextSelector::DeleteTextSet()
{
	if(m_textSet != nullptr)
	{
		delete[] m_textSet;
		m_textSet = nullptr;
	}
}
