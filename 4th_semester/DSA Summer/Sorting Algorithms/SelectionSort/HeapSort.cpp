#include <iostream>
using namespace std ;

void HeapSort(int * arr, int size) ;
void Heapify(int * arr, int size, int root) ;
void buildHeap(int* arr, int size) ;
void dispArray(int * arr, int size) ;
int getMin(int* arr, int size) ;

int main()
{
	const int size = 12 ;
	int arr[size] = {10,5,2,36,20,21,50,2,31,15,12,11} ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl << endl << endl ;
	HeapSort(arr,size) ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	return 0 ;
}

void HeapSort(int * arr, int size)
{
	buildHeap(arr,size) ;
	dispArray(arr,size) ;
	int temp = 0 ;
	for(int i = size-1 ; i >= 0 ; i--)
	{
		temp = getMin(arr,i) ;
		arr[i] = temp ;
		dispArray(arr,size) ;
	}
}

void buildHeap(int * arr, int size )
{
	for(int i = (size-1)/2 ; i >= 0 ; i--)
		Heapify(arr,size,i) ;
}

int getMin(int * arr, int size)
{
	int temp = arr[0] ;
	arr[0] = arr[size] ;
	Heapify(arr,size,0) ;
	return temp ;
}

void Heapify(int * arr, int size , int root)
{
	int max = -1, temp = 0 ;
	while (root < size)
	{
		if(root*2+1 < size && root * 2 + 2 < size)
		{
			if(arr[root*2+1] > arr[root*2+2])
				max = root*2+1 ;
			else
				max = root*2+2 ;
		}
		else if (root*2+1 < size)
			max = root*2+1 ;
		else 
			break ;
		if(max != -1 && (arr[root] < arr[max]))
		{
			temp = arr[root] ;
			arr[root] = arr[max] ;
			arr[max] = temp ;
		}
		root = max ;
	}
}

void dispArray(int* arr, int size)
{
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
}