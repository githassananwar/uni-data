#include<iostream>

using namespace std;

int *reverse(int[],int);

int main ()
{
	int count=0;
    int const SIZE=5;
	int arr[SIZE]={1,2,3,4,6};
    
	for(count=0;count<SIZE;count++)
	{
		cout<<*(reverse(arr,SIZE)+count)<<",";
	}
	
	cout<<endl;

    return 0;

}

int *reverse(int arr[],int SIZE)
{
	int count=0,revCount=SIZE-1;
	int const REVSIZE=5;
	int reverse[REVSIZE];
	int *ptr=reverse;

	for(count=0;count<SIZE;count++)
	{
		reverse[revCount]=arr[count];
		revCount--;

	}

	return ptr;

}