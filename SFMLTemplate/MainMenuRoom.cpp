#include "FirstImage.h"
#include "BackGroundImage.h"
#include "SFMLButton.h"
#include "SFMLGame.h"
#include "SFMLTextureManager.h"
#include "MainMenuRoom.h"
#include "LevelOneRoom.h"
#include "LevelTwoRoom.h"
#include "LevelThreeRoom.h"
#include "Box.h"
#include "Goal.h"
#include <string>
#include "SFMLFont.h"

void QuitGameButtonPressed(void * Button)
{
	SFMLGame::GetInstance()->GetWindow()->close();
}

void LevelOneButtonPressed(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new LevelOneRoom);
}

void LevelTwoButtonPressed(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new LevelTwoRoom);
}

void LevelThreeButtonPressed(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new LevelThreeRoom);
}

MainMenuRoom::MainMenuRoom()
	: SFMLRoom()
{
	InstanceCreate(new BackGroundImage(0, 0));

	InstanceCreate(new SFMLButton("quitgamebutton", 500, 600, QuitGameButtonPressed));

	InstanceCreate(new SFMLButton("levelonebutton", 100, 490, LevelOneButtonPressed));

	InstanceCreate(new SFMLButton("leveltwobutton", 500, 490, LevelTwoButtonPressed));

	InstanceCreate(new SFMLButton("levelthreebutton", 900, 490, LevelThreeButtonPressed));

}

void MainMenuRoom::Draw()
{
	SFMLRoom::Draw();

	SFMLFont::GetInstance()->DrawText(150, 570, "STEPS : " + std::to_string(SFMLGame::GetInstance()->GetHiScores()[0]));
	SFMLFont::GetInstance()->DrawText(550, 570, "STEPS : " + std::to_string(SFMLGame::GetInstance()->GetHiScores()[1]));
	SFMLFont::GetInstance()->DrawText(950, 570, "STEPS : " + std::to_string(SFMLGame::GetInstance()->GetHiScores()[2]));

}
