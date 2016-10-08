#include "Date.h"
#include<iostream>

using namespace std;

int main()
{
	Date d1,d2,d3;
	cin>>d1>>d2;
	cout<<endl;

	cout<<d1<<d2;
	cout<<endl;

	int noOfDays=d1-d2;
	cout<<"Difference of days: "<<noOfDays<<endl;
	cout<<endl;

	int num=735;

	d3=d1+num;
	cout<<"Added result(Date,int): "<<d3;

	d3=num+d1;
	cout<<"Added result(int,Date): "<<d3;
	cout<<endl;

	cout<<"Increment results:-"<<endl;
	cout<<"Pre-Inc "<<++d1;
	cout<<"Post-Inc "<<d1++<<d1;
	cout<<endl;

	cout<<"Decrement results:-"<<endl;
	cout<<"Pre-Dec "<<--d2;
	cout<<"Post-Dec : "<<d2--<<d2;
	cout<<endl;

	

	return 0;

}