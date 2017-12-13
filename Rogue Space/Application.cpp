#include "EventController.h"
#include "Window.h"
#include "Level.h"
#include "PlayerCharacter.h"
#include <iostream>

using namespace std;

int main(int args, char* argsv[])
{
	// Create the event controller to manage the events
	EventController eventController = EventController();

	// Create a window and subscribe it to the SDL_QUIT evet
	Window window = Window("Rouge Space", 1280, 720);
	eventController.Subscribe(&window, SDL_QUIT);

	// Create the level
	Level<15, 15> test = Level<15,15>();

	// Create the player, subscribe it to the SDL_KeyDown Event and
	// place the character into the tile (7,7)
	PlayerCharacter *player = new PlayerCharacter();
	eventController.Subscribe(player, SDL_KEYDOWN);
	test.GetTile(7, 7)->SetContents(player);

	// Start the game loop
	while (!window.IsClosed())
	{
		test.Draw(&window);
		eventController.PollEvents();
		window.RenderObjects();
	}

	// Exit the application
	return 0;
}