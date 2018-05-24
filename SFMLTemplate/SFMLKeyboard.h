#pragma once

// Include files
#include <vector>

class SFMLKeyboard
{
public:
	// ONLY the game frame the key was first pressed
	bool IsKeyPressed(sf::Keyboard::Key key);

	// Every game frame AFTER the key was first pressed
	bool IsKeyDown(sf::Keyboard::Key key);

	// ONLY the game frame the key was first released
	bool IsKeyReleased(sf::Keyboard::Key key);

	// Every game frame AFTER the key was first released
	bool IsKeyUp(sf::Keyboard::Key key);

	// Update keyboard status - It's automatic
	void Update();

	// Gets singleton instance
	static SFMLKeyboard * GetInstance();
	
private:
	// Constructor
	SFMLKeyboard();

	// Destructor 
	~SFMLKeyboard();
	
	// Singleton instance
	static SFMLKeyboard * Instance;

	// If the keyboard changes one day so does this number
	const static int KEYS_TO_MONITOR = 105;

	// Maintain previous and current status of each key
	std::vector<bool> Current;
	std::vector<bool> Previous;
};