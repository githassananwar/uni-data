#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    double charge=2500;
	double increase=0.04;
	int count=1;

	cout << "Current Membership fee: $" << charge << endl;

	cout << setprecision(0) << fixed;

	while(count<6)
	{

		charge = charge + (increase*charge);

		cout << "Membership fee after " << count <<" years: $" << charge << endl;

		count=count+1;
		
	}
    
     


    return 0;

}