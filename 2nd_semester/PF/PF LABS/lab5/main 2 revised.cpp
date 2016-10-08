#include<iostream>

using namespace std;

int main ()
{
    
	int num=0, points=0;

	cout << "Enter number of books purchased: ";
	cin >> num;

	if(num==0)
	{
		points=0;
		cout << "You earned " << points << " points." << endl;
	}

	else if(num==1)
	{
		points=5;
		cout << "You earned " << points << " points." << endl;
	}

	else if(num==2)
	{
		points=15;
		cout << "You earned " << points << " points." << endl;
	}

	else if(num==3)
	{
		points=30;
		cout << "You earned " << points << " points." << endl;
	}

	else if(num>=4)
	{
		points=60;
		cout << "You earned " << points << " points." << endl;
	}

	else
	{
		cout << "ERROR!!! Books not in range. ." << endl;
	}
   


    return 0;

}