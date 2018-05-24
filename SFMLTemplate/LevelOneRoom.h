#pragma once

#include <SFML/Graphics.hpp>
#include "SFMLRoom.h"

class LevelOneRoom : public SFMLRoom
{
public:
	LevelOneRoom();
	virtual void Draw();
	~LevelOneRoom();
private:
	int HighScore;
};

