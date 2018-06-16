#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLGame.h"
#include "SFMLKeyboard.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
#include <fstream>

// ----------------------------------------------------
// Default/Starting game window and resolution settings
// ----------------------------------------------------
int        SFMLGame::WindowWidth        = 1280;
int        SFMLGame::WindowHeight       = 720;
int        SFMLGame::WindowStyleStatus  = sf::Style::Resize;
bool       SFMLGame::VisibleMouseCursor = true;
sf::String SFMLGame::WindowTitleBar     = "shit game";

// Singleton static initializtion
SFMLGame * SFMLGame::Instance           = nullptr;

bool SFMLGame::GetWindowFullScreenStatus()
{
	return (WindowStyleStatus &= sf::Style::Fullscreen) > 0;
}

bool SFMLGame::GetWindowTitlebarStatus()
{
	return (WindowStyleStatus &= sf::Style::Titlebar) > 0;
}

// NOTE:  You must see sf::Style for your available options
void SFMLGame::SetWindowStyle(int sfStyleStatus)
{
	if (sfStyleStatus != WindowStyleStatus)
	{
		WindowStyleStatus = sfStyleStatus;
		SetScreenResolution(WindowWidth, WindowHeight);
	}
}

void SFMLGame::SetScreenResolution(int Width, int Height)
{
	WindowWidth = Width;
	WindowHeight = Height;
	Window->create(sf::VideoMode(WindowWidth, WindowHeight), WindowTitleBar, WindowStyleStatus);
}

sf::String SFMLGame::GetWindowTitleBar()
{
	return WindowTitleBar;
}

void SFMLGame::SetWindowTitleBar(const sf::String & TitleBarText)
{
	WindowTitleBar = TitleBarText;
	Window->setTitle(WindowTitleBar);
}

sf::Vector2i SFMLGame::GetWindowPosition()
{
	return Window->getPosition();
}




bool SFMLGame::GetVisibleMouseCursorStatus()
{
	return VisibleMouseCursor;
}

void SFMLGame::SetVisibleMouseCursorStatus(bool Status)
{
	VisibleMouseCursor = Status;
	Window->setMouseCursorVisible(VisibleMouseCursor);
}

void SFMLGame::SetFrameRate(int FramesPerSecond)
{
	FrameRate = sf::microseconds(1000000 / FramesPerSecond);
}

int SFMLGame::GetFrameRate()
{
	return static_cast<int>(1000000 / FrameRate.asMicroseconds());
}

void SFMLGame::Run(SFMLRoom * FirstRoom)
{
	// Set the room
	assert(FirstRoom != nullptr);
	delete CurrentRoom;
	CurrentRoom = FirstRoom;

	sf::Clock Clock;
	sf::Time ElapsedTime = sf::Time::Zero;
	
	while (Window->isOpen())
	{
		if (NextRoom != nullptr)
		{
			delete CurrentRoom;
			CurrentRoom = NextRoom;
			NextRoom = nullptr;
		}

		ElapsedTime += Clock.restart();
		
		if (ElapsedTime > FrameRate)
		{
			ElapsedTime = sf::Time::Zero;
			SFMLKeyboard::GetInstance()->Update();
			SFMLMouse::GetInstance()->Update();
			CurrentRoom->Update();
		}

		Window->clear();
		CurrentRoom->Draw();
		Window->display();

		HandleEvents();
	}
}

SFMLGame::SFMLGame()
	: Window(new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), WindowTitleBar, WindowStyleStatus)),
	  FrameRate(sf::microseconds(16666)),
	  CurrentRoom(nullptr),
	  NextRoom(nullptr)
{
	Window->setMouseCursorVisible(VisibleMouseCursor);
	LoadHiscores(HISCORES_FILE);
}

SFMLGame::~SFMLGame()
{
	delete Window;
	delete Instance;
}

SFMLGame * SFMLGame::GetInstance()
{
	if (nullptr == Instance)
	{
		Instance = new SFMLGame();
	}

	return Instance;
}

void SFMLGame::HandleEvents()
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window->close();
		}
		else if (event.type == sf::Event::Resized)
		{
			SetScreenResolution(1280, 720);
		}
	}
}
// load hiscores
void SFMLGame::LoadHiscores(const std::string & name)
{
	std::fstream file(name);
	int n;
	while (file.eof() == false)
	{
		file >> n;
		HISCORES.push_back(n);
	}
}

void SFMLGame::SaveHiscores(const std::string & name)
{
	//writes to file from player vector
	std::fstream file(name);
	for (int i = 0; i <= 2; ++i)
	{
		file << HISCORES[i] << std::endl;
	}
}

sf::RenderWindow * SFMLGame::GetWindow()
{
	return Window;
}

SFMLRoom * SFMLGame::GetCurrentRoom()
{
	return CurrentRoom;
}

void SFMLGame::ChangeCurrentRoom(SFMLRoom * nextRoom)
{
	if (NextRoom != nullptr)
	{
		delete NextRoom;
	}
	NextRoom = nextRoom;
}

std::vector<int> SFMLGame::GetHiScores()
{
	std::vector<int> Vectorz;
	for (int t : HISCORES)
	{
		Vectorz.push_back(t);
	}
	return Vectorz;
}

void SFMLGame::SetHiScore(int lvl, int value)
{
	HISCORES[lvl-1] = value;
	SaveHiscores("data.txt");
}
