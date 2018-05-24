#include "NextBackGroundImage.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"

NextBackGroundImage::NextBackGroundImage(float x, float y)
	: SFMLObject("nextbackgroundImage", x, y, 1, 1)
{
	// Nothing here...
}

void NextBackGroundImage::Update()
{
	// Housekeeping...
	SFMLObject::Update();

	// Then anything else it needs to do?
}