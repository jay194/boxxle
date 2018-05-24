#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "SFMLObject.h"

class SFMLButton : public SFMLObject
{
public:
	SFMLButton(const std::string & resourceName, 
		       float x,
		       float y,
		       void(*CallbackFunction)(void * Room));

	virtual ~SFMLButton();

	virtual void Update();

private:
	void(*Callback)(void *);
};