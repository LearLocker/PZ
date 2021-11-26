#include "Employee.h"

// Getters and Setters
string Employee::getLastName() { return lastName; }
void Employee::setLastName(string _lastName) { lastName = _lastName; }

uint16_t Employee::getSeniority() { return seniority; }
void Employee::setSeniority(uint16_t _seniority) { seniority = _seniority; }

uint32_t Employee::getHourlyWage() { return hourlyWage; }
void Employee::setHourlyWage(uint32_t _hourlyWage) { hourlyWage = _hourlyWage; }

uint16_t Employee::getNumberOfWorkHours() { return numberOfWorkHours; }
void Employee::setNumberOfWorkHours(uint16_t _numberOfWorkHours) { numberOfWorkHours = _numberOfWorkHours; }

// Constructor
Employee::Employee(string lastName) : lastName(lastName) {
	Init();
}

void Employee::Init() {
	seniority         = rand() % 50;
	hourlyWage        = rand() % 900 + 100;
	numberOfWorkHours = rand() % 80 + 80;
}

int Employee::Salary() {
	return numberOfWorkHours * hourlyWage;
}

uint8_t Employee::Qualification() {
	if (seniority < 1) {
		return 0;
	}
	else if (seniority > 1 && seniority < 3) {
		return 5;
	}
	else if (seniority > 3 && seniority < 5) {
		return 8;
	}
	else if (seniority > 5) {
		return 15;
	}
}

double Employee::Award() {
	return Salary() * (Qualification() / 100.);
}

void Employee::PrintInfo() {
	cout << "Employee:\t" << lastName;
	cout << endl << "Seniority:\t" << seniority;
	cout << endl << "Hourly Wage:\t" << hourlyWage;
	cout << endl << "Number Of Work Hours:\t" << numberOfWorkHours;
	cout << endl << "Total Salary:\t" << Salary();
	cout << endl << "Award:\t" << Award();
	cout << endl;
}
