#include<iostream>

using namespace std;

char *getString();

int main ()
{
	char *mainPtr=getString();
	cout<<mainPtr<<endl;

	delete [] mainPtr;
	mainPtr=0;

    return 0;

}
char *getString()
{
	int const SIZE=80;
	int count=0,askii=1,shortSize=0;
	char arr[SIZE];

	cout<<"Enter the sentence: ";
	cin>>arr;

	for(count=0;askii!=0;count++)
	{
		askii=arr[count];
	}

	shortSize=count;
	cout<<shortSize<<endl;

	char *ptr=new char[shortSize];

	for(count=0;count<shortSize;count++)
	{
		*(ptr+count)=arr[count];
	}
	return ptr;

}
