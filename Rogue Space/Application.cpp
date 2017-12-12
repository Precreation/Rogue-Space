#include "EventController.h"
#include "Window.h"
#include "Level.h"
#include "Player.h"
#include <iostream>

using namespace std;

int main(int args, char* argsv[])
{
	EventController eventController = EventController();

	Window window = Window("Rouge Space", 1280, 720);
	eventController.Subscribe(&window, SDL_QUIT);
	Level<10, 10> test = Level<10,10>();
	Player *player = new Player();
	eventController.Subscribe(player, SDL_KEYDOWN);

	test.GetTile(5, 5)->SetContents(player);
	while (!window.IsClosed())
	{
		test.Draw(&window);
		eventController.PollEvents();
		window.RenderObjects();
	}

	return 0;
}