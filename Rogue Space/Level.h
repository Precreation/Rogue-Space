#pragma once
#include "Tile.h"
#include <iostream>

using namespace std;

class Level
{
private:
	// Class Declarations
	int _width, _height;	// The width and height of the level in Tiles
	Tile** _level;			// An array that stores the tile information of the level 

public:
	Level(int rows, int columns);		// Default Constructor
	~Level();							// Destructor

	void Draw(Window *window);			// A method that draws the level to the renderer
	Tile* GetTile(int row, int col);	// A method that retrieves a tile at the given row and column
};