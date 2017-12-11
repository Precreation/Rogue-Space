#include "Player.h"

using namespace std;


Player::Player()
{
	cout << "Player Created!" << endl;
	_player = SDL_Rect();
	_player.w = 32;
	_player.h = 32;
}

void Player::Draw(Window *window)
{
	SDL_SetRenderDrawColor(window->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(window->renderer, &_player);
}