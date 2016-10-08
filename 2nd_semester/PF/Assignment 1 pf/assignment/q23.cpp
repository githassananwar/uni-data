#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char pack='D';

	double rate=0, total=0, extraRate=0;

	int hours=0, pkghours=0, extra=0;

	cout<<"Enter Your package (A, B, C): ";
	cin>>pack;

	if(pack=='A')
	{
		rate=9.95;
		pkghours=10;
		extraRate=2;

		cout<<"Enter number of hours of usage(per month): ";
		cin>>hours;

		if(hours<=744)
		{
			if(hours<=pkghours)
			{
				total=hours*rate;

			}
			else
			{
				extra=hours-pkghours;

				total=(pkghours*rate)+(extra*extraRate);


			}cout<<"Total amount for this month: $ "<<total<<endl;
		}
		else
		{
			cout<<"ERROR!!! Invlaid number of hours."<<endl;
		}

	}


	else if(pack=='B')
	{
		rate=14.95;
		pkghours=20;
		extraRate=1;

		cout<<"Enter number of hours of usage(per month): ";
		cin>>hours;

		if(hours<=744)
		{
			if(hours<=pkghours)
			{
				total=hours*rate;

			}
			else
			{
				extra=hours-pkghours;

				total=(pkghours*rate)+(extra*extraRate);


			}
			cout<<"Total amount for this month: $ "<<total<<endl;
		}
		else
		{
			cout<<"ERROR!!! Invlaid number of hours."<<endl;
		}


	}


	else if(pack=='C')
	{
		rate=19.95;


		cout<<"Enter number of hours of usage(per month): ";
		cin>>hours;

		if(hours<=744)
		{


				total=hours*rate;
				cout<<"Total amount for this month: $ "<<total<<endl;


		}
		else
		{
			cout<<"ERROR!!! Invlaid number of hours."<<endl;
		}

	}


	else
	{
		cout<<"ERROR!!! You entered Wrong package."<<endl;

	}







	return 0;

}
