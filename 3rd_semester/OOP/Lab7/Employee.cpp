#include "Employee.h"
#include "Project.h"
#include "CharString.h"

#include<iostream>

using namespace std;

Employee::Employee(int i, CharString n, Address add)
{
	id=i;
	name=n;
	permanentAddr=add;
	projectCount=0;
	assignedToDept = 0;
	for(int i=0;i<3;i++)
	{
		project[i]=0;
	}
}

int Employee::getEmpId()
{
	return id;
}

void Employee :: displayEmployeeInfo()
{
	cout<<"Employee ID no: "<<id<<endl;
	cout<<"Name: ";
	cout<<name;
	cout<<endl<<"Permanent Address: ";
	permanentAddr.displayAddress();
}

bool Employee::addProject(Project* proj)
{
	if(projectCount<3)
	{
		project[projectCount]=proj;
		project[projectCount]->IncEmployeesWorkingOn();
		projectCount++;

		return 1;
	}

	return 0;

}

bool Employee::removeProject(int projectID)
{
	for(int i=0;i<projectCount;i++)
	{
		if(project[i]->getProID()==projectID)
		{
			project[i]->DecEmployeesWorkingOn();
			project[i]=0;
			projectCount--;
			if(i<2)
			{
				if(i>0)
				{
					for(int j=1;j<2;j++)
					{	
						project[j]=project[j+1];
						project[j+1]=0;
					}
				}
				else
				{
					for(int j=0;j<2;j++)
					{	
						project[j]=project[j+1];
						project[j+1]=0;
					}
				}
				
			}
			return 1;
		}
	}
	return 0;

}
void Employee::displayAllProjects()
{
	cout<<endl<<"Projects taken by Employee ID# "<<id<<" Mr. ";
	cout<<name;
	cout<<":- "<<endl;
	for(int i=0; project[i]!=0 && i<3; i++)
	{
		
		project[i]->displayProjectInfo();
		
	}
}

void Employee::setAssignedToDept(bool value)
{
	assignedToDept = value ;
}

bool Employee::getAssignedToDept()
{
	return assignedToDept ;
}


Employee::~Employee(void)
{
}
