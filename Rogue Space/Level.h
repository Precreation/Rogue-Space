#pragma once
#include "Tile.h"
#include <iostream>

using namespace std;

template<int R, int C>
class Level
{
private:
	// Class Declarations
	Tile(*_level)[C];	// An array that stores the tile information of the level 

public:
	// Default Constructor
	Level()
	{
		_level = new Tile[R][C];
		Initialize();
	}

	// Destructor
	~Level()
	{
		delete[] _level;
	}
	
	// A method that sets up the initial view of the level
	void Initialize() 
	{
		for (int row = 0; row < R; row++)
			for (int column = 0; column < C; column++)
				_level[row][column].SetPosition(column * 32, row * 32);
	}

	// A method that draws the level to the renderer
	void Draw(Window *window)
	{
		// Draw the level tiles
		for (int row = 0; row < R; row++)
			for (int column = 0; column < C; column++)
				_level[row][column].Draw(window);

		// Draw the tile contents
		for (int row = 0; row < R; row++)
			for (int column = 0; column < C; column++)
				if (_level[row][column].GetContents() != nullptr)
					_level[row][column].GetContents()->Draw(window);
	}

	// A method that retrieves a tile at the given row and column
	Tile* GetTile(int row, int col)
	{
		cout << "Get: " << &_level[row][col] << endl;
		return &_level[row][col];
	}
};