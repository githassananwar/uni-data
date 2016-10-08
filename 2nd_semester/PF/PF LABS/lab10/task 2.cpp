#include<iostream>

using namespace std;

void specialSearch(int[], int, int, int&, int&);

int main ()
{

	int const size=8;
    int  countL=0, countG=0, key=10;

	int arr[size]={3,5,4,11,10,14,32,1};

	specialSearch(arr, size, key, countL, countG);
   
    return 0;

}

void specialSearch(int arr[], int n, int key, int &numLess, int &numGreat)
{
	int count=0;
	for(count=0; count<n; count++)
	{
		if(arr[count]<key)
		{
			numLess++;
			
		}
		else if(arr[count]>key)
		{
			numGreat++;
			
		}


	}

	cout << "Total number of Numbers less than key num " << key << " :"<<numLess<<endl;
	cout << "Total number of Numbers greater than key num " << key << " :"<<numGreat<<endl;


}
