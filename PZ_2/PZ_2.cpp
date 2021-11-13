// PZ_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

//Найти сколько раз в строке встречается заданная пользователем буква.
void firstAssigment() {
    string targetString;
    char searchedChar;

    cout << "Please enter the string" << endl;
    std::getline(cin, targetString);

    cout << endl;
    cout << "Please enter the searched character" << endl;
    cin >> searchedChar;

    int countInStr = 0;
    for (auto strChar : targetString) {
        if (searchedChar == strChar) {
            ++countInStr;
        }
    }

    cout << "The number of '" << searchedChar << "' in the string '" << targetString << "' is " << countInStr << endl;

}

//Напишите программу, которая выводит в цикле значения каждого ASCII кода с 32 по 127. Каждая строка должна отображать 16 символов с одним пробелом между символами.
void secondAssigment() {
    int asciiChar = 32;
    while (asciiChar <= 127) {
        for (int i = 0; i < 16; ++i) {
            cout << (char)asciiChar++;
            if (i == 15) {
                cout << endl;
            }
            else {
                cout << " ";

            }
        }
    }
}

//Составить алгоритм увеличения всех трех, введенных с клавиатуры, переменных на 5, если среди них есть хотя бы две равные.В противном случае выдать ответ «равных нет».
void thirdAssigment() {
    int firstNum, secondNum, thirdNum;

    cout << "Please type 3 numbers using space as separator" << endl;
    cin >> firstNum >> secondNum >> thirdNum;

    if (firstNum == secondNum ||
        firstNum == thirdNum ||
        secondNum == thirdNum ||
        firstNum == secondNum == thirdNum) {
        ++firstNum; ++secondNum; ++thirdNum;
    }

    cout << "First number is " << firstNum << endl << "Second number is " << secondNum << endl << "Third number is " << thirdNum << endl;

}

//Составить программу, которая будет считывать введенное трехзначное число(считывать в строку нельзя).После чего, каждую цифру этого числа необходимо вывести в новой строке.
void forthAssigment() {
    int originalNum;

    cout << "Please type number ith 3 digit" << endl;
    cin >> originalNum;

    int hundreds, tens, ones;

    hundreds = originalNum / 100;
    tens = (originalNum % 100) / 10;
    ones = originalNum % 10;

    cout << "Original number is " << originalNum << endl << "Hundreds is " << hundreds << ", tens is " << tens << ", ones is " << ones << endl;
}

int main()
{
    firstAssigment();

    system("pause");
    system("cls");

    secondAssigment();

    system("pause");
    system("cls");

    thirdAssigment();

    system("pause");
    system("cls");

    forthAssigment();

    system("pause");
    system("cls");
}