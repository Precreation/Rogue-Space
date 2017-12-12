#pragma once
#include <iostream>
#include "Window.h"

using namespace std;

class RenderObject
{
public:
	RenderObject() 
	{
	}
	virtual void Draw(Window *window) = 0;
};

