#include<iostream>

using namespace std;


int main ()
{
    unsigned short num=0, i=1;
	int size=0;

	cout<<"Enter number: ";
	cin>>num;

	size=sizeof(short)*8-1;

	cout<<size<<endl;

	i=i<<size;
	

	for(int j=1;j<=size+1;j++)
	{
		if(num&i)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		i=i>>1;
		if(j%8==0)
		{
			cout<<" ";
		}
	}
	
	cout<<endl;
	return 0;

}