#include<iostream>

using namespace std;

int findIndex(int* arr,int startIndex, int size);

int main()
{
	int arr[6]={8,11,12,13,7,14};
	cout<<"Index: "<<findIndex(arr,0,6)<<endl;

	return 0;
}

int findIndex(int* arr,int startIndex, int size)
{
	int mid = (startIndex+size)/2;

	if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
	{
		return mid;
	}
	else if(arr[mid] > arr[mid-1])
	{
		return findIndex(arr,mid,size-1);
	}
	else if(arr[mid] < arr[mid-1])
	{
		return findIndex(arr,startIndex,mid-1);
	}
	
}