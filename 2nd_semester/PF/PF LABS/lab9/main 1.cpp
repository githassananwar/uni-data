#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	int const size=12;
	double average=0, total=0;
	int count=0, max=0, min=0;
	int monthH=0, monthL=0;


	double rain[size];

	for(count=0; count<size; count++)
	{
		cout<<"Enter Month "<<count+1<<" rainfall(mm): ";
		cin>>rain[count];
		while(rain[count]<0)
		{
			cout<<"Error!!! Negative entry for Month "<<count+1<<", Enter again: ";
			cin>>rain[count];
		}

		if(count==0)
		{
			max=rain[count];
			min=rain[count];
		}
		else 
		{
			if(rain[count]>max)
			{
				max=rain[count];
				monthH=count+1;

			}
			else if(rain[count]<min)
			{
				min=rain[count];
				monthL=count+1;
			}

		}

	}

	for(count=0; count<size; count++)
	{
		total=total+rain[count];


	}

	average=total/12;

	cout<<endl<<"Total rainfall for the year: "<<total<<endl;;

	cout<<setprecision(2)<<fixed<<"Average monthly rainfall: "<<average<<endl;

	cout<<"Month having highest rainfall: "<<monthH<<endl;

	cout<<"Month having lowest rainfall: "<<monthL<<endl;
    
   


    return 0;

}