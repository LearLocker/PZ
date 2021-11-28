#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

int Rectangle::Max(int first, int second) {
	if (first > second) {
		return first;
	}
	else {
		return second;
	}
}

int Rectangle::Min(int first, int second) {
	if (first < second) {
		return first;
	}
	else {
		return second;
	}
}

Rectangle Rectangle::BoundRect(Rectangle& first, Rectangle& second) {
	int newX = Min(first.x, second.x);
	int newY = Min(first.y, second.y);

	int newHeight = Max(first.y + first.height, second.y + second.height);
	int newWidth = Max(first.x + second.width, second.x + second.width);

	return Rectangle(newX, newY, newWidth - newX, newHeight - newY);
}

void Rectangle::PrintInfo() {
	cout << "x:\t" << x;
	cout << endl << "y:\t" << y;
	cout << endl << "Width:\t" << width;
	cout << endl << "Height:\t" << height;
}
