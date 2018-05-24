#include "LevelOneRoom.h"
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

void MainMenuButtonPressed(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new MainMenuRoom);
}

LevelOneRoom::LevelOneRoom()
{

	HighScore = SFMLGame::GetInstance()->GetHiScores()[0];
	SFMLGame::GetInstance()->prevlevel = 1;

	InstanceCreate(new lvlBackGroundImage(0, 0));

	InstanceCreate(new Goal(680, 320));
	InstanceCreate(new Goal(680, 360));
	InstanceCreate(new Goal(680, 280));

	InstanceCreate(new Box(520, 240));
	InstanceCreate(new Box(480, 240));
	InstanceCreate(new Box(480, 280));

	InstanceCreate(new Hero(440, 200));

	InstanceCreate(new Wall(440, 440));
	InstanceCreate(new Wall(440, 400));
	InstanceCreate(new Wall(440, 360));
	InstanceCreate(new Wall(480, 360));
	InstanceCreate(new Wall(480, 320));
	InstanceCreate(new Wall(440, 320));
	InstanceCreate(new Wall(400, 320));
	InstanceCreate(new Wall(400, 280));
	InstanceCreate(new Wall(400, 240));
	InstanceCreate(new Wall(400, 200));
	InstanceCreate(new Wall(440, 480));
	InstanceCreate(new Wall(480, 480));
	InstanceCreate(new Wall(520, 480));
	InstanceCreate(new Wall(560, 480));
	InstanceCreate(new Wall(600, 480));
	InstanceCreate(new Wall(600, 400));
	InstanceCreate(new Wall(600, 440));
	InstanceCreate(new Wall(640, 440));
	InstanceCreate(new Wall(680, 440));
	InstanceCreate(new Wall(720, 440));
	InstanceCreate(new Wall(720, 400));
	InstanceCreate(new Wall(720, 360));
	InstanceCreate(new Wall(720, 320));
	InstanceCreate(new Wall(720, 280));
	InstanceCreate(new Wall(720, 240));
	InstanceCreate(new Wall(680, 240));
	InstanceCreate(new Wall(640, 240));
	InstanceCreate(new Wall(640, 280));
	InstanceCreate(new Wall(640, 320));
	InstanceCreate(new Wall(600, 320));
	InstanceCreate(new Wall(560, 320));
	InstanceCreate(new Wall(560, 280));
	InstanceCreate(new Wall(560, 240));
	InstanceCreate(new Wall(560, 200));
	InstanceCreate(new Wall(560, 160));
	InstanceCreate(new Wall(520, 160));
	InstanceCreate(new Wall(480, 160));
	InstanceCreate(new Wall(440, 160));
	InstanceCreate(new Wall(400, 160));

	InstanceCreate(new SFMLButton("mainmenubutton", 640, 580, MainMenuButtonPressed));

}

void LevelOneRoom::Draw()
{
	SFMLRoom::Draw();
	std::vector<SFMLObject *> heror = GetAllObjectsOfType<Hero*>();
	SFMLFont::GetInstance()->DrawText( 800 ,160, "STEPS : " + std::to_string(heror[0]->steps));
}

LevelOneRoom::~LevelOneRoom()
{
	std::vector<SFMLObject *> heror = GetAllObjectsOfType<Hero*>();
	if (heror[0]->steps < HighScore && heror[0]->steps >= 93)
	{
		SFMLGame::GetInstance()->SetHiScore(1, heror[0]->steps);
	}
}
