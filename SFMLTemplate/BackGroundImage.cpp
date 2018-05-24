#include "BackGroundImage.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"

BackGroundImage::BackGroundImage(float x, float y)
	: SFMLObject("backgroundImage", x, y, 1, 1)
{
	// Nothing here...
}

void BackGroundImage::Update()
{
	// Housekeeping...
	SFMLObject::Update();

	// Then anything else it needs to do?
}