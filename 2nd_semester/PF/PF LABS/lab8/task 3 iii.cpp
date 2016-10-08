#include<iostream>

using namespace std;

bool isPerfect(int);

int main ()
{
    int num=1, count=1;

	cout << "Perfect Numbers between 1 and 1000:-" << endl;

	while(num <= 1000)
	{
		if(isPerfect(num))
		{
			cout << num << endl;
			cout << "Factors of " << num << " are:- ";
			for(count=1; count<num; count++)
			{
				if(num%count == 0)
				{
					cout << count << "  ";
				}

			}	
			cout << endl << endl;
			
		}

		num++;

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