#pragma once
#include <iostream>

class Complex
{
private:
    double a, b;
public:
    Complex() : a(0), b(0) {}
    Complex(double r, double i) {
        a = r; b = i;
    }
    void set();
    void display();
    
    Complex operator*(const Complex& c2) const;
    Complex operator*(const double& value) const;

    double operator!() const;
    bool operator==(const Complex& c2) const;

    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator+(const double& vslue, const Complex& c);
    friend Complex operator+(const Complex& c, const double& value);
    friend std::ostream& operator<<(std::ostream& output, const Complex&);
};

