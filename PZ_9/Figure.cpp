#include "Figure.h"

std::string CFigure::getColor() {
	return color;
}
void CFigure::setColor(std::string _color) {
	color = _color;
}

CTriangle::CTriangle(double b, double h) : CFigure(), base(b), height(h) {};

void CTriangle::CalculusArea(void) { 
	area = 0.5 * (base * height); 
}
void CTriangle::PrintArea(void) const {
	std::cout << "Area of Triangle (base: " << base << ", height: " << height << ") is " << area << std::endl;
}

CCircle::CCircle(double a) : CFigure(), radius(a) {};

void CCircle::CalculusArea(void) { 
	area = PI * radius * radius; 
}
void CCircle::PrintArea(void) const { 
	std::cout << "Area of Circle (radius: " << radius << ") is " << area << std::endl; 
}

CSquare::CSquare(double a) : CFigure(), side(a) {};

void CSquare::CalculusArea(void) { 
		area = side * side;
}
void CSquare::PrintArea(void) const {
		std::cout << "Area of Square (side: " << side << ") is " << area << std::endl;
}
