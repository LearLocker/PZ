// PZ_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <math.h> 

using std::string;
using std::cin;
using std::cout;
using std::endl;

// параметры по дефолту указываются в конце перечисления параметров функции
// int askNumber(int low = 1, int high);

void printString(string toPrint = "Hello");

void printString(string toPrint, int size);

void printString(string toPrint, bool isDefault);

void thirdAssigment(int n, int k);

int main()
{
    string inputString = "";
    cout << "Input the string: ";
    getline(cin, inputString);

    printString(inputString);
    printString("", true);
    printString();
    printString("", 0);

    system("pause");
    system("cls");

    int k;
    int n;
    cout << "Input the number: ";
    cin >> n;
    cout << "Input quantity of digits: ";
    cin >> k;

    thirdAssigment(n, k);

    system("pause");
    system("cls");
}

void printString(string toPrint) {
    cout << "Regular call" << endl;
    cout << toPrint << endl;
}

void printString(string toPrint, int size) {
    cout << "Using size of string call" << endl;

    if (size != 0) {
        cout << toPrint << endl;
    }
    else {
        cout << "Hello" << endl;
    }
}

void printString(string toPrint, bool isDefault) {
    cout << "Using flag call" << endl;

    if (isDefault) {
        cout << "Hello" << endl;
    }
    else {
        cout << toPrint << endl;
    }
}

void thirdAssigment(int n, int k)
{
    if (n == 0) {
        return;
    }

    int numberOfDigits = (int)(log10(n) + 1);

    if (numberOfDigits >= k)
        cout << (int)(n / pow(10, numberOfDigits - k)) << endl;
    else
        cout << n << endl;

    return;
}