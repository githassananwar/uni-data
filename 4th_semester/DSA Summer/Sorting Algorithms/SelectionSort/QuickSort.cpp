#include <iostream>
using namespace std ;

void quickSort(int * arr, int l ,int u) ;
int getPivot(int * arr, int l , int u) ;

int main()
{
	const int size = 12 ;
	int arr[size] = {10,5,2,36,20,21,50,2,31,15,12,11} ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl << endl << endl ;
	quickSort(arr,0,size-1) ;
	for(int i = 0 ; i < size ; i++)
		cout << arr[i] << " " ;
	cout << endl ;
	return 0 ;
}

void quickSort(int * arr, int l ,int u) 
{
	if(u <= l)
		return ;
	int p = getPivot(arr,l,u) ;
	quickSort(arr,l,p-1) ;
	quickSort(arr,p+1,u) ;
}

int getPivot(int * arr, int l ,int u)
{
	int i = l+1, j = u ;
	int x = arr[l] ;
	while (i <= j)
	{
		while ( i <= u && arr[i] <= x)
		{
			i++ ;
		}
		while (j > l && arr[j] >= x)
		{
			j-- ;
		}
		if(i <= j)
		{
			int temp = arr[i] ;
			arr[i] = arr[j] ;
			arr[j] = temp ;
		}
		else
		{
			int temp = arr[l] ;
			arr[l] = arr[j] ;
			arr[j] = temp ;
			break ;
		}
	}
	return j ;
}