#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void firstAssigment() {
    int numbers[3];
    int size = sizeof(numbers) / sizeof(numbers[0]);
    double sum = 0.;

    cout << "Please type 3 numbers using space as separator" << endl;
    cin >> numbers[0] >> numbers[1] >> numbers[2];

    for (auto number : numbers) {
        sum += number;
    }

    size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Average of three numbers is " << sum / size << endl;
}

int fahrenheitOffset() {
    return 32;
}

double fahrenheitCoefficient() {
    return 9 / 5.;
}

void thirdAssigment() {
    double celsius = 0., fahrenheit = 0.;

    cout << "Please enter the temperature in Celsius" << endl;
    cin >> celsius;

    fahrenheit = (celsius * fahrenheitCoefficient()) + fahrenheitOffset();

    cout << "Temperature in Fahrenheit is " << fahrenheit << endl;
}

int main()
{
    firstAssigment();

    system("pause");
    system("cls");

    thirdAssigment();
}
