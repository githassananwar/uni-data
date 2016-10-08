/* HASSAN ANWAR 
BSEF12M014 - SE Morning */

#include<iostream>
using namespace std;

int main ()
{

	//Variable Declaration.
	/*'row' represents height(vertical) and
	'coulmn' represents width(horizontal)*/
    int row=0, column=0;

	//counters for row and columns.
	int countRow=1, countColumn=1;


	//Prompt lines to take height as input.
	cout << "Enter height: ";
	cin >> row;

	//Height validation.
	while(row%2==0 || row<3)
	{
		cout << "Invalid height!!! Enter again: ";
		cin>>row;
	}


	//Prompt lines to take width as input.
	cout << "Enter width: ";
	cin >> column;

	//Width validation.
	while(column%2==0 || column<5)
	{
		cout << "Invalid width!!! Enter again: ";
		cin>>column;
	}


	/*Main loop terminates as row counter crosses
	row(height value).*/
	while(countRow <= row)
	{

		//to display +'s horizontally.
		for(countColumn=1; countColumn<=column; countColumn++)
		{
			
			//to display +'z without spaces in 1st, last and odd row.
			if(countRow==1 || countRow==row || countRow%2!=0)
			{
				cout << "+";
			}
			//for others. .
			else
			{
				//for each even column number print space. .
				if(countColumn%2==0)
				{
					cout << " ";
				}
				//for other columns print +. .
				else
				{
					cout << "+";
				}
			
			}

		}

		//For new line before next iteration of main loop.
		cout << endl;
		//Increment in row count.
		countRow++;
		
	}	


    return 0;

}