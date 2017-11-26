#ifndef DELAYTEXT_H
#define DELAYTEXT_H

class DelayText
{
public:
	DelayText();
	~DelayText();
	void SetDelayAmount_ms(int delay);
	
private:
	int m_delay;
};
#endif	//DELAYTEXT_H
