#include<iostream>
#include<iomanip>

using namespace std;



int main()
{

    double value=0, assess=0, tax=0;
	double assessP=0.6;				//60 percent
	double taxP=0.0064;				//64 cents for each $100. Standard converted in dollar percantage.

	cout << "Enter value of your property: $ ";
	cin >> value;

	assess = assessP*value;

	tax = taxP*assess;

	cout << setprecision(2)<<fixed;

	cout << endl << setw(20) << left << "Assessment value: " << setw(4) << "$" << setw(8) << assess << endl;

	cout << setw(20) << left << "Property tax: " << setw(4) << "$" << setw(8) << tax << endl;



    return 0;

}




