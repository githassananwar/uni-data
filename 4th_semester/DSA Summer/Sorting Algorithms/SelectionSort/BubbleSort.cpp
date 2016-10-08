#include <iostream>
using namespace std ;

void bubbleSort(int * arr, int size) ;
void swap(int * arr, int i1, int i2) ;

int main()
{
	int arr[4] = {4 ,3 ,2 ,1} ;
	for(int i = 0 ; i < 4 ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	bubbleSort(arr,4) ;
	for(int i = 0 ; i < 4 ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	return 0 ;
}

void bubbleSort(int * arr, int size)
{
	bool sorted = false ;
	int i = 0, j = 0 ;
	int count = 1 ;
	for(i = size-1 ; i >= 0 && !sorted ; i--)
	{
		sorted = true ;
		for(j = 0 ; j < i ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr,j,j+1) ;
				sorted = false ;
			}
		}
	}
}

void swap(int * arr, int i1, int i2)
{
	int temp = arr[i1] ;
	arr[i1] = arr[i2] ;
	arr[i2] = temp ;
}