#include<iostream>
#include<iomanip>

using namespace std;

int main ()
{
    
	double weight=0, rate=0;
	double mile=0, per=500;
	double total=0;

	cout<<"Enter weight of your package: ";
	cin>>weight;

	if(weight<0||weight>20)
	{
		cout<<"ERROR!!! Weight not in our range. ."<<endl;
	}
	else
	{
		cout<<"Enter distance in miles: ";
		cin>>mile;

		if(mile<10||mile>3000)
		{
			cout<<"ERROR!!! Distance not in our range. ."<<endl;
		}
		else
		{
			if(weight<=2)
			{
				rate=1.10;
				total

			}
		}


	}

    return 0;

}