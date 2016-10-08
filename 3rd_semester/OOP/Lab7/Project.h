#ifndef PROJECT_H
#define PROJECT_H
#include "CharString.h"

class Project
{
	int id;
	CharString projectDescription;
	int employeesWorkingOn;
public:
	Project(int, CharString);
	int getProID();
	void displayProjectInfo();
	void IncEmployeesWorkingOn();
	void DecEmployeesWorkingOn();
	~Project(void);
};

#endif