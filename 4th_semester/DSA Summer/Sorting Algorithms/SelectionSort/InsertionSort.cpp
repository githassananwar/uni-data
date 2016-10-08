#include <iostream>
using namespace std ;

void insertionSort(int* arr, int size) ;

int main()
{
	const int size = 4 ;
	int arr[size] = {4,3,2,1} ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl << endl << endl ;
	insertionSort(arr,size) ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	return 0 ;
}

void insertionSort(int * arr, int size)
{
	int temp ;
	int i = 0 , j = 0 ;
	for(i = 1 ; i < size ; i++)
	{
		temp = arr[i] ;
		for(j = i-1 ; j >= 0 && arr[j] > temp ; j--)
		{
			arr[j+1] = arr[j] ;
		}
		arr[j+1] = temp ;
	}
}