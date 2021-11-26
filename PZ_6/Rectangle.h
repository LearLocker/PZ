#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Rectangle
{
private:
	int x, y;
	int width, height;

	int Max(int first, int second);
	int Min(int first, int second);

public:
	Rectangle(int x, int y, int width, int height);
	Rectangle BoundRect(Rectangle& first, Rectangle& second);
	void PrintInfo();
};

