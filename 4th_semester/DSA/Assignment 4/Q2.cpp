#include<iostream>

using namespace std;

void displayPartition(int);
void recursiveCalculation(int, int, int);

int main()
{
	int num;
	cout<<"Enter number: ";
	cin>>num;

	displayPartition(num);

	return 0;
}

void displayPartition(int num)
{
	int n=1, diff=1;
	recursiveCalculation(num, n, diff);
}

void recursiveCalculation(int num, int n, int diff)
{
	int sumInc=n, count=1;

	if(n==num)
	{
		return;
	}

	while(sumInc<=num)
	{
		sumInc=sumInc+diff;
		if(sumInc==num)
		{
			cout<<n;
			for(int i=0;i<count;i++)
			{
				cout<<" "<<diff<" ";
			}
			cout<<endl;
			break;
		}
		count++;
	}

	if(n+diff>num)
	{
		n++;
		diff=0;
	}

	recursiveCalculation(num, n, diff+1);

}