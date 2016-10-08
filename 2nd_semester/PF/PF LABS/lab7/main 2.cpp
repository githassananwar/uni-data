#include<iostream>

using namespace std;

int main ()
{

    int row=0, column=0;
	int countR=1, countC=1;

	cout << "Enter height of triangle: ";
	cin>>row;
	while(row%2!=0 || row<4)
	{
		cout << "Invalid height!!! Enter again: ";
		cin>>row;
	}


	cout << "Enter width of triangle: ";
	cin>>column;
	while(column%2!=0 || column<6)
	{
		cout << "Invalid width!!! Enter again: ";
		cin>>column;
	}


	while(countR<=row)
	{
		countC=1;
		while(countC<=column)
		{
			if((countR>1&&countR<row) && (countC> 1 && countC<column))
			{
				cout << " ";
			}
			else
			{
				cout << "*";

			}

			countC++;

		}

		cout<<endl;
		countR++;


	}
   


    return 0;

}