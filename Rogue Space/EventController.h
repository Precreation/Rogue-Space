#pragma once
#include "EventHandler.h"
#include <iostream>

using namespace std;

class EventController
{
private:
	// Class Delcarations
	SDL_Event _event;							// The currently polled event
	EventHandler *_windowEventsSubscription;	// The object that handles window events
	EventHandler *_keyboardEventsSubscription;	// The object that handles key down events

public:
	void PollEvents();													// A method that polls all SDL Events
	void Subscribe(EventHandler *handler, SDL_EventType eventType);		// A method that subscribes a event handler to the given event
};