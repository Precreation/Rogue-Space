#include "PlayerCharacter.h"

using namespace std;

// Default Constructor
PlayerCharacter::PlayerCharacter()
{
	_tileImage = SDL_Rect();
	_tileImage.w = TILE_SIZE;
	_tileImage.h = TILE_SIZE;
}

// Destructor
PlayerCharacter::~PlayerCharacter(){}

// A method that draws the object to the screen.
// Overrides the RenderObjects Draw method.
void PlayerCharacter::Draw(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(window->renderer, &_tileImage);
}

// A method that deals with subscribed events when triggered.
void PlayerCharacter::EventHandle(SDL_Event event)
{
	// When a key is pressed, check which key is pressed then 
	// perform the corresponding action
	switch (event.key.keysym.sym)
	{
	case SDLK_w:
		SetPosition(_tileImage.x, _tileImage.y - MOVEMENT_SPEED);
		break;
	case SDLK_a:
		SetPosition(_tileImage.x - MOVEMENT_SPEED, _tileImage.y);
		break;
	case SDLK_s:
		SetPosition(_tileImage.x, _tileImage.y + MOVEMENT_SPEED);
		break;
	case SDLK_d:
		SetPosition(_tileImage.x + MOVEMENT_SPEED, _tileImage.y);
		break;
	default:
		break;
	}
}