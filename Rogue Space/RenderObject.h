#pragma once
#include <iostream>
#include "Window.h"

using namespace std;

class RenderObject
{
public:
	RenderObject() 
	{
		cout << "RenderObject Created" << endl;
	}
	virtual void Draw(Window *window) = 0;
};

