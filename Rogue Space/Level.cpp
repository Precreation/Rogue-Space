#include "Level.h"

// Default Constructor
Level::Level(int rows, int columns)
{
	_width = rows;
	_height = columns;
	_level = new Tile*[_width];

	// Loops through the desired amount of rows for the level
	for (int row = 0; row < _width; row++)
	{
		// Create the number of columns that 
		_level[row] = new Tile[_height];
		for (int column = 0; column < _height; column++)
			// Set the position of the tile
			_level[row][column].SetPosition(column * 32, row * 32);
	}
}

// Destructor
Level::~Level()
{
	delete[] _level;
}

// A method that draws the level to the renderer
void Level::Draw(Window *window)
{
	// Draw the level tiles
	for (int row = 0; row < _width; row++)
		for (int column = 0; column < _height; column++)
			_level[row][column].Draw(window);

	// Draw the tile contents
	for (int row = 0; row < _width; row++)
		for (int column = 0; column < _height; column++)
			if (_level[row][column].GetContents() != nullptr)
				_level[row][column].GetContents()->Draw(window);
}

// A method that retrieves a tile at the given row and column
Tile* Level::GetTile(int row, int col)
{
	return &_level[row][col];
}

