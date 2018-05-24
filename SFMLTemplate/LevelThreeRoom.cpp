#include "LevelThreeRoom.h"
#include "lvlBackGroundImage.h"
#include "SFMLTextureManager.h"
#include "Goal.h"
#include "Hero.h"
#include "Wall.h"
#include "Box.h"
#include "MainMenuRoom.h"
#include "SFMLButton.h"
#include "SFMLFont.h"

void MainMenuButtonPressed3(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new MainMenuRoom);
}

LevelThreeRoom::LevelThreeRoom()
{
	HighScore = SFMLGame::GetInstance()->GetHiScores()[2];
	SFMLGame::GetInstance()->prevlevel = 3;

	InstanceCreate(new lvlBackGroundImage(0, 0));

	InstanceCreate(new Hero(520, 280));

	InstanceCreate(new Goal(560, 360));
	InstanceCreate(new Goal(560, 320));
	InstanceCreate(new Goal(520, 320));
	InstanceCreate(new Goal(520, 360));

	InstanceCreate(new Box(720, 280));
	InstanceCreate(new Box(680, 320));
	InstanceCreate(new Box(600, 280));
	InstanceCreate(new Box(520, 240));

	InstanceCreate(new Wall(640, 240));
	InstanceCreate(new Wall(600, 240));
	InstanceCreate(new Wall(560, 240));
	InstanceCreate(new Wall(480, 240));
	InstanceCreate(new Wall(480, 200));
	InstanceCreate(new Wall(720, 200));
	InstanceCreate(new Wall(760, 200));
	InstanceCreate(new Wall(760, 320));
	InstanceCreate(new Wall(760, 360));
	InstanceCreate(new Wall(600, 320));
	InstanceCreate(new Wall(600, 360));
	InstanceCreate(new Wall(480, 360));
	InstanceCreate(new Wall(440, 360));
	InstanceCreate(new Wall(440, 320));
	InstanceCreate(new Wall(440, 280));
	InstanceCreate(new Wall(440, 240));
	InstanceCreate(new Wall(480, 400));
	InstanceCreate(new Wall(520, 400));
	InstanceCreate(new Wall(560, 400));
	InstanceCreate(new Wall(600, 400));
	InstanceCreate(new Wall(640, 400));
	InstanceCreate(new Wall(680, 400));
	InstanceCreate(new Wall(720, 400));
	InstanceCreate(new Wall(760, 400));
	InstanceCreate(new Wall(800, 320));
	InstanceCreate(new Wall(800, 280));
	InstanceCreate(new Wall(800, 240));
	InstanceCreate(new Wall(800, 200));
	InstanceCreate(new Wall(720, 160));
	InstanceCreate(new Wall(680, 160));
	InstanceCreate(new Wall(640, 160));
	InstanceCreate(new Wall(600, 160));
	InstanceCreate(new Wall(560, 160));
	InstanceCreate(new Wall(520, 160));
	InstanceCreate(new Wall(480, 160));

	InstanceCreate(new SFMLButton("mainmenubutton", 640, 580, MainMenuButtonPressed3));
}

void LevelThreeRoom::Draw()
{
	SFMLRoom::Draw();
	std::vector<SFMLObject *> heror = GetAllObjectsOfType<Hero*>();
	SFMLFont::GetInstance()->DrawText(800, 160, "STEPS : " + std::to_string(heror[0]->steps));

}

LevelThreeRoom::~LevelThreeRoom()
{
	std::vector<SFMLObject *> heror = GetAllObjectsOfType<Hero*>();
	if (heror[0]->steps < HighScore && heror[0]->steps >= 118)
	{
		SFMLGame::GetInstance()->SetHiScore(3, heror[0]->steps);
	}
}

