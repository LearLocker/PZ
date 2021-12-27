// PZ_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <string>

class MyBaseException {

public:
    MyBaseException(const int& number) : number_(number) {}
    virtual ~MyBaseException() noexcept {}

    virtual void PrintError()
    {
        std::cout << "Error. Received: "
            << number_ << std::endl;
    }
protected:
    int number_;
};

class MyException_1 : public MyBaseException
{
public:
    MyException_1(const int& number) :MyBaseException(number) { }
    virtual void PrintError()
    {
        std::cout << "Too big! Received: ";
        std::cout << MyBaseException::number_ << std::endl;
    }
};

class MyException_2 : public MyBaseException
{
public:
    MyException_2(const int& number) :MyBaseException(number) { }
    virtual void PrintError()
    {
        std::cout << "Zero! Received: ";
        std::cout << MyBaseException::number_ << std::endl;
    }
};

class MyException_3 : public MyBaseException
{
public:
    MyException_3(const int& number) :MyBaseException(number) { }
    virtual void PrintError()
    {
        std::cout << "Negative! Received: ";
        std::cout << MyBaseException::number_ << std::endl;
    }
};

void checkNumber(const int& number) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(1, 3);

    int exception_number = distr(eng);

    switch (exception_number) {
    case 1: throw  MyException_1(number); break;
    case 2: throw  MyException_2(number); break;
    case 3: throw  MyException_3(number); break;
    default: std::cout << "Uknown exception" << std::endl; break;
    }
}

int main()
{
    char exit;

    do {
        try
        {
            int number;
            std::cout << "Enter the number: ";
            std::cin >> number;
            checkNumber(number);
        }
        catch (MyException_1& e)
        {
            e.PrintError();
        }
        catch (MyBaseException& e)
        {
            std::cout << "Generic case" << std::endl;
            e.PrintError();
        }

        std::cout << "Try again? (y-yes, other-exit)" << std::endl;
        std::cin >> exit;
    } while (exit == 'y' || exit == 'Y');
}