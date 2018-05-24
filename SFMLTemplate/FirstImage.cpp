#include "FirstImage.h"
#include "SFMLGame.h"
#include "SFMLKeyboard.h"

FirstImage::FirstImage(float x, float y)
	: SFMLObject("COOKIE", x, y, 1, 1)
{
	// Nothing here...
}

void FirstImage::Update()
{
	// Housekeeping...
	SFMLObject::Update();

	// Then anything else it needs to do?
}