#include<iostream>

using namespace std;

void calcSumAndDiff(int, int, int&, int&);

int main ()
{
    int num1=7, num2=3;
	int add=0, sub=0;

	cout << "Before calling the function:- " << endl;
	cout << "Sum: " << add << endl;
	cout << "Difference: " << sub << endl;

	calcSumAndDiff(num1, num2, add, sub);

	cout << endl << "After calling the function:- " << endl;
	cout << "Sum: " << add << endl;
	cout << "Difference: " << sub << endl;


	return 0;
}

void calcSumAndDiff(int n1, int n2, int &sum, int&diff)
{
	sum = n1+n2;
	diff = n1-n2;
}

