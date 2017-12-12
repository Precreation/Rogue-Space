#include "Tile.h"

Tile::Tile()
{
	_tileImage = SDL_Rect();
	_tileImage.w = TILE_SIZE;
	_tileImage.h = TILE_SIZE;

	_redValue = 0;
	_greenValue = 115;
	_blueValue = 233;

	_contents = nullptr;
}

Tile::~Tile() 
{
}

void Tile::Draw(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, _redValue, _greenValue, _blueValue, 255);
	SDL_RenderFillRect(window->renderer, &_tileImage);
}


TileObject* Tile::GetContents()
{
	return _contents;
}

void Tile::SetContents(TileObject* content)
{	
	content->SetPosition(_tileImage.x, _tileImage.y);
	_contents = content;
	cout << "Content was added to Tile " << this << endl;
}