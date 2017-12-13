#pragma once
#include <SDL.h>
#include <string>
#include "EventHandler.h"

using namespace std;

class Window : public EventHandler
{
private:
	// Class Declarations
	bool _closed;					// A boolean flag that tells if the window is closed
	int _width, _height;			// The width and height for the window
	SDL_Window *_window = nullptr;	// The SDL window that is being created
	string _title;					// The string that will be shown in the title bar of the window

	bool Initialize();				// A method that initializes SDL and other window objects

public:
	// Class Declarations
	SDL_Renderer *renderer;			// The renderer that will be used to draw to the window

	Window();										// Default Constructor
	Window(string title, int width, int height);	// Constructor with defined title, width and height
	~Window();										// Destructor

	bool IsClosed();								// A method that tells if the window has closed
	void RenderObjects();							// A method that renders all objects to the screen
	void EventHandle(SDL_Event event) override;		// A method that deals with subscribed events when triggered
};