#include<iostream>

using namespace std;

int main ()
{
	int n1, n2, n3, n4, n5;

	cout<<"Enter 1st number: ";
	cin>>n1;

	cout<<"Enter 2nd number: ";
	cin>>n2;

	cout<<"Enter 3rd number: ";
	cin>>n3;

	cout<<"Enter 4th number: ";
	cin>>n4;

	cout<<"Enter 5th number: ";
	cin>>n5;

	int max, min;

	max=n1;
	min=n1;

	if(n2>max)
	{
		max=n2;
	}
	if(n3>max)
	{
		max=n3;
	}
	if(n4>max)
	{
		max=n4;
	}
	if(n5>max)
	{
		max=n5;
	}

	if(n2<min)
	{
		min=n2;
	}
	if(n2<min)
	{
		min=n3;
	}
	if(n4<min)
	{
		min=n4;
	}
	if(n5<min)
	{
		min=n5;
	}

	cout<<"Maximum number is: "<<max<<endl;
	cout<<"Minimum number is: "<<min<<endl;


	return 0;

}
