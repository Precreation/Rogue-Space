#pragma once
#include "Tile.h"
#include <iostream>

using namespace std;

template<int R, int C>
class Level
{
private:
	Tile(*_level)[C];

public:
	Level()
	{
		_level = new Tile[R][C];
		Initialize();
	}

	~Level()
	{
		delete[] * _level;
	}
	
	void Initialize() 
	{
		for (int row = 0; row < R; row++)
			for (int column = 0; column < C; column++)
				_level[row][column].SetPosition(column * 32, row * 32);
	}

	void Draw(Window *window)
	{
		for (int row = 0; row < R; row++)
			for (int column = 0; column < C; column++)
				_level[row][column].Draw(window);
	}

	Tile* GetTile(int row, int col)
	{
		cout << "Get: " << &_level[row][col] << endl;
		return &_level[row][col];
	}
};