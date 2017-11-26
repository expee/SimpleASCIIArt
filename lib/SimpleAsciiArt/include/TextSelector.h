#ifndef TEXTSELECTOR_H
#define TEXTSELECTOR_H

class TextSelector
{
public:
	TextSelector();
	~TextSelector();
	void SetText(const char* text, unsigned char level);
	char SelectText(unsigned char grayScalelevel);
	
private:
	void DeleteTextSet();
	char* m_textSet;
	unsigned char m_interval;
	unsigned char m_level;
};
#endif	//TEXTSELECTOR_H
