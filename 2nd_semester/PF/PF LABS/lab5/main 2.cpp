#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    double regular=10, limit=400;
	double balance=0, check=0, extra=15;
	double total=0;
	double checkFee=0;

	cout<<"Enter your current balance: ";
	cin>>balance;

	//balance condition if. .
	if(balance>=0)
	{
		
	cout<<"Enter the number of checks written: ";
	cin>>check;

	if(check>=0)
	{
		if(balance<limit)
		{
			total=extra;
		}

		if(check<20)
		{
			checkFee=0.10*check;
			total=total+checkFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}

		if(check>=20&&check<=39)
		{
			checkFee=0.08*check;
			total=total+checkFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}

		else if(check>=40&&check<=59)
		{
			checkFee=0.06*check;
			total=total+checkFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}

		else if(check>=60)
		{
			checkFee=0.04*check;
			total=total+checkFee+regular;
			cout<<setprecision(2)<<fixed;
			cout<<"Bank service charges for the month: "<<"$ "<<total<<endl;
		}


	}
	else
	{

		cout<<"ERROR!!!You entered negative value."<<endl;
	}



	}

	//balance condition else
	else
	{

		cout<<"ERROR!!! You entered negative value. Account overdrawn. ."<<endl;
	}

    return 0;

}