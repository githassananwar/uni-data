#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	const int SIZE=100;

	char month1[SIZE], month2[SIZE], month3[SIZE];
	double amount1=0, amount2=0, amount3=0;
	double total, average;

	cout << "Enter Month 1: ";
	cin >> month1;
	cout << "Enter amount of rain(in inches): ";
	cin >> amount1;


	cout << endl << "Enter Month 2: ";
	cin >> month2;
	cout << "Enter amount of rain(in inches): ";
	cin >> amount2;

	cout << endl << "Enter Month 3: ";
	cin >> month3;
	cout << "Enter amount of rain(in inches): ";
	cin >> amount3;

	total = amount1 + amount2 + amount3;

	average = total/3;

	cout << setprecision(2) << fixed;

	cout << endl << "The average rainfall for ";
	cout << month1 <<", " << month2 << " and " << month3;
	cout << " is " << average << " inches." << endl << endl;
	

	return 0;

}
