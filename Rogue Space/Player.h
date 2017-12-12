#pragma once
#include "Character.h"

class Player : public Character, public EventHandler
{
private:

public:
	Player();
	~Player();

	void Draw(Window *window);
	void EventHandle(SDL_Event event) override;
};