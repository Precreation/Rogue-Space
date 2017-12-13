#pragma once
#include <SDL.h>
#include "RenderObject.h"
#include "TileObject.h"

class Tile : public TileObject
{
private:
	// Class Declarations
	int _redValue, _blueValue, _greenValue;		// The RGB values for the color the rectangle will be
	TileObject* _contents;						// The object that is contained by the object 

public:
	Tile();									// Default Constructor
	~Tile();								// Destructor
	void Draw(Window *window);				// A method that draws the tile to the renderer

	TileObject* GetContents();				// A method that gets the contents of the tile
	void SetContents(TileObject* content);	// A method that sets the contents of the tile
};