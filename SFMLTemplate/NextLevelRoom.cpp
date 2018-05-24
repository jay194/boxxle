#include "NextLevelRoom.h"
#include "MainMenuRoom.h"
#include "LevelTwoRoom.h"
#include "LevelThreeRoom.h"
#include "SFMLButton.h"
#include "NextBackGroundImage.h"

void MainMenuButtonPressed4(void * Button)
{
	SFMLGame::GetInstance()->ChangeCurrentRoom(new MainMenuRoom);
}
void NextLevelButtonPressed(void * Button)
{
	if (SFMLGame::GetInstance()->prevlevel == 1)
		SFMLGame::GetInstance()->ChangeCurrentRoom(new LevelTwoRoom);
	else if (SFMLGame::GetInstance()->prevlevel == 2)
		SFMLGame::GetInstance()->ChangeCurrentRoom(new LevelThreeRoom);
}
void quitgamebuttonPressed4(void * Button)
{
	SFMLGame::GetInstance()->GetWindow()->close();
}
NextLevelRoom::NextLevelRoom()
{
	InstanceCreate(new NextBackGroundImage(0, 0));
	InstanceCreate(new SFMLButton("mainmenubutton", 100, 490, MainMenuButtonPressed4));
	if(SFMLGame::GetInstance()->prevlevel != 3)
		InstanceCreate(new SFMLButton("nextlevelbutton", 500, 490, NextLevelButtonPressed));
	
	InstanceCreate(new SFMLButton("quitgamebutton", 900, 490, quitgamebuttonPressed4));
}

