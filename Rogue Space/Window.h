#pragma once
#include <SDL.h>
#include <string>

using namespace std;

class Window
{
private:
	bool _closed;
	int _width, _height;
	string _title;
	SDL_Window *_window;

	bool Initialize();

public:
	Window();
	Window(string title, int width, int height);
	~Window();

	bool IsClosed();
};