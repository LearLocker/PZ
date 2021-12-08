#pragma once

#include <iostream>

constexpr double PI = 3.14;

class CFigure
{
public:
	CFigure() : area(0) {}
	virtual ~CFigure() {};
	virtual void CalculusArea(void) = 0;
	virtual void PrintArea(void) const = 0;
protected:
	double area;
};

class CTriangle : public CFigure
{
public:
	CTriangle(double b, double h) : CFigure(), base(b), height(h) {};
	~CTriangle() {};
	void CalculusArea(void) { area = 0.5 * ( base * height ); }
	void PrintArea(void) const { std::cout << "Area of Triangle (base: " << base << ", height: " << height << ") is " << area << std::endl; }
protected:
	double base;
	double height;
};

class CCircle : public CFigure
{
public:
	CCircle(double a) : CFigure(), radius(a) {};
	~CCircle() {};
	void CalculusArea(void) { area = PI * radius * radius; }
	void PrintArea(void) const { std::cout << "Area of Circle (radius: " << radius << ") is " << area << std::endl; }
protected:
	double radius;
};

class CSquare : public CFigure
{
public:
	CSquare(double a) : CFigure(), side(a) {};
	~CSquare() {};
	void CalculusArea(void) { area = side * side; }
	void PrintArea(void) const { std::cout << "Area of Square (side: " << side << ") is " << area << std::endl; }
protected:
	double side;
};