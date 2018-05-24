#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class SFMLObject;

class SFMLRoom
{
public:
	SFMLRoom();
	virtual ~SFMLRoom();

	virtual void Update();
	virtual void Draw();

	void InstanceCreate(SFMLObject * Instance);

	template<typename T>
	bool PlaceMeeting(SFMLObject * TestObject, const sf::Rect<float> & Box);

	template<typename T>
	SFMLObject * InstancePlace(SFMLObject * TestObject, const sf::Rect<float> & Box);

	template<typename T>
	std::vector<SFMLObject *> GetAllObjectsOfType();

private:
	std::vector<SFMLObject *> Objects;
};

template<typename T>
bool SFMLRoom::PlaceMeeting(SFMLObject * TestObject, const sf::Rect<float> & Box)
{
	for (SFMLObject * Object : Objects)
	{
		if (Object != TestObject)
		{
			if (dynamic_cast<T>(Object) != nullptr)
			{
				if (Box.intersects(Object->GetBoundingBox()))
				{
					return true;
				}
			}
		}
	}
	return false;
}

template<typename T>
SFMLObject * SFMLRoom::InstancePlace(SFMLObject * TestObject, const sf::Rect<float> & Box)
{
	for (SFMLObject * Object : Objects)
	{
		if (Object != TestObject)
		{
			if (dynamic_cast<T>(Object) != nullptr)
			{
				if (Box.intersects(Object->GetBoundingBox()))
				{
					return Object;
				}
			}
		}
	}
	return nullptr;
}

template<typename T>
std::vector<SFMLObject *> SFMLRoom::GetAllObjectsOfType()
{
	std::vector<SFMLObject *> Vector;

	for (SFMLObject * Object : Objects)
	{
		if (dynamic_cast<T>(Object) != nullptr)
		{
			Vector.push_back(Object);
		}
	}
	return Vector;
}