#include<iostream>

using namespace std;

bool isPerfect(int);

int main ()
{
    int count=1;

	cout << "Perfect Numbers between 1 and 1000:-" << endl;

	while(count <= 1000)
	{
		if(isPerfect(count))
		{
			cout << count << endl;
		}
		count++;
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