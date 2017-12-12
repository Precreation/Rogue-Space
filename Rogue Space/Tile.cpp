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
	cout << this << " Created" << endl;

}

Tile::~Tile() 
{
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
	content->SetPosition(_tile.x, _tile.y);
	_contents = content;
	cout << "Content was added to Tile " << this << endl;
}

void Tile::SetPosition(int xPosition, int yPosition)
{
	_tile.x = xPosition;
	_tile.y = yPosition;
}