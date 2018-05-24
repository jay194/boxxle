#include "Goal.h"

Goal::Goal(float x, float y)
	: SFMLObject("Goal", x, y, 1, 1)
{
	this->SetDepth(1);
}

void Goal::Update()
{
	SFMLObject::Update();
}


Goal::~Goal()
{
}
