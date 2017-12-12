#pragma once
#include <SDL.h>
#include "RenderObject.h"
#include "TileObject.h"

class Tile : public TileObject
{
private:
	// Class Declarations
	int _redValue, _blueValue, _greenValue;
	TileObject* _contents;

public:
	Tile();
	~Tile();
	void Draw(Window *window);

	TileObject* GetContents();
	void SetContents(TileObject* content);
};