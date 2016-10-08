#include<iostream>

using namespace std;

double *median(int[],int);

int main ()
{
	int const SIZE=6;
	int arr[SIZE]={4,5,6,7,9,10};

	cout<<"Median is: "<<*median(arr,SIZE)<<endl;

    return 0;

}

double *median(int arr[],int SIZE)
{
	int n1=0, n2=0;
	double mid=0;

	double *ptr=&mid; //pointer for median. .

	if(SIZE%2==0)
	{
		n1=SIZE/2-1;
		n2=n1+1;
		*ptr=static_cast<double>(arr[n1]+arr[n2])/2;
	}
	else
	{
		*ptr=arr[(SIZE/2)];

	}

	return ptr;

}