// PZ_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Employee.h"
#include "Rectangle.h"

using std::string;
using std::cout;
using std::cin;

int main()
{
	// First Assigment

	string tmpLastName = "";
	cout << "Please input a last name for employee" << endl;
	std::getline(cin, tmpLastName);

	Employee firstEmployee(tmpLastName);
	firstEmployee.PrintInfo();

	system("pause");
	system("cls");

	// Second Assigment

	int  x1, y1, height1, width1, x2, y2, height2, width2;
	cout << "Please enter the coordinates of the bottom left corner, height and width for the first rectangle" << endl;
	cin >> x1 >> y1 >> height1 >> width1;

	cout << "Please enter the coordinates of the bottom left corner, height and width for the second rectangle" << endl;
	cin >> x2 >> y2 >> height2 >> width2;

	Rectangle firstRect(x1, y1, width1, height1);
	Rectangle secondRect(x2, y2, width2, height2);

	Rectangle minBoundingRect = firstRect.BoundRect(firstRect, secondRect);

	cout << "Minimum bounding rectangle:" << endl;
	minBoundingRect.PrintInfo();
}
