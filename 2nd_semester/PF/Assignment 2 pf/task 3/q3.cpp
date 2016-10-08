/* HASSAN ANWAR 
BSEF12M014 - SE Morning */

#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{

	//Variable Declaration.
	int num=0;

	/*countRow represents numbers shown vertically(|).
	countColumn represents numbers shown horizontally(--).*/
	int countRow=1, countColumn=1;

	//'ans' represents product answer.
	int ans=0;


	//Prompt lines to take input.
	cout << "Enter number: ";
	cin >> num;


	/*Main loop terminates as as countRow becomes 
	greater than entered number.
	setw() is used to format the output by taking different
	widths for different outputs.*/
	while(countRow <= num)
	{
		
		/*Inside loop to display Horizontal numbers(top) in table.
		It will only run at 1st iteration of main loop.*/
		while(countColumn <= num)
		{
			
			//if else case for balancing output formatting.
			if(countColumn == 1)
			{
				cout << setw(8) << countColumn;
			}
			else
			{
				cout << setw(4) << countColumn;
			}

			//For new line before termination of the loop.
			if(countColumn == num)
			{
				cout << endl;
			}
			
			countColumn++;

		}



		//Inside if condition to display (+----) only when row counter is 1.
		if(countRow == 1)
		{
			/*Loop to manage length of (+----) according to numbers
			shown horizontally.*/
			for(countColumn=1; countColumn<=num; countColumn++)
			{
				//if else case for balancing output formatting.
				if(countColumn == 1)
				{
					cout << setw(8) << "+----";
				}
				else
				{
					cout << "----";
				}

				//For new line before termination of the loop.
				if(countColumn == num)
				{
					cout << endl;
				}

			}
		}


		//to display Vertical numbers at each iteration of Main loop.
		cout << setw(2) << countRow << setw(2) << "|";

		
		//Inside loop to diplay Product answers horizontally.
		for(countColumn=1; countColumn<=num; countColumn++)
		{
			ans = countColumn*countRow;

			cout << setw(4) << ans;
		
			//For new line before termination of the loop.
			if(countColumn == num)
			{
				cout << endl;
			}

				
		}
		
		
		/*Increment in countRow at end of each Main loop 
		iteration.*/
		countRow++;

	}

	//New line after termination of Main loop.
	cout << endl;


	return 0;
   
}