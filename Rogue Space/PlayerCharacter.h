#pragma once
#include "Character.h"

class PlayerCharacter : public Character, public EventHandler
{
private:
	const int MOVEMENT_SPEED = 32;
public:
	PlayerCharacter();
	~PlayerCharacter();

	void Draw(Window *window);
	void EventHandle(SDL_Event event) override;
};