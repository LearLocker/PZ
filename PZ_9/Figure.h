#pragma once

#include <iostream>

constexpr double PI = 3.14;

class CFigure
{
public:
	friend class ShapeLogger;

	CFigure() : area(0) {}
	virtual ~CFigure() {}
	virtual void CalculusArea(void) = 0;
	virtual void PrintArea(void) const = 0;
	void setColor(std::string _color);
protected:
	double area;
private: 
	std::string color = "gray";
};

class CTriangle : public CFigure
{
public:
	static int trianCount;

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
	static int circleCount;

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
	static int sqrCount;

	CSquare(double a);
	~CSquare() {};
	void CalculusArea(void);
	void PrintArea(void) const;
protected:
	double side;
};