/* HASSAN ANWAR 
BSEF12M014 - SE Morning */

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main ()
{

	//Variable Declaration.
	int hyp=1, side1=1, side2=1;

	/*Limit variable upto which all combinations
	are to be shown.*/
	int limit=200;


	/*Main loop terminates as hypotenuse
	value cross the limit.
	Each 'for' loop inside Main loop for side1 & side2 also 
	terminates as they cross the limit.*/
	while(hyp<=limit)
	{
		
		/*At each iteration of main loop, side1 & side2 is assigned 1 to check
		all combinations with incrementing hypotenuse.*/
		for(side1=1; side1<=limit; side1++)
		{
			
			//Looking all values of side2 with incrementing side1. 
			for(side2=1; side2<=limit; side2++)
			{

				//Pythagorus formula check
				if( pow(side1,2.0) + pow(side2,2.0) == pow(hyp,2.0) )
				{

					//Formatting output by using setw().
					cout <<"Hyp= " << setw(3) << left << hyp;
					cout <<setw(6) << left << ", Side1= " << setw(3) << side1;
					cout <<setw(6) << left<< ", Side2= " << setw(3) << side2 << endl;

				}
				
			}
		
		}

		hyp++;

	}


	return 0;
   

}