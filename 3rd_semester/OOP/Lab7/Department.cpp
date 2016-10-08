#include "Department.h"
#include "CharString.h"
#include "Employee.h"

#include<iostream>

using namespace std;

Department::Department(int i, CharString n)
{
	id=i;
	name=n;
	for(int i=0;i<50;i++)
	{
		employee[i]=0;
	}
	employeeCount=0;
}

void Department::displayDeptInfo()
{
	cout<<"Department ID: "<<id<<endl;
	cout<<"Department Name: ";
	cout<<name;
	cout<<endl<<"Total employees: "<<employeeCount<<endl;

}

bool Department::AddEmployee(Employee* emp)
{
	if(employeeCount<50 && !emp->getAssignedToDept())
	{
		employee[employeeCount]=emp;
		employee[employeeCount]->setAssignedToDept(1);
		employeeCount++;
		return 1;
	}

	return 0;

}

bool Department::removeEmployee(int employeeID)
{
	for(int i=0;i<employeeCount;i++)
	{
		if(employee[i]->getEmpId()==employeeID)
		{
			if(employee[i]->getAssignedToDept())
			{
				employee[i]->setAssignedToDept(0);
				employee[i]=0;
				employeeCount--;
				if(i<49)
				{
					if(i>0)
					{
						for(int j=1;j<49;j++)
						{	
							employee[j]=employee[j+1];
							employee[j+1]=0;
						}
					}
					else
					{
						for(int j=0;j<49;j++)
						{	
							employee[j]=employee[j+1];
							employee[j+1]=0;
						}
					}
			
				}
				return 1;
			}
		}
	}

	return 0;
}

void Department::DisplayAllEmployees()
{
	cout<<endl<<"Department ID# "<<id<<" ";
	cout<<name;
	cout<<" employees list:-"<<endl;
	for(int i=0; employee[i]!=0 && i<3; i++)
	{
		employee[i]->displayEmployeeInfo();
		cout<<endl;
	}
}


Department::~Department(void)
{
}
