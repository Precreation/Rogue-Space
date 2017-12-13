#pragma once
#include <SDL.h>

class EventHandler 
{
public :
	virtual void EventHandle(SDL_Event event) = 0;	// A method that is called used to handle subscribed events
};