#include "Box.h"
#include "SFMLObject.h"

Box::Box(float x, float y)
	: Wall("Box", x, y)
{
	this->SetDepth(3);
}

void Box::Update()
{
	SFMLObject::Update();
}


Box::~Box()
{
}
