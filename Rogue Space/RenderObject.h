#pragma once
#include <iostream>
#include "Window.h"

using namespace std;

class RenderObject
{
public:
	virtual void Draw(Window *window) = 0;	// A method to be inherited to draw objects to the renderer
};

