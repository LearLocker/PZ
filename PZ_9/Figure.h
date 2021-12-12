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
	std::string getColor();
	void setColor(std::string _color);
protected:
	double area;
	std::string color = "gray";
};

class CTriangle : public CFigure
{
public:
	CTriangle(double b, double h);
	~CTriangle() {};
	void CalculusArea(void);
	void PrintArea(void) const;
protected:
	double base;
	double height;
};

class CCircle : public CFigure
{
public:
	CCircle(double a);
	~CCircle() {};
	void CalculusArea(void);
	void PrintArea(void) const;
protected:
	double radius;
};

class CSquare : public CFigure
{
public:
	CSquare(double a);
	~CSquare() {};
	void CalculusArea(void);
	void PrintArea(void) const;
protected:
	double side;
};