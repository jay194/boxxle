#include <SFML/Graphics.hpp>
#include "SFMLKeyboard.h"

SFMLKeyboard * SFMLKeyboard::Instance = nullptr;

SFMLKeyboard * SFMLKeyboard::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLKeyboard();
	}

	return Instance;
}

SFMLKeyboard::~SFMLKeyboard()
{
	delete Instance;
}

void SFMLKeyboard::Update()
{
	Previous = Current;
	for (int i = 0; i < KEYS_TO_MONITOR; ++i)
	{
		Current[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
	}
}

SFMLKeyboard::SFMLKeyboard()
	: Current(KEYS_TO_MONITOR),
	  Previous(KEYS_TO_MONITOR)
{
	Update();
}

bool SFMLKeyboard::IsKeyPressed(sf::Keyboard::Key key)
{
	return (Previous[key] == false) && (Current[key] == true);
}

bool SFMLKeyboard::IsKeyDown(sf::Keyboard::Key key)
{
	return (Previous[key] == true) && (Current[key] == true);
}

bool SFMLKeyboard::IsKeyReleased(sf::Keyboard::Key key)
{
	return (Previous[key] == true) && (Current[key] == false);
}

bool SFMLKeyboard::IsKeyUp(sf::Keyboard::Key key)
{
	return (Previous[key] == false) && (Current[key] == false);
}