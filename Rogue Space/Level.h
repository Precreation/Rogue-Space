#pragma once
#include "Tile.h"

template<int C, int R>
class Level 
{
private:
	Tile _level[R][C];

public:
	Level();
	
	void Draw(Window *window);
};