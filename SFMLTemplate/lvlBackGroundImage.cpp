#include "lvlBackgroundImage.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"

lvlBackGroundImage::lvlBackGroundImage(float x, float y)
	: SFMLObject("lvlbackgroundImage", x, y, 1, 1)
{
	// Nothing here...
}

void lvlBackGroundImage::Update()
{
	// Housekeeping...
	SFMLObject::Update();

	// Then anything else it needs to do?
}