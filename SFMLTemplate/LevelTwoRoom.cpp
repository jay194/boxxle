#include "LevelTwoRoom.h"
#include "lvlBackGroundImage.h"
#include "FirstImage.h"
#include "SFMLTextureManager.h"
#include "Goal.h"
#include "Hero.h"
#include "Wall.h"
#include "Box.h"
#include "MainMenuRoom.h"
#include "SFMLButton.h"
#include "SFMLFont.h"

void MainMenuButtonPressed2(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new MainMenuRoom);
}

LevelTwoRoom::LevelTwoRoom()
{
	HighScore = SFMLGame::GetInstance()->GetHiScores()[1];
	SFMLGame::GetInstance()->prevlevel = 2;

	InstanceCreate(new lvlBackGroundImage(0, 0));

	InstanceCreate(new Box(640, 400));
	InstanceCreate(new Box(520, 360));
	InstanceCreate(new Box(560, 240));

	InstanceCreate(new Goal(480, 400));
	InstanceCreate(new Goal(480, 360));
	InstanceCreate(new Goal(480, 320));

	InstanceCreate(new Hero(520, 200));

	InstanceCreate(new Wall(720, 400));
	InstanceCreate(new Wall(720, 360));
	InstanceCreate(new Wall(720, 320));
	InstanceCreate(new Wall(720, 280));
	InstanceCreate(new Wall(680, 280));
	InstanceCreate(new Wall(680, 240));
	InstanceCreate(new Wall(480, 440));
	InstanceCreate(new Wall(440, 440));
	InstanceCreate(new Wall(440, 400));
	InstanceCreate(new Wall(440, 360));
	InstanceCreate(new Wall(440, 320));
	InstanceCreate(new Wall(440, 280));
	InstanceCreate(new Wall(480, 280));
	InstanceCreate(new Wall(520, 280));
	InstanceCreate(new Wall(520, 320));
	InstanceCreate(new Wall(640, 360));
	InstanceCreate(new Wall(600, 320));
	InstanceCreate(new Wall(600, 280));
	InstanceCreate(new Wall(520, 440));
	InstanceCreate(new Wall(560, 440));
	InstanceCreate(new Wall(600, 440));
	InstanceCreate(new Wall(640, 440));
	InstanceCreate(new Wall(680, 440));
	InstanceCreate(new Wall(720, 440));
	InstanceCreate(new Wall(680, 200));
	InstanceCreate(new Wall(640, 200));
	InstanceCreate(new Wall(600, 200));
	InstanceCreate(new Wall(480, 240));
	InstanceCreate(new Wall(480, 200));
	InstanceCreate(new Wall(600, 160));
	InstanceCreate(new Wall(640, 160));
	InstanceCreate(new Wall(560, 160));
	InstanceCreate(new Wall(520, 160));
	InstanceCreate(new Wall(480, 160));

	InstanceCreate(new SFMLButton("mainmenubutton", 640, 580, MainMenuButtonPressed2));
}

void LevelTwoRoom::Draw()
{
	SFMLRoom::Draw();
	std::vector<SFMLObject *> heror = GetAllObjectsOfType<Hero*>();
	SFMLFont::GetInstance()->DrawText(800, 160, "STEPS : " + std::to_string(heror[0]->steps));
}

LevelTwoRoom::~LevelTwoRoom()
{
	std::vector<SFMLObject *> heror = GetAllObjectsOfType<Hero*>();
	if (heror[0]->steps < HighScore && heror[0]->steps >= 51)
	{
		SFMLGame::GetInstance()->SetHiScore(2, heror[0]->steps);
	}
}

