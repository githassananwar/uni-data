#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Project.h"
#include "CharString.h"
#include "Address.h"

class Employee
{
	int id;
	CharString name;
	Address permanentAddr;
	bool assignedToDept;
	Project* project[3];
	int projectCount;

public:
	Employee(int=0, CharString="", Address=0);
	int getEmpId();
	void displayEmployeeInfo();
	bool addProject(Project*);
	bool removeProject(int);
	void displayAllProjects();
	void setAssignedToDept(bool);
	bool getAssignedToDept();
	~Employee(void);
};


#endif
