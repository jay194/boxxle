#pragma once

#include <SFML/Graphics.hpp>

// Includes and class declarations
class sf::RenderWindow;
class SFMLRoom;

class SFMLGame
{
public:
	// Runs the entire game
	void Run(SFMLRoom * FirstRoom);

	// Screen resolution functionality
	void SetScreenResolution(int Width, int Height);

	// Fullscreen functionality
	// See sf::Style for sfStyleStatus options
	void SetWindowStyle(int sfStyleStatus);
	bool GetWindowFullScreenStatus();
	bool GetWindowTitlebarStatus();

	// Frame rate functionality
	int  GetFrameRate();
	void SetFrameRate(int FramesPerSecond);

	// Mouse cursor visibility functionality
	bool GetVisibleMouseCursorStatus();
	void SetVisibleMouseCursorStatus(bool Status);

	// Title bar text functionality
	sf::String SFMLGame::GetWindowTitleBar();
	void       SFMLGame::SetWindowTitleBar(const sf::String & TitleBarText);

	// Render window 
	sf::RenderWindow * GetWindow();

	// Gets singleton instance
	static SFMLGame * GetInstance();

	SFMLRoom * GetCurrentRoom();
	void ChangeCurrentRoom(SFMLRoom * NextRoom);

	//get hiscores
	std::vector<int> GetHiScores();
	void SetHiScore(int lvl, int value);
	int prevlevel = 0;
private:
	// Constructor
	SFMLGame();

	// Destructor
	virtual ~SFMLGame();

	// Handle window close events
	void HandleEvents();

	// Singleton instance
	static SFMLGame * Instance;

	// Render window
	sf::RenderWindow * Window;
	
	// Frame rate (Game frames per second)
	sf::Time FrameRate;
	
	SFMLRoom * CurrentRoom;
	SFMLRoom * NextRoom;

	// Full screen status
	static int WindowStyleStatus;

	// Mouse cursor status
	static bool VisibleMouseCursor;

	// Render window width
	static int WindowWidth;

	// Render window height
	static int WindowHeight;

	// Render window title bar
	static sf::String WindowTitleBar;

	// hiscores file
	const std::string HISCORES_FILE = "data.txt";

	void LoadHiscores(const std::string & name);
	void SaveHiscores(const std::string & name);
	std::vector<int> HISCORES;
};