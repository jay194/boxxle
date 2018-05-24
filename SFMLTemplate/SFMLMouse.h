#pragma once

// Include files
#include <vector>

class SFMLMouse
{
public:
	// Update positioning and buttons
	void Update();
	
	// Gets singleton instance
	static SFMLMouse * GetInstance();

	// ONLY the game frame the button was first pressed
	bool IsButtonPressed(sf::Mouse::Button button);

	// Every game frame AFTER the button was first pressed
	bool IsButtonDown(sf::Mouse::Button button);

	// ONLY the game frame the button was first released
	bool IsButtonReleased(sf::Mouse::Button button);

	// Every game frame AFTER the button was first released
	bool IsButtonUp(sf::Mouse::Button button);

	// Set mouse position
	void SetPosition(int X, int Y);
	void SetPosition(const sf::Vector2i & POSITION);

	// Get mouse position
	sf::Vector2i GetPosition();
	int GetPositionX();
	int GetPositionY();

	// How much did the mouse move in one game frame
	sf::Vector2i GetPositionDifference();

private:
	// Constructor
	SFMLMouse();

	// Destructor 
	~SFMLMouse();

	// Singleton instance
	static SFMLMouse * Instance;

	// Positioning
	sf::Vector2i CurrentPosition;
	sf::Vector2i PreviousPosition;

	// If the mouse changes one day so does this number
	const static int BUTTONS_TO_MONITOR = 5;

	// Maintain previous and current status of each button
	std::vector<bool> CurrentMousePresses;
	std::vector<bool> PreviousMousePresses;
};