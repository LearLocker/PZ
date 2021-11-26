#pragma once

#include <cstdint>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Employee
{
private:
	string lastName;
	uint16_t seniority;
	uint32_t hourlyWage;
	uint16_t numberOfWorkHours;

	void Init();
	int Salary();
	double Award();
	uint8_t Qualification();

public:
	Employee(string lastName);
	string getLastName();
	void setLastName(string _lastName);

	uint16_t getSeniority();
	void setSeniority(uint16_t _seniority);

	uint32_t getHourlyWage();
	void setHourlyWage(uint32_t _hourlyWage);

	uint16_t getNumberOfWorkHours();
	void setNumberOfWorkHours(uint16_t _numberOfWorkHours);

	void PrintInfo();
};

