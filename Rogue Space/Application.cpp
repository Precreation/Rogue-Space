#include "Window.h"
#include "Level.h"
#include "Player.h"

using namespace std;

int main(int args, char* argsv[])
{
	Window window = Window("Rouge Space", 1280, 720);
	Level<2, 2> test = Level<2,2>();
	Player *player = new Player();

	test.GetTile(0, 0)->SetContents(player);
	while (!window.IsClosed())
	{
		test.Draw(&window);
		window.PollEvents();
		window.RenderObjects();
	}

	return 0;
}