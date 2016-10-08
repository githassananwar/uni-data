#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	int const size=7;
    long empId[size];
	int hours[size];
	double payRate[size];
	double wages[size];

	int count=0;

	empId[0]=5658845;
	empId[1]=4520125;
	empId[2]=7895122;
    empId[3]=8777541;
    empId[4]=8451277;
    empId[5]=1302850;
    empId[6]=7580489;


	for(count=0;count<size;count++)
	{
		cout<<"Enter employee "<<count+1<<" hours: ";
		cin>>hours[count];
		while(hours[count]<0)
		{
			cout<<"Invalid hours!!! Enter again: ";
			cin>>hours[count];
		}


		cout<<"Enter employee "<<count+1<<" payhours: ";
		cin>>payRate[count];
		while(payRate[count]>=6)
		{
			cout<<"Invalid Pay rate!!! Enter again: ";
			cin>>payRate[count];
		}

		wages[count]=hours[count]*payRate[count];

		cout<<endl;

	}

	for(count=0; count<size; count++)
	{
		cout<<"Employee id no. "<<empId[count]<<" gross wages= : $";
		cout<<setprecision(1)<<fixed<<wages[count]<<endl;

	}
	

    return 0;

}