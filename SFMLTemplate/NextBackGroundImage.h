#pragma once

#include <SFML/Graphics.hpp>
#include "SFMLObject.h"

class NextBackGroundImage : public SFMLObject
{
public:
	NextBackGroundImage(float x, float y);
	virtual void Update();
};
