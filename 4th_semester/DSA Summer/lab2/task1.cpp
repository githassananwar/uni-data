#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

bool linearSearch (int arr[], int n, int value)
{
	int i = 0;
	while (i < n) {
		if (arr[i] == value)
			return true;
		i++;
	}
	return false;
}

bool binarySearch (int arr[], int n, int value)
{
	int mid, lBound = 0, uBound = n - 1;
	while (lBound <= uBound)
	{
		mid = (lBound + lBound) / 2;
		if (value > arr[mid])
			lBound = mid + 1;
		else if (value < arr[mid])
			uBound = mid - 1;
		else
			return true;
	}
	return false;
}


int main()
{
	SYSTEMTIME systime;
	GetLocalTime (&systime);
	cout <<"SYSTEM TIME: " << systime.wSecond << ' ' << systime.wMilliseconds << endl;


	const int SIZE=10000;
	ifstream fin("numbers_large_10000.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't found" << endl;
	}
	else
	{
		int arr[SIZE];
		for(int i=0;i<SIZE;i++)
		{
			fin>>arr[i];
		}
		
		cout<<endl; //------------------------------------------------------------------------------

		GetLocalTime (&systime);
		cout <<"INITIAL SYSTEM TIME: " << systime.wSecond << ' ' << systime.wMilliseconds << endl;

		if (linearSearch (arr, 10000, 5501))
			cout << "Linear search found it.\n";

		GetLocalTime (&systime);
		cout <<"FINAL SYSTEM TIME: " << systime.wSecond << ' ' << systime.wMilliseconds << endl;

		cout<<endl;//------------------------------------------------------------------------------

		GetLocalTime (&systime);
		cout <<"INITIAL SYSTEM TIME: " << systime.wSecond << ' ' << systime.wMilliseconds << endl;

		if (binarySearch (arr, 10000, 5501))
			cout << "Binary search found it.\n";

		GetLocalTime (&systime);
		cout <<"FINAL SYSTEM TIME: " << systime.wSecond << ' ' << systime.wMilliseconds << endl;


	}

	return 0;
}