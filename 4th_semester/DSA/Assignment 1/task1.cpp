#include<iostream>

using namespace std;

int sum(int N)
{
	int sum = 0;

	for (int k = N; k > 0; k /= 2)			//log2(N)+1
                                            //log2(N) * (2N-1)
		for (int i = 0; i < k; i++)         //N
                                            //N-1
			sum++;			               //1

		return sum;
}

int main()
{
	int x = sum(10);
	cout << "Sum is " << x << endl;
}


//So the Time Equation of the Function is log2(N)+1 + log2(N) * (2N-1) or log2(N) (2N)
