#include<iostream>

using namespace std;

void sortArray(int* arr, int size);

int main()
{
	int arr[10]={-1,1,1,1,1,0,0,0,-1,0};
	sortArray(arr,10);

	cout<<"Sorted Array: ";
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}

void sortArray(int* arr, int size)
{
	int tempArr[3]={0};
	for(int i=0;i<size;i++)
	{
		if(arr[i]==-1)
		{
			tempArr[0]++;
		}
		else if(arr[i]==0)
		{
			tempArr[1]++;
		}
		else if(arr[i]==1)
		{
			tempArr[2]++;
		}
	}

	int currentIndex=0;

	for(int i=0;i<tempArr[0];i++)
	{
		arr[currentIndex]=-1;
		currentIndex++;
	}

	for(int i=0;i<tempArr[1];i++)
	{
		arr[currentIndex]=0;
		currentIndex++;
	}

	for(int i=0;i<tempArr[2];i++)
	{
		arr[currentIndex]=1;
		currentIndex++;
	}


}