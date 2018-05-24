#pragma once
#include <SFML/Graphics.hpp>
#include "SFMLRoom.h"
class LevelTwoRoom : public SFMLRoom
{
public:
	LevelTwoRoom();
	virtual void Draw();
	~LevelTwoRoom();
private:
	int HighScore;
};

