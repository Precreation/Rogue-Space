#pragma once
#include <SDL.h>

class EventHandler 
{
public :
	virtual void EventHandle(SDL_Event event) = 0;
};