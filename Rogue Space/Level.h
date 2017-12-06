#pragma once
#include "Tile.h"

template<int R, int C>
class Level 
{
private:
	Tile (*_level)[C];

public:
	Level();
	~Level();

	void Draw(Window *window);
};