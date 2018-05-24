#pragma once

#include <SFML/Graphics.hpp>
#include "SFMLObject.h"

class FirstImage : public SFMLObject
{
public:
	FirstImage(float x, float y);
	virtual void Update();
};
