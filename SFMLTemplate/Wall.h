#pragma once
#include "SFMLObject.h"
class Wall : public SFMLObject
{

public:
	Wall(float x, float y);
	Wall(const std::string & resourceName, float x, float y);
	virtual void Update();
	~Wall();
};

