#include "Figure.h"

int CTriangle::trianCount = 0;
int CCircle::circleCount  = 0;
int CSquare::sqrCount     = 0;

void CFigure::setColor(std::string _color) {
	color = _color;
}

CTriangle::CTriangle(double b, double h) : CFigure(), base(b), height(h) { ++trianCount; }

void CTriangle::CalculusArea(void) { 
	area = 0.5 * (base * height); 
}
void CTriangle::PrintArea(void) const {
	std::cout << "Area of Triangle (base: " << base << ", height: " << height << ") is " << area << std::endl;
}

CCircle::CCircle(double a) : CFigure(), radius(a) { ++circleCount; }

void CCircle::CalculusArea(void) { 
	area = PI * radius * radius; 
}
void CCircle::PrintArea(void) const { 
	std::cout << "Area of Circle (radius: " << radius << ") is " << area << std::endl; 
}

CSquare::CSquare(double a) : CFigure(), side(a) { ++sqrCount; }

void CSquare::CalculusArea(void) { 
		area = side * side;
}
void CSquare::PrintArea(void) const {
		std::cout << "Area of Square (side: " << side << ") is " << area << std::endl;
}
