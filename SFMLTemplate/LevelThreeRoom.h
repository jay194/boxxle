#pragma once
#include "SFMLRoom.h"
#include <SFML/Graphics.hpp>
class LevelThreeRoom : public SFMLRoom
{
public:
	LevelThreeRoom();
	virtual void Draw();
	~LevelThreeRoom();
private:
	int HighScore;
};

