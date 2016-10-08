#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
	double startNum=0, average=0, increase=0;
	int days=0, count=1;

	cout << "Enter starting number of organism: ";
	cin >> startNum;

	while(startNum<2)
	{
		cout << "ERROR! Invalid starting number,  Enter again: ";
		cin >> startNum;
	}

	cout << "Enter average daily population increase(%): ";
	cin >> average;

	while(average<0)
	{
		cout << "ERROR! Invalid average population increase,  Enter again: ";
		cin >> average;
	}

	cout << "Enter number of days: ";
	cin >> days;

	while(days<1)
	{
		cout << "ERROR! Invalid days,  Enter again: ";
		cin >> days;
	}

	cout << "Starting population: " << startNum << endl;

	//Calculation

	cout << setprecision(1) << fixed;

	while(count<=days)
	{
		increase = (average/100)*startNum;

		startNum = startNum+increase;

		cout << "Population after day " << count << " : " << startNum << endl;

		count++;
	}


    return 0;

}