#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    double regular=10, limit=400;
	double balance=0, cheque=0, extra=15;
	double total=0;
	double chequeFee=0;

	cout<<"Enter your current balance: ";
	cin>>balance;

	//balance condition if. .
	if(balance>=0)
	{
		
	cout<<"Enter the number of cheques written: ";
	cin>>cheque;

	if(cheque>=0)
	{
		if(balance<limit)
		{
			total=extra;
		}

		if(cheque<20)
		{
			chequeFee=0.10*cheque;
			total=total+chequeFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}

		if(cheque>=20&&cheque<=39)
		{
			chequeFee=0.08*cheque;
			total=total+chequeFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}

		else if(cheque>=40&&cheque<=59)
		{
			chequeFee=0.06*cheque;
			total=total+chequeFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}

		else if(cheque>=60)
		{
			chequeFee=0.04*cheque;
			total=total+chequeFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}


	}
	else
	{

		cout<<"ERROR!!! Invalid number of cheques."<<endl;
	}



	}

	//balance condition else
	else
	{

		cout<<"ERROR!!! Invalid Balance entered. Account overdrawn. ."<<endl;
	}

    return 0;

}