#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	const int SIZE=1000;
	int adult=0, child=0 , pAdult=6, pChild=3;
	double grossProfit=0, netProfit=0, dstbProfit=0;
	double netPercent=0.2;

	char name[SIZE];

	cout << "Enter Movie name: ";
	cin.getline(name,SIZE);

	cout << "Enter number of adults tickets sold: ";
	cin >> adult;

	cout << "Enter number of child tickets sold: ";
	cin >> child;

	grossProfit = (adult*pAdult) + (child*pChild);

	netProfit = netPercent * grossProfit;

	dstbProfit = grossProfit-netProfit;


    cout << setw(30) << "Movie name:" << setw(4) <<"''" <<setw(7) << name <<setw(4) <<"''" << endl;

	cout << setw(30) << "Adult Tickets sold:" << setw(15) << adult <<endl;

	cout << setw(30) << "Child Tickets sold:" << setw(15) << child << endl;

	cout<<setprecision(2)<<fixed;

	cout << setw(30) << "Gross box office profit:" << setw(5) << "$" << setw(10) << grossProfit << endl;

	cout << setw(30) << "Net box office profit:" << setw(5) <<"$" << setw(10) << netProfit << endl;

	cout << setw(30) << "Amount paid to Distributor:"<< setw(5) <<"$" << setw(10) << dstbProfit << endl;



	


	return 0;

}
