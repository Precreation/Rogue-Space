#include <iostream>
#include "Window.h"

using namespace std;

Window::Window() 
{
	_title = "SDL Window";
	_width = 800;
	_height = 600;

	_closed = !Initialize();
}

Window::Window(string title, int width, int height)
{
	_title = title;
	_width = width;
	_height = height;

	_closed = !Initialize();
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::Initialize()
{
	//Attempt to initialize SDL Video
	if (!SDL_INIT_VIDEO)
	{
		cerr << "SDL could not initialize video.\n Error: $s", SDL_GetError();
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

	if (_window == nullptr)
	{
		cerr << "SDL could not create the window.\n Error: %s", SDL_GetError;
		return false;
	}

	return true;
}

bool Window::IsClosed()
{
	return _closed;
}