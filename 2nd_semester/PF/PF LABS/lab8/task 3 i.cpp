#include<iostream>

using namespace std;


bool isPerfect(int);

int main ()
{
    int num=8;

	if(isPerfect(num))
	{
		cout <<num << " is a Perfect number." << endl;
	}
	else
	{
		cout << num << " is Not a Perfect number." << endl;
	}


	return 0;
}

bool isPerfect(int n)
{
	int count=1, sum=0;

	while(count<n)
	{
		if(n%count == 0)
		{
			sum = sum+count;
		}
		count++;
	}

	if(sum == n)
	{
		return true;

	}
	else
	{
		return false;
	}

}