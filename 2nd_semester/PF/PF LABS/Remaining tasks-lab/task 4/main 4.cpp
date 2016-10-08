#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{

    char month[1000];
    char year[1000];
    double sales=0, county=0, state=0;
    double total=0, saleTotal=0;
    double stateP=0.04, countyP=0.02;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter total amount collected: ";
    cin >> total;

    cout << endl;

    sales = total/1.06;

    state = stateP*sales;

    county = countyP*sales;

    saleTotal = state+county;

    cout << setprecision(2) << fixed;

    cout << "Month: " << month << endl << endl;

    cout << "--------------------" << endl;


    cout << setw(25) << left << "Total collected: " << setw(2) << "$" << setw(8) << total << endl;

    cout << setw(25) << left << "Sales: " << setw(2) << "$" << setw(8) << sales << endl;

    cout << setw(25) << left << "County sales tax: " << setw(2) << "$" << setw(8) << county << endl;

    cout<<setw(25) << left << "State sales tax: " << setw(2) << "$" << setw(8) << state << endl;

    cout<<setw(25) << left <<"Total sales tax : " << setw(2) << "$" << setw(8) << saleTotal << endl;


	return 0;

}
