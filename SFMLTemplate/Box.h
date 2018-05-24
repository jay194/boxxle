#pragma once
#include "Wall.h"
class Box : public Wall
{
public:
	Box(float x, float y);
	virtual void Update();
	~Box();
};

