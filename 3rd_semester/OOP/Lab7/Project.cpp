#include "CharString.h"
#include "Project.h"

#include<iostream>

using namespace std;


Project::Project(int i=0, CharString p="")
{
	id=i;
	projectDescription=p;
	employeesWorkingOn=0;
}

int Project::getProID()
{
	return id;
}

void Project::displayProjectInfo()
{
	cout<<"Project ID: "<<id<<endl;
	cout<<"Total Employees working: "<<employeesWorkingOn<<endl;
	cout<<"Project description: ";
	cout<<projectDescription;
	cout<<endl;

}

void Project::IncEmployeesWorkingOn()
{
	employeesWorkingOn++;
}

void Project::DecEmployeesWorkingOn()
{
	employeesWorkingOn--;

}

Project::~Project(void)
{
}
