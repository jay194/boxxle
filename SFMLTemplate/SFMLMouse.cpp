#include <SFML/Graphics.hpp>
#include "SFMLMouse.h"

SFMLMouse * SFMLMouse::Instance = nullptr;

SFMLMouse::SFMLMouse()
	: CurrentMousePresses(BUTTONS_TO_MONITOR),
	  PreviousMousePresses(BUTTONS_TO_MONITOR)
{
	Update();
}

SFMLMouse::~SFMLMouse()
{
	delete Instance;
}

void SFMLMouse::Update()
{
	// Position
	PreviousPosition = CurrentPosition;
	CurrentPosition = sf::Mouse::getPosition();

	// Mouse presses
	PreviousMousePresses = CurrentMousePresses;
	for (int i = 0; i < BUTTONS_TO_MONITOR; ++i)
	{
		CurrentMousePresses[i] = 
			sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(i));
	}
}

void SFMLMouse::SetPosition(int X, int Y)
{
	SetPosition(sf::Vector2i(X, Y));
}

void SFMLMouse::SetPosition(const sf::Vector2i & POSITION)
{
	sf::Mouse::setPosition(POSITION);
	CurrentPosition = POSITION;
}

sf::Vector2i SFMLMouse::GetPosition()
{
	return CurrentPosition;
}

int SFMLMouse::GetPositionX()
{
	return CurrentPosition.x;
}

int SFMLMouse::GetPositionY()
{
	return CurrentPosition.y;
}

sf::Vector2i SFMLMouse::GetPositionDifference()
{
	return CurrentPosition - PreviousPosition;
}

bool SFMLMouse::IsButtonPressed(sf::Mouse::Button button)
{
	return (CurrentMousePresses[button] == true) &&
		(PreviousMousePresses[button] == false);
}

// Every game frame AFTER the key was first pressed
bool SFMLMouse::IsButtonDown(sf::Mouse::Button button)
{
	return (CurrentMousePresses[button] == true) &&
		(PreviousMousePresses[button] == true);
}

// ONLY the game frame the key was first released
bool SFMLMouse::IsButtonReleased(sf::Mouse::Button button)
{
	return (CurrentMousePresses[button] == false) &&
		(PreviousMousePresses[button] == true);
}

// Every game frame AFTER the key was first released
bool SFMLMouse::IsButtonUp(sf::Mouse::Button button)
{
	return (CurrentMousePresses[button] == false) &&
		(PreviousMousePresses[button] == false);
}

SFMLMouse * SFMLMouse::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLMouse();
	}

	return Instance;
}