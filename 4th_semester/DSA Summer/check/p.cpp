#include <iostream>

using namespace std;

int cal(int a[], int n)
{
	
	if(n<=0)
	{
		return 0;
	}

	if(a[n-1]%2==0)
	{
		return 1+cal(int a[],int n-1);
	}

	return cal(a, n-1);

}

int main()
{
	int a[]={1,2,3,4, 6, 8};
	cout<<cal(a,6)<<endl;

	return 0;
}