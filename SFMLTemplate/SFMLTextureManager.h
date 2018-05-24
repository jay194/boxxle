#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class SFMLTextureManager
{
public:
	static SFMLTextureManager * GetInstance();

	~SFMLTextureManager();

	void LoadTexture(const std::string & resourceName,
		             const std::string & fileName);

	sf::Texture * GetTexture(const std::string & resourceName);

private:
	SFMLTextureManager();

	static SFMLTextureManager * Instance;

	std::map<std::string, sf::Texture *> Textures;
};