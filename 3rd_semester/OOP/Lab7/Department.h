#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "CharString.h"
#include "Employee.h"

class Department
{
	int id;
	CharString name;
	Employee* employee[50];
	int employeeCount;
public:
	Department(int i=0, CharString n="");
	void displayDeptInfo();
	bool AddEmployee(Employee* emp);
	bool removeEmployee(int employeeID);
	void DisplayAllEmployees();
	~Department(void);
};

#endif