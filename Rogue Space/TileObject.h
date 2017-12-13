#pragma once
#include "RenderObject.h"

class TileObject : public RenderObject
{
public:
	// Class Declarations
	const int TILE_SIZE = 32;		// A constant that tells the size of all tiles	
	SDL_Rect _tileImage;			// The rectangle that is drawn to make up the tile

	void SetPosition(int xPosition, int yPosition)		// A method that sets the position of the tile
	{													// (Might be reworked for better tile intefration?)
		_tileImage.x = xPosition;
		_tileImage.y = yPosition;
	}
};