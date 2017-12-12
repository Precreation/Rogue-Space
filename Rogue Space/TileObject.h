#pragma once
#include "RenderObject.h"

class TileObject : public RenderObject
{
public:
	const int TILE_SIZE = 32;
	SDL_Rect _image;

	void SetPosition(int xPosition, int yPosition)
	{
		_image.x = xPosition;
		_image.y = yPosition;
	}
};