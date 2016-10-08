/* HASSAN ANWAR 
BSEF12M014 - SE Morning */

#include<iostream>
using namespace std;

int main ()
{
	//Variable Declaration.
    int size=0;

	/*countRow is for vertical and
	countColumn is for horizontal printing.*/
	int countRow=1, countColumn=1;

	//for spaces
	int space=0, countSpace=0;


	//Prompt lines to take dimension size.
	cout << "Enter size: ";
	cin >> size;

	//Size validation
	while(size<2)
	{
		cout << "Invalid size!!! Enter again: ";
		cin >> size;
	}

	
	/*Main loop terminates as row counter crosses
	size value.*/
	while(countRow <= size)
	{

		//loop to print spaces at each row. 
		for(countSpace=0; countSpace<space; countSpace++)
		{
			cout << " ";
		}

		//loop to print *'s after printing of spaces.
		for(countColumn=1; countColumn<=size; countColumn++)
		{
			cout << "*";	
		}
		
		//Increment in row & space count.
		space++;
		countRow++;

		//For new line before next iteration of main loop.
		cout << endl;
		

	}

   
    return 0;

}