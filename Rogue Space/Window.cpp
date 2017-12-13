#include <iostream>
#include "Window.h"

using namespace std;

// Default Constructor
Window::Window() 
{
	_title = "SDL Window";
	_width = 800;
	_height = 600;

	_closed = !Initialize();
}

// Constructor with defined title, width and height
Window::Window(string title, int width, int height)
{
	_title = title;
	_width = width;
	_height = height;

	_closed = !Initialize();
}

//Destructor
Window::~Window()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

// A method that initializes SDL and other window objects
bool Window::Initialize()
{
	// Attempt to initialize SDL Video
	if (!SDL_INIT_VIDEO)
	{
		cerr << "SDL could not initialize video.\n Error: $s", SDL_GetError();
		return false;
	}

	// Attempt to create a window
	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

	// Check to see if window was changed
	if (_window == nullptr)
	{
		cerr << "SDL could not create the window.\n Error: %s", SDL_GetError();
		return false;
	}

	// Creates a Renderer (Error check is in the object)
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		cerr << "SDL could not create the renderer.\n Error: %s", SDL_GetError();
		return false;
	}

	return true;
}

// A method that tells if the window has closed
bool Window::IsClosed()
{
	return _closed;
}

// A method that renders all objects to the screen
void Window::RenderObjects()
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
	SDL_RenderClear(renderer);
}

// A method that deals with subscribed events when triggered
void Window::EventHandle(SDL_Event event)
{
	_closed = true;
}