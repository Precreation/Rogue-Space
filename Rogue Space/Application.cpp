#include "Window.h"
#include "Level.cpp"

using namespace std;

int main(int args, char* argsv[])
{
	Window window = Window("Rouge Space", 1280, 720);
	Level<20,20> test;

	while (!window.IsClosed())
	{
		test.Draw(&window);
		window.PollEvents();
		window.RenderObjects();
	}

	return 0;
}