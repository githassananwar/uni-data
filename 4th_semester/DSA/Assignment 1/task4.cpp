#include<iostream>

using namespace std;

int findElement(int* arr, int size);

int main()
{
	int arr[5]={1,4,3,2,4};
	cout<<"Element missing: "<<findElement(arr,5)<<endl;

	return 0;
}

int findElement(int* arr, int size)
{
	int elementFound=-1;
	int* tempArr=new int [size];
	for(int i=0;i<size;i++)
	{
		tempArr[i]=0;
	}

	for(int i=0;i<size;i++)
	{
		tempArr[arr[i]]++;
	}

	for(int i=0;i<size;i++)
	{
		if(tempArr[i]==0)
		{
			elementFound=i;
		}
	}

	delete [] tempArr;

	return elementFound;
}