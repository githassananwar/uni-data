#include<iostream>

using namespace std;

template <typename T>
int findRank(T* arr, T size, T element);

int main()
{
	int arr[7]={41, 29, 55, 1, 8, 2, 17};
	cout<<"Rank: "<<findRank(arr,7,8)<<endl;

	return 0;
}

template <typename T>
int findRank(T* arr, T size, T element)
{
	int count =0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]<element)
		{
			count++;
		}
	}

	return count;
}