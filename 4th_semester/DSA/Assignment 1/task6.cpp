#include<iostream>

using namespace std;

template <typename T>
int findIndex(T* arr,int startIndex, int size);

int main()
{
	int arr[6]={-1,0,2,4,5,6};
	cout<<"Index: "<<findIndex(arr,0,6)<<endl;

	return 0;
}

template <typename T>
int findIndex(T* arr,int startIndex, int size)
{

	int mid=(startIndex+size)/2;

	if(startIndex<=size)
	{
		if(arr[mid]==mid)
		{
			return mid;
		}
		else if(arr[mid]>mid)
		{
			findIndex(arr,startIndex,mid-1);
		}
		else if(arr[mid]<mid)
		{
			findIndex(arr,mid+1,size);
		}
	}
	else
	{
		return -1;
	}

}