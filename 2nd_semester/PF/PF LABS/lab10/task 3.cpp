#include<iostream>

using namespace std;

void specialSearch(int[],int,int,int&,int&);
int findMedian(int[], int);

int main ()
{

	int const SIZE=9;

	int arr[SIZE]={3,5,4,11,10,14,32,1,12};

	cout << "Median is: " << findMedian(arr, SIZE) << endl;

    return 0;

}

void specialSearch(int arr[], int n, int key, int &numLess, int &numGreat)
{
	int count=0;
	for(count=0; count<n; count++)
	{
		if(arr[count]<key)
		{
			numLess++;

		}
		else if(arr[count]>key)
		{
			numGreat++;

		}

	}

}

int findMedian(int arr[], int n)
{
	int count=0, key=0;
	int countL=0, countG=0;
	for(count=0; count<n; count++)
	{
		countL=0, countG=0;
		key = arr[count];
		specialSearch(arr, n, key, countL, countG);
		if(countL == countG)
		{
			return key;

		}

	}



}
