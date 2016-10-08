/* HASSAN ANWAR 
BSEF12M014 - SE Morning */

#include<iostream>
using namespace std;

int main ()
{

	//Variable Declaration.
	int start=0, end=0;				
	int countStart=0, countEnd=0;

	//Prompt lines to take input.
	cout << "Enter starting integer: ";
	cin >> start;

	cout << "Enter ending integer: ";
	cin >> end;


	/*Main loop terminates as starting integer
	becomes greater than ending integer.*/
	while(start <= end)
	{

		/*At the start of each iteration of main loop, starting
		integer value is assigned to both counters.*/
		countStart = start;
		countEnd = start;

		/*Second loop terminates as start counter becomes 
		greater than ending integer value.*/
		while(countStart <= end)
		{
			cout << "(" << start << "," << countEnd << ") ";
			
			//Incrementing both counter values.
			countStart++;
			countEnd++;

		}

		//For new line before next iteration of main loop.
		cout << endl;

		/*Increment in starting integer & decrement in ending
		integer value at the end of each main loop iteration.*/
		start++;
		end--;
		

	}
  

	return 0;


}