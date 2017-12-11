#pragma once
#include "Tile.h"

template<int R, int C>
class Level
{
private:
	Tile(*_level)[C];

public:
	Level()
	{
		_level = new Tile[R][C];
	}
	~Level()
	{
		delete[] * _level;
	}
	
	void Draw(Window *window)
	{
		for (int row = 0; row < R; row++)
			for (int column = 0; column < C; column++)
			{
				_level[row][column].Draw(window);
				_level[row][column].SetPosition(column * 32, row * 32);
			}
	}

	Tile GetTile(int row, int col)
	{
		return _level[row][col];
	}
};