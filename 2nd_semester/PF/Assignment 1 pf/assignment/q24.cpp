#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char pack='D';

	double rate=0, extraRate=0;

	double totalA=0, totalB=0, totalC=0;

	int hours=0, pkghours=0, extra=0;

	double saveA1=0, saveA2=0, saveB=0;

	cout<<"Enter Your package (A, B, C): ";
	cin>>pack;

	while(pack!='A'&&pack!='B'&&pack!='C')
	{
	    cout<<"Enter again: ";
	    cin>>pack;
	}



	if(pack=='A'||pack=='B'||pack=='C')
	{

		cout<<"Enter number of hours of usage(per month): ";
		cin>>hours;




		if(hours<=744)
		{
			//for A
			rate=9.95;
			pkghours=10;
			extraRate=2;
			if(hours<=pkghours)
			{
				totalA=hours*rate;

			}
			else
			{
				extra=hours-pkghours;

				totalA=(pkghours*rate)+(extra*extraRate);

			}


			//for B
			rate=14.95;
			pkghours=20;
			extraRate=1;
			if(hours<=pkghours)
			{
				totalB=hours*rate;

			}
			else
			{
				extra=hours-pkghours;

				totalB=(pkghours*rate)+(extra*extraRate);

			}

			//for C
			rate=19.95;
			totalC=hours*rate;




        saveA1=totalA-totalB;
		saveA2=totalA-totalC;
		saveB=totalB-totalC;

		if(pack=='A')
		{
			cout<<"Total amount for this month: $ "<<totalA<<endl;
			if(saveA1>0)
			{
				cout<<"If you purchase Package 'B', You could save: $ "<<saveA1<<endl;
			}
			else if(saveA2>0)
			{
				cout<<"If you purchase Package 'C', You could save: $ "<<saveA2<<endl;
			}
		}


		if(pack=='B')
		{
			cout<<"Total amount for this month: $ "<<totalB<<endl;
			if(saveB>0)
			{
				cout<<"If you purchase Package 'C', You could save: $ "<<saveB<<endl;
			}
		}


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
