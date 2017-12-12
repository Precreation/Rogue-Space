#include "EventController.h"

void EventController::PollEvents() 
{
	if (SDL_PollEvent(&_event))
	{
		switch (_event.type) 
		{
		case SDL_QUIT:
			if (_windowEventsSubscription != nullptr)
				_windowEventsSubscription->EventHandle(_event);
			break;
		case SDL_KEYDOWN:
			if (_keyboardEventsSubscription != nullptr)
				_keyboardEventsSubscription->EventHandle(_event);
			break;
		}
	}
}

void EventController::Subscribe(EventHandler *handler, SDL_EventType eventType)
{
	switch (eventType) 
	{
	case SDL_QUIT:
		_windowEventsSubscription = handler;
		break;
	case SDL_KEYDOWN:
		_keyboardEventsSubscription = handler;
		break;
	}
}