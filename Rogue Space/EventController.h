#pragma once
#include "EventHandler.h"
#include <iostream>

using namespace std;

class EventController
{
private:
	SDL_Event _event;
	EventHandler *_windowEventsSubscription;
	EventHandler *_keyboardEventsSubscription;

public:
	void PollEvents();
	void PollKeyboardEvents();
	void Subscribe(EventHandler *handler, SDL_EventType eventType);
};