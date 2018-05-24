#include "FirstImage.h"
#include "SFMLButton.h"
#include "SFMLTextureManager.h"
#include "TestRoom.h"
/*
void QuitGameButtonPressed(void * Button)
{
	SFMLButton * b = reinterpret_cast<SFMLButton *>(Button);
}
*/
TestRoom::TestRoom()
	: SFMLRoom()
{
	/*
	SFMLTextureManager::GetInstance()->LoadTexture("COOKIE", "Cookie.png");
	SFMLTextureManager::GetInstance()->LoadTexture("guy", "guy.jpg");
	SFMLTextureManager::GetInstance()->LoadTexture("tileset", "tileset.gif");
	SFMLTextureManager::GetInstance()->LoadTexture("nethack", "nethack.gif");
	SFMLTextureManager::GetInstance()->LoadTexture("quitgamebutton", "QuitGameButtonImage.png");

	FirstImage * Object = new FirstImage(0, 400);
	Object->SetHSpeed(5);
	Object->SetFriction(0.02f);
	InstanceCreate(Object);

	SFMLButton * button = new SFMLButton("quitgamebutton", 0, 0, QuitGameButtonPressed);
	InstanceCreate(button);
	*/
}
