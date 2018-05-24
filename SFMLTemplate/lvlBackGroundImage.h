#pragma once

#include <SFML/Graphics.hpp>
#include "SFMLObject.h"

class lvlBackGroundImage : public SFMLObject
{
public:
	lvlBackGroundImage(float x, float y);
	virtual void Update();
};
