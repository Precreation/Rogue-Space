#pragma once
#include "Character.h"

class Player : public Character
{
private:
	SDL_Rect _player;

public:
	Player();
	~Player();

	void Draw(Window *window);
};