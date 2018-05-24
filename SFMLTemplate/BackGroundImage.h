#pragma once

#include <SFML/Graphics.hpp>
#include "SFMLObject.h"

class BackGroundImage : public SFMLObject
{
public:
	BackGroundImage(float x, float y);
	virtual void Update();
};
