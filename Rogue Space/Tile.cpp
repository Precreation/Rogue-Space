#include "Tile.h"

Tile::Tile()
{
	_tile = SDL_Rect();
	_tile.w = TILE_SIZE;
	_tile.h = TILE_SIZE;

	_redValue = 0;
	_greenValue = 115;
	_blueValue = 233;

}

void Tile::Draw(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, _redValue, _greenValue, _blueValue, 255);
	SDL_RenderFillRect(window->renderer, &_tile);
}

void Tile::SetPosition(int xPosition, int yPosition)
{
	_tile.x = xPosition;
	_tile.y = yPosition;
}