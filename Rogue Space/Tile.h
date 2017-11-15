#pragma once
#include <SDL.h>
#include "Window.h"

class Tile
{
private:
	// Constants
	const int TILE_SIZE = 32;

	// Class Declarations
	int _redValue, _blueValue, _greenValue;
	SDL_Rect _tile;

public:
	Tile();

	void Draw(Window *window);
	void SetPosition(int xPosition, int yPosition);
};