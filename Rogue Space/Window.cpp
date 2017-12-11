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

// Constructor
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

// Initialize the components of the window
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

// Get the value of _closed
bool Window::IsClosed()
{
	return _closed;
}

// Renders objects to the window
void Window::RenderObjects()
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
	SDL_RenderClear(renderer);
}

// Evaluate window events
void Window::PollEvents()
{
	SDL_Event event;

	//Checks to see if there is an event
	if (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_closed = true;
			break;
		case SDL_KEYDOWN:
			PollKeyboardEvents(event);
			break;
		default:
			break;
		}
	}
}

void Window::PollKeyboardEvents(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_w:
		cout << "W is pressed" << endl;
		break;
	case SDLK_a:
		cout << "A is pressed" << endl;
		break;
	case SDLK_s:
		cout << "S is pressed" << endl;
		break;
	case SDLK_d:
		cout << "D is pressed" << endl;
		break;

	default:
		break;
	}
}