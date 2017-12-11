#include "Tile.h"

Tile::Tile()
{
	_tile = SDL_Rect();
	_tile.w = TILE_SIZE;
	_tile.h = TILE_SIZE;

	_redValue = 0;
	_greenValue = 115;
	_blueValue = 233;

	_contents = nullptr;
}

Tile::~Tile() 
{
	delete[] _contents;
}
void Tile::Draw(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, _redValue, _greenValue, _blueValue, 255);
	SDL_RenderFillRect(window->renderer, &_tile);

	if (_contents != nullptr)
		_contents->Draw(window);

}


TileObject* Tile::GetContents()
{
	return _contents;
}

void Tile::SetContents(TileObject* content)
{
	_contents = content;
}

void Tile::SetPosition(int xPosition, int yPosition)
{
	_tile.x = xPosition;
	_tile.y = yPosition;
}