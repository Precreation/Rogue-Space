#include "Player.h"

using namespace std;


Player::Player()
{
	cout << "Player Created!" << endl;
	_image = SDL_Rect();
	_image.w = TILE_SIZE;
	_image.h = TILE_SIZE;
}

Player::~Player(){}

void Player::Draw(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(window->renderer, &_image);
}

void Player::EventHandle(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_w:
		SetPosition(_image.x, _image.y - 32);
		break;
	case SDLK_a:
		SetPosition(_image.x-32, _image.y);
		break;
	case SDLK_s:
		SetPosition(_image.x, _image.y + 32);
		break;
	case SDLK_d:
		SetPosition(_image.x+32, _image.y);
		break;
	default:
		break;
	}

}