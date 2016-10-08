#include<iostream>

using namespace std;

int main ()
{
    double num=0, count=0, op=0;
    cout << "Enter Number for its factorial: ";
	cin >> num;

	op = num;

	count = num-1;

	while(count!=0)
	{
		num = num*count;

		count = count-1;
	}

	cout << "Factorial of " << op << ": " << num << endl;

 
	return 0;

}
