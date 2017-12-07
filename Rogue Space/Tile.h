#pragma once
#include <SDL.h>
#include "RenderObject.h"
#include "TileObject.h"

class Tile : RenderObject
{
private:
	// Constants
	const int TILE_SIZE = 32;

	// Class Declarations
	int _redValue, _blueValue, _greenValue;
	SDL_Rect _tile;
	TileObject** _contents;

public:
	Tile();
	~Tile();
	void Draw(Window *window);
	void SetPosition(int xPosition, int yPosition);
};