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

void printStringUsingDefault(string toPrint = "Hello");

void printString(string toPrint);

void printString();

void thirdAssigment(int n, int k);

int main()
{
    string inputString = "";
    cout << "Input the string: ";
    getline(cin, inputString);

    printStringUsingDefault(inputString);
    printStringUsingDefault();

    printString(inputString);
    printString();

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

void printStringUsingDefault(string toPrint) {
    cout << toPrint << endl;
}

void printString(string toPrint) {
    if (toPrint.size() != 0) {
        cout << toPrint << endl;
    }
    else {
        cout << "Hello" << endl;
    }
}

void printString() {
    cout << "Hello" << endl;
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