#include<iostream>

using namespace std;

int main ()
{

    int num=1, countDivisor=1, count=0;

	while(num<=1000)
	{
		count=0;
		countDivisor=1;

		while(countDivisor<=num)
		{
			if(num%countDivisor==0)
			{
				count++;
			}

			countDivisor++;

		}

		if(count==2)
		{
			cout << "Prime number: " << num << endl;

		}

		num++;
	

	}

   


    return 0;

}