#include "SFMLTextureManager.h"

SFMLTextureManager * SFMLTextureManager::Instance = nullptr;

SFMLTextureManager::SFMLTextureManager()
	: Textures()
{
	// Nothing here...
}

SFMLTextureManager * SFMLTextureManager::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new SFMLTextureManager();
	}

	return Instance;
}

void SFMLTextureManager::LoadTexture(const std::string & resourceName,
	                                 const std::string & fileName)
{
	std::map<std::string, sf::Texture *>::iterator iter = Textures.find(resourceName);
	if (iter != Textures.end())
	{
		delete iter->second;
	}

	sf::Texture * Texture = new sf::Texture();
	Texture->loadFromFile(fileName);
	Textures[resourceName] = Texture;
}

sf::Texture * SFMLTextureManager::GetTexture(const std::string & resourceName)
{
	return Textures[resourceName];
}

SFMLTextureManager::~SFMLTextureManager()
{
	delete Instance;
}