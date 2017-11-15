#include "Level.h"

using namespace std;

template <int R, int C> 
Level<R, C>::Level()
{
}

template <int R, int C>
void Level<R, C>::Draw(Window *window)
{
	for (int row = 0; row < R; row++)
		for (int column = 0; column < C; column++)
		{
			_level[row][column].Draw(window);
			_level[row][column].SetPosition(column * 32, row * 32);
		}
}