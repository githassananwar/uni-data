#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{

	double start=0;
	double rate=0;
	double minute=0, fpart=0, total;



	cout<<"Enter Starting time in format(HH.MM): ";
	cin>>start;



	if(start<=23.59)
	{
		fpart=start - static_cast<int>(start);

		if(fpart<=0.59)
		{

			cout<<"Enter number of minutes: ";
			cin>>minute;

			if(start>=0.0 && start<=6.59)
			{
				rate=0.12;


			}

			else if(start>=7.0 && start<=19.0)
			{
				rate=0.55;


			}

			else if(start>=19.01 && start<=23.59)
			{
				rate=0.35;

			}

			total=rate*minute;
				cout<<"Your total charges are: "<<"$ "<<total<<endl;


		}
		else
		{
			cout<<"ERROR!!! Your Starting time is INVALID."<<endl;
		}




	}
	else
	{
		cout<<"ERROR!!! Your Starting time is INVALID."<<endl;
	}






	return 0;

}
