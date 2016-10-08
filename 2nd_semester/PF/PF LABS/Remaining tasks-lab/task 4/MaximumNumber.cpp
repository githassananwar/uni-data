#include<iostream>

using namespace std;


int calculateMaximum(int* data)
{
	int max=data[0];

	for(int i=1; i<10; i++)
	{
		if(data[i]>max)
		{
			max=data[i];
		}
	}

	return max;

}

int withnoParameters()
{
	int arr=10;

	return arr;
}

void hello()
{
	cout<<"Hello wORLD"<<endl;
}

void displayData(int max)
{
	cout<<"Maximum number is: "<<max;
}


int main()
{
	int data[10];
	
	for(int i=0;i<10;i++)
	{
		cout<<"Enter number "<<i+1<<" :";
		cin>>data[i];
	}

	int max =calculateMaximum(data);


	displayData(max);

}










