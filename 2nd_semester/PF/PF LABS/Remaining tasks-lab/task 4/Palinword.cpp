#include<iostream>
#include<conio.h>




using namespace std;

int main()
{
	int n1, n2, n3;

	cout<<"Enter three numbers: ";
	cin>>n1>>n2>>n3;

	int sum=n1+n2+n3;
	int product=n1*n2*n3;
	float average=sum/3.0;

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

	if(n2<min)
	{
		min=n2;
	}
	if(n3<min)
	{
		min=n3;
	}

	cout<<"Average: "<<average<<endl;
	cout<<"Sum: "<<sum<<endl;
	cout<<"Product: "<<product<<endl;
	cout<<"Maximum: "<<max<<endl;
	cout<<"Minimum: "<<min<<endl;


	return 0;

}