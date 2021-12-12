#include "Complex.h"

void Complex::set() {
    std::cout << "Enter Real part: ";
    std::cin >> a;
    std::cout << "Enter Imaginary Part: ";
    std::cin >> b;
}

void Complex::display() {
    if (b < 0)
        if (b == -1)
            std::cout << "The complex number is: " << a << "-i" << std::endl;
        else
            std::cout << "The complex number is: " << a << b << "i" << std::endl;
    else
        if (b == 1)
            std::cout << "The complex number is: " << a << " + i" << std::endl;
        else
            std::cout << "The complex number is: " << a << " + " << b << "i" <<
            std::endl;
}

Complex Complex::operator*(const Complex& c2) const {
    Complex result = *this;
    result.a = a * c2.a - b * c2.b;
    result.b = (a * c2.b) + (c2.a * b);

    return result;
}
Complex Complex::operator*(const double& value) const {
    Complex result = *this;
    result.a = a * value;
    result.b = b * value;
    
    return result;
}

double Complex::operator!() const 
{
    return sqrt((a * a) + (b * b));
}

bool Complex::operator==(const Complex& c2) const {
    /*if (!(*this) == !c2)
        return true;*/

    if((a== c2.a)&&(b==c2.b))
        return true;
 
    else
        return false;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex res;
    res.a = c1.a + c2.a;
    res.b = c1.b + c2.b;
    return res;
}

Complex operator+(const double& value, const Complex& c) {
    return Complex(value + c.a, c.b);
}

Complex operator+(const Complex& c, const double& value) {
    return Complex(c.a + value, c.b);
}

std::ostream& operator<< (std::ostream& output, const Complex& c) {
    output << c.a << " + " << c.b << " * i";
    return output;
}