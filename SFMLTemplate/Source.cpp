#include <SFML/Graphics.hpp>
#include "SFMLGame.h"
#include "MainMenuRoom.h"
#include "TestRoom.h"
#include "SFMLTextureManager.h"

// Boxxle thing
// Jay Patel
// Game Programming C++
// Spring 2017

int main()
{

	SFMLTextureManager::GetInstance()->LoadTexture("COOKIE", "Cookie.png");
	SFMLTextureManager::GetInstance()->LoadTexture("guy", "guy.jpg");
	SFMLTextureManager::GetInstance()->LoadTexture("tileset", "tileset.gif");
	SFMLTextureManager::GetInstance()->LoadTexture("nethack", "nethack.gif");
	//backgrounds
	SFMLTextureManager::GetInstance()->LoadTexture("backgroundImage", "backgroundImage.jpg");
	SFMLTextureManager::GetInstance()->LoadTexture("lvlbackgroundImage", "lvlbackgroundImage.jpg");
	SFMLTextureManager::GetInstance()->LoadTexture("nextbackgroundImage", "nextbackgroundImage.jpg");
	// buttons
	SFMLTextureManager::GetInstance()->LoadTexture("quitgamebutton", "QuitGameButtonImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("levelonebutton", "LevelOneButtonImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("leveltwobutton", "LevelTwoButtonImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("levelthreebutton", "LevelThreeButtonImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("mainmenubutton", "MainMenuButtonImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("nextlevelbutton", "NextLevelButtonImage.png");
	//game objects
	SFMLTextureManager::GetInstance()->LoadTexture("Goal", "GoalImage.png");

	SFMLTextureManager::GetInstance()->LoadTexture("Hero", "HeroImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Right", "hero_right.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Left", "hero_left.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Up", "hero_up.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Down", "hero_down.png");

	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Right_Box", "hero_right_box.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Left_Box", "hero_left_box.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Up_Box", "hero_up_box.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Hero_Down_Box", "hero_down_box.png");

	SFMLTextureManager::GetInstance()->LoadTexture("Wall", "WallImage.png");
	SFMLTextureManager::GetInstance()->LoadTexture("Box", "BoxImage.png");

	SFMLGame::GetInstance()->Run(new MainMenuRoom());
	return 0;
}