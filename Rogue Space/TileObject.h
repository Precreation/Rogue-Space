#pragma once
#include "RenderObject.h"

class TileObject : public RenderObject
{
public:
	const int TILE_SIZE = 32;
	SDL_Rect _tileImage;

	void SetPosition(int xPosition, int yPosition)
	{
		_tileImage.x = xPosition;
		_tileImage.y = yPosition;
	}
};