#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
	double second=0;
	double minute=0, hour=0, day=0;

	cout << "Enter number of seconds: ";

	cin >> second;

	if(second >= 60 && second < 3600)
	{

		minute = second/60;
		cout << setprecision(1) << fixed;
		cout << "Number of minutes: " << minute << endl;

	}


	if(second >= 3600 && second < 86400)
	{

		hour = second/3600;
		cout << setprecision(1) << fixed;
		cout << "Number of hours: " << hour << endl;

	}


	if(second >= 86400)
	{

		day = second/86400;
		cout << setprecision(1) << fixed;
		cout << "Number of days: " << day << endl;

	}

	


	return 0;

}


