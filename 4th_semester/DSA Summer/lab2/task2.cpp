#include<iostream>

using namespace std;

void findNext(char* number, int length)
{
	char temp=0; 
	int index=-1;
	
	for(int i=length-2;i>=0;i--)
	{
		if((int)number[i]<(int)number[i+1])
		{
			temp=number[i];
			number[i]=number[length-1]; //Replacing it with last index
			number[length-1]=temp;
			index=i;
			break;
		}
	}

	if(index!=-1)
	{
		//Arranging remaining(after index) in ascending order
		int i=index+1, j=length-1;
		for(int count=0; count<(length-index)/2; count++)
		{	
			temp=number[j];
			number[j]=number[i];
			number[i]=temp;
			
			i++;
			j--;
		}
		cout<<number<<endl;

	}
	else
	{
		cout<<"Not possible"<<endl;
	}
}

int main()
{
	char number[]="218765";
	findNext(number,6);

	return 0;
}