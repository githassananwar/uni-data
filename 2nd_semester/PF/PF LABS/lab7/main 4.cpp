#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>


using namespace std;

void coinToss(int count);
void times();



int main()
{
	times();


	return 0;

}


void times()
{
	int tosses=0;
	cout<<"Enter number of tosses you want: ";
	cin>>tosses;

	coinToss(tosses);

}


void coinToss(int count)
{
	int x, y;
	int i=1;

	unsigned seed=time(0);
	srand(seed);


	while(i<=count)
	{

		x=rand()%2+1;

		if(x==1)
		{
			cout<< "Head it is. ." <<endl;
		}
		if(x==2)
		{
			cout<< "Tail it is. ." <<endl;
		}

		i++;


	}


}
