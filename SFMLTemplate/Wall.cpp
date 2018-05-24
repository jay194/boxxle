#include "Wall.h"

Wall::Wall(float x, float y)
	: SFMLObject("Wall", x, y, 1, 1)
{

}

Wall::Wall(const std::string & resourceName, float x, float y)
	: SFMLObject(resourceName, x, y)
{
}

void Wall::Update()
{
	SFMLObject::Update();
}


Wall::~Wall()
{
}
