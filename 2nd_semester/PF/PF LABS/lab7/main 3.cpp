#include<iostream>

using namespace std;

void printRectangle(int row, int column);
void getInput();

int main ()
{

   getInput();

   return 0;
	
}

	

void getInput()
{
	int height=0, width=0;

	cout << "Enter height of triangle: ";
	cin>>height;
	while(height%2!=0 || height<4)
	{
		cout << "Invalid height!!! Enter again: ";
		cin>>height;
	}


	cout << "Enter width of triangle: ";
	cin>>width;
	while(width%2!=0 || width<6)
	{
		cout << "Invalid width!!! Enter again: ";
		cin>>width;
	}


	printRectangle(height,width);

}


void printRectangle(int row, int column)
{
	int countR=1, countC=1;

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

}


  