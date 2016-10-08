#include <iostream>

using namespace std ;

void selectionSort(int* arr, int size) ;
int findMinIndex(int*arr, int size, int start) ;
void swap(int * arr, int i1, int i2) ;

int main() 
{
	int arr[4] = {2 ,4 ,1 ,6} ;
	for(int i = 0 ; i < 4 ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	selectionSort(arr,4) ;
	for(int i = 0 ; i < 4 ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	return 0 ;
}

void selectionSort(int * arr, int size)
{
	int minIndex = 0 ;
	for(int i = 0 ; i < size ; i++)
	{
		minIndex = findMinIndex(arr, size, i) ;
		swap(arr,i,minIndex) ;
	}
}

int findMinIndex(int * arr, int size, int start)
{
	int min = start ;
	for(int i = start ; i < size ; i++)
	{
		if (arr[min] > arr[i])		//change it to make it descending order
			min = i ;
	}
	return min ;
}

void swap(int * arr, int i1, int i2)
{
	int temp = arr[i1] ;
	arr[i1] = arr[i2] ;
	arr[i2] = temp ;
}