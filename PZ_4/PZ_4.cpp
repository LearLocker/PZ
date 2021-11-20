// PZ_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

void firstAssigment();

void secondAssigment();

bool max_unique(int firstNum, int secondNum, int thirdNum, int& result);

void formatName(string& inputString);

int main()
{
    std::size_t assigment{};
    cout << "Choose the assigment between 1 and 2" << endl;
    cin >> assigment;
    switch(assigment) {
    case 1: firstAssigment(); break;
    case 2: secondAssigment(); break;
    default: cout << "Uknown assigment number" << endl; break;
    }
}

void firstAssigment() {
    system("cls");

    int firstNum = 0, secondNum = 0, thirdNum = 0, result = 0;
    cout << "Please type 3 numbers using space as separator" << endl;
    cin >> firstNum >> secondNum >> thirdNum;

    bool unique = max_unique(firstNum, secondNum, thirdNum, result);

    cout << "Are those numbers unique? " << (unique ? "True" : "False") << endl;
    cout << "The biggest number is " << result << endl;

    system("pause");
    system("cls");
}

void secondAssigment() {
    system("cls");

    string name = "Anna";
    char ch = 0;
    bool valid;

    formatName(name);
    cout << name << endl;

    name = "Tom";
    formatName(name);
    cout << name << endl;

    system("pause");
     
    // error with users input
    do {
        system("cls");

        cout << "Input the name: " << endl;
        getline(cin, name);

        formatName(name);

        cout << name << endl;

        cout << "Do you ant to try more? For exit type 'Esc'" << endl;
        cin >> ch;
    } while (ch != 27);

    system("pause");
    system("cls");
}

bool max_unique(int firstNum, int secondNum, int thirdNum, int& result) {
    result = firstNum > secondNum ? firstNum : secondNum;
    result = result < thirdNum ? thirdNum : result;

    if (firstNum == secondNum || firstNum == thirdNum || thirdNum == secondNum) {
        return false;
    }

    return true;
}


void formatName(string& inputString) {
    if (inputString.size() == 0) {
        inputString = "Error";
        return;
    }

    char lastSymbol = inputString[inputString.size() - 1];

    if (lastSymbol == 'a' || lastSymbol == 'o' || lastSymbol == 'e') {
        inputString = "Mrs " + inputString;
    }
    else {
        inputString = "Mr " + inputString;
    }
}