#pragma once
#include <SDL.h>
#include <string>

using namespace std;

class Window
{
private:
	bool _closed;
	int _width, _height;
	SDL_Window *_window = nullptr;
	string _title;

	bool Initialize();

public:
	SDL_Renderer *renderer;

	Window();
	Window(string title, int width, int height);
	~Window();

	bool IsClosed();
	void RenderObjects();
	void PollEvents();
	void PollKeyboardEvents(SDL_Event event);
};