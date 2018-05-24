#include "SFMLFont.h"
#include "SFMLTextureManager.h"

SFMLFont * SFMLFont::Instance = nullptr;

SFMLFont::SFMLFont()
	: SFMLObject("Font", 0, 0, 16, 16)
{
	// Nothing here...
}

SFMLFont * SFMLFont::GetInstance()
{
	if (Instance == nullptr)
	{
		SFMLTextureManager::GetInstance()->LoadTexture("Font", "font.png");
		Instance = new SFMLFont();
	}

	return Instance;
}

void SFMLFont::Update()
{
	// Do nothing...
}

void SFMLFont::Draw()
{
	// Do nothing...
}

void SFMLFont::DrawText(int X, int Y, const std::string & TEXT, const sf::Color & COLOR)
{
	SetX(X);
	SetY(Y);
	SetImageBlend(COLOR.r, COLOR.g, COLOR.b, COLOR.a);
	for (char CHARACTER : TEXT)
	{
		SetImageIndex(CHARACTER);
		SFMLObject::Draw();
		SetX(GetX() + GetSpriteWidth());
	}
}