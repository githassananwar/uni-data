#include <iostream>
using namespace std ;

void mergeSort(int* arr, int l, int u) ;
void merge(int * arr, int l1, int u1, int l2 , int u2 ) ;

int main()
{
	const int size = 12 ;
	int arr[size] = {10,5,2,36,20,21,50,2,31,15,12,11} ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl << endl << endl ;
	mergeSort(arr,0,size-1) ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	return 0 ;
	return 0 ;
}

void mergeSort(int* arr, int l, int u) 
{
	if(u <= l)
		return ;
	int mid = l + (u-l) / 2 ;
	mergeSort(arr,l,mid) ;
	mergeSort(arr,mid+1,u) ;
	merge(arr,l,mid,mid+1,u) ;
}

void merge(int * arr, int l1, int u1, int l2 , int u2 ) 
{
	int size1 = u1 - l1 + 1 ;
	int size2 = u2 - l2 + 1 ;
	int size3 = size1 + size2 ;
	int * m = new int [size3] ;
	int i = l1 , j = l2, k = 0 ;
	while (i <= u1 && j <= u2)
	{
		if(arr[i] <= arr[j])
			m[k++] = arr[i++] ;
		else
			m[k++] = arr[j++] ;
	}
	while ( i <= u1)
	{
		m[k++] = arr[i++] ;
	}
	while (j <= u2)
	{
		m[k++] = arr[j++] ;
	}
	i = l1 ;
	k = 0 ;
	while (k < size3)
	{
		arr[i++] = m[k++] ;
	}
	delete [] m ;
}