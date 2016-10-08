#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    
	double faren=0, celsius=0;

	while(celsius<=20)
	{
		faren=(9*celsius/5)+32;

		cout << "Farenhite temperature for " << celsius << " C = ";
		cout << faren << " F" << endl;

		celsius++;
	}

    return 0;

}