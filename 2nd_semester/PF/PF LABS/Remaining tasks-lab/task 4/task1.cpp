#include<iostream>

using namespace std;

int main ()
{
	int marks;

	std::cout<<"Enter your marks: ";
	cin>>marks;

	if(marks>=85 && marks<=100)
	{
		cout<<"Your grade is A+\n";
	}
	else if(marks>=75 && marks<=84)
	{
		cout<<"Your grade is B+\n";
	}
	else if(marks>=60 && marks<=74)
	{
		cout<<"Your grade is C+\n";
	}
	else if(marks>=0 && marks<=59)
	{
		cout<<"Your grade is F\n";
	}
	else
	{
		cout<<"Entered marks are invalid\n\n";
	}


   

	return 0;

}
