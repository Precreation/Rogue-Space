#include "Window.h"
#include "Level.h"
#include "Player.h"

using namespace std;

int main(int args, char* argsv[])
{
	Window window = Window("Rouge Space", 1280, 720);
	Level<10, 10> test = Level<10,10>();
	Player *player = new Player();

	test.GetTile(5, 5).SetContents(player);
	while (!window.IsClosed())
	{
		test.Draw(&window);
		window.PollEvents();
		window.RenderObjects();
	}

	return 0;
}