// PZ_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using std::cout;
using std::cin; 
using std::endl;

void firstAssigment();
void secondAssigment();
void uniqueElements(int* array, const int arraySize);

int main()
{
    std::size_t assigment{};

    cout << "Choose the assigment between 1 and 2" << endl;
    cin >> assigment;

    switch (assigment) {
    case 1: firstAssigment(); break;
    case 2: secondAssigment(); break;
    default: cout << "Uknown assigment number" << endl; break;
    }
}

void firstAssigment()
{
    system("cls");

    int uniqueArr[] = { 3, 7, 11, 13, 7, 17, 11, 15 };

    int uniqueArrSize = sizeof(uniqueArr) / sizeof(uniqueArr[0]);
    int arrSize;

    cout << "Input the size of an array" << endl;
    cin >> arrSize;

    int* userArr = new int[arrSize];

    cout << "Input the array" << endl;
    for (int i = 0; i < arrSize; ++i) {
        cin >> userArr[i];
    }

    system("cls");

    cout << "Given array:" << endl;
    for (int i = 0; i < arrSize; ++i) {
        cout << userArr[i] << " ";
    }
    
    uniqueElements(userArr, arrSize);

    cout << "Given array:" << endl;
    for (int i = 0; i < uniqueArrSize; ++i) {
        cout << uniqueArr[i] << " ";
    }

    uniqueElements(uniqueArr, uniqueArrSize);

    delete[] userArr;

    system("pause");
}
void secondAssigment()
{
    system("cls");

    int arrSize;

    cout << "Input the size of an array" << endl;
    cin >> arrSize;

    int* userArr = new int[arrSize];

    cout << "Input the array" << endl;
    for (int i = 0; i < arrSize; ++i) {
        cin >> userArr[i];
    }

    int product = 1;
    for (int i = 1; i < arrSize; i += 2) {
        product *= *(userArr + i);
    }

    cout << "The product of the elements at even positions is " << product << endl;
}

void uniqueElements(int* array, const int arraySize)
{
    cout << endl << "Unique elements: " << endl;

    bool* duplicate = new bool[arraySize] {false};
    for (int i = 0; i < arraySize; ++i)
    {
        int j;
        for (j = i + 1; j < arraySize; ++j) {
            if (*(duplicate + i)) {
                break;
            }
            else {
                if (*(array + i) == *(array + j))
                {
                    *(duplicate + i) = true;
                    *(duplicate + j) = true;
                    break;
                }
            }            
        }
            
        if (!*(duplicate + i))
            cout << *(array + i) << " ";
    }

    cout << endl;
}