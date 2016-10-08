#include<iostream>

using namespace std;


int *allocateArray(int);

int main ()
{
	int size;
	int *output;
	cout<<"Enter the number of elements to allocate: ";
	cin>>size;
    
    
	int *ptr=allocateArray(size);

	cout<<"Returned value: "<<ptr<<endl;

	delete [] ptr;
	ptr=0;

    return 0;

}

int *allocateArray(int n)
{
	int *ptr=new int [n];
	return ptr;

}