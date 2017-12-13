#include "EventController.h"

// A method that polls all SDL Events
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

// A method that subscribes a event handler to the given event
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