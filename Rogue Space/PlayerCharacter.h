#pragma once
#include "Character.h"

class PlayerCharacter : public Character, public EventHandler
{
private:
	// Class Declarations
	const int MOVEMENT_SPEED = 32;	// A constant that tells the speed the player can move

public:
	PlayerCharacter();				// Default Constructor
	~PlayerCharacter();				// Destructor

	void Draw(Window *window);						// A method that draws the object to the screen
	void EventHandle(SDL_Event event) override;		// A method that deals with subscribed events when triggered
};