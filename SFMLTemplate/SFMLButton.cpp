#include "SFMLButton.h"
#include "SFMLMouse.h"

SFMLButton::SFMLButton(const std::string & resourceName,
	                   float x,
	                   float y,
	                   void(*CallbackFunction)(void * Room))
	: SFMLObject(resourceName, x, y, 2, 1),
	  Callback(CallbackFunction)
{
	// Nothing here...
}

SFMLButton::~SFMLButton()
{

}

void SFMLButton::Update()
{
	SetImageIndex(0);
	sf::Vector2i Position = SFMLMouse::GetInstance()->GetPosition();
	//fix window resize on the button
	sf::Vector2i WinPos = SFMLGame::GetInstance()->GetWindowPosition();
	float Left = GetSprite()->getPosition().x + WinPos.x + 10;
	float Top = GetSprite()->getPosition().y + WinPos.y + 40;
	float Right = Left + (GetSprite()->getTexture()->getSize().x / 2);
	float Bottom = Top + GetSprite()->getTexture()->getSize().y;
	if ((Position.x >= Left) && (Position.y >= Top) && (Position.x < Right) && (Position.y < Bottom))
	{
		SetImageIndex(1);
		if (SFMLMouse::GetInstance()->IsButtonPressed(sf::Mouse::Left))
		{
			Callback(this);
		}
	}
}