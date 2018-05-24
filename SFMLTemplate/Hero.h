#pragma once
#include "SFMLObject.h"
#include "Box.h"

class Hero : public SFMLObject
{
public:
	Hero(float x, float y);
	virtual void Update();
	int GetSteps();
	~Hero();
	virtual void OnAlarm(int alarm);
private:
	bool withBOX = false;
	SFMLObject * thebox;
};

