#include"Address.h"
#include"CharString.h"
#include "Project.h"
#include "Employee.h"
#include "Department.h"

#include<iostream>

using namespace std;


int main()
{
	//data
	CharString city("Nishat Cly, Lahore");
	CharString name1("Hassan");
	CharString name2("Anwar");

	CharString dept1("PUCIT");
	CharString dept2("PUCAD");

	Address add(530,'C',2,city);
	CharString info("Poject in progress");

	//Projects with id's
	Project p1(5,info);
	Project p2(6,info);
	Project p3(7,info);
	Project p4(8,info);

	//Departments with id's
	Department d1(456,dept1);
	Department d2(789,dept2);

	//Employees with department assignment
	Employee e1(3,name1,add);
	e1.setAssignedToDept(d1.AddEmployee(&e1));

	Employee e2(4,name2,add);
	e2.setAssignedToDept(d2.AddEmployee(&e2));

	//--------------------FUNCTION CALLS--------------------
	//Display Employees and departments
	e1. displayEmployeeInfo();
	cout<<endl;
	e2. displayEmployeeInfo();
	cout<<endl;
	d1.displayDeptInfo();
	cout<<endl;
	d2.displayDeptInfo();


	//Project addition to employees
	e1.addProject(&p1);
	e1.addProject(&p2);
	e1.addProject(&p3);
	e1.addProject(&p4);

	e2.addProject(&p2);

	cout<<endl;

	//Project removal check
	if(e1.removeProject(5))
	{
		cout<<"Project removed successfully."<<endl;
	}
	else
	{
		cout<<"Project NOT removed successfully."<<endl;
	}

	cout<<endl;

	//Employee and department all info
	e1.displayAllProjects();
	e2.displayAllProjects();

	d1.DisplayAllEmployees();
	d2.DisplayAllEmployees();

	//Employee removal check
	if(d1.removeEmployee(3))
	{
		cout<<"Employee removed successfully."<<endl;
	}
	else
	{
		cout<<"Employee NOT removed successfully."<<endl;
	}


	d1.displayDeptInfo();

	cout<<endl;

	return 0;
}