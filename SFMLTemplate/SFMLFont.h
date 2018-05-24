#pragma once

#include <string>
#include "SFMLObject.h"

class SFMLFont : SFMLObject
{
public:
	static SFMLFont * GetInstance();

	void SFMLFont::DrawText(int X,
		int Y,
		const std::string & TEXT,
		const sf::Color & COLOR = sf::Color::White);

	virtual void Update();
	virtual void Draw();

private:
	SFMLFont();

	static SFMLFont * Instance;
};
