#include<iostream>

using namespace std;

int main ()
{
	int const size=20;
	char ansC[size]={'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D',
					 'C','C','B','D','A'};
	char ansIp[size];

	int count=0, correct=0, wrong=0;
    
	for(count=0; count<size; count++)
	{
		cout<<"Enter question "<<count+1<<"answer: ";
		cin>>ansIp[count];

	}

	for(count=0; count<size; count++)
	{


	}
   


    return 0;

}