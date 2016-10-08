#include <iostream>
#include <ctime>
using namespace std ;
template <typename T>
void shuffle(T * arr , int N )
{
	T temp ;
	int j = 0 ;
	srand(time(0));
	for(int i=0;i<N-1;i++)
	{
		j=i+rand()%(N-i-1) + 1 ;
		temp = arr[j];
		arr[j] = arr[i] ;
		arr[i] = temp ;
	}
}
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	char arr2[18] = {"My name is Rizwan"};
	shuffle<int>(arr,10);
	for(int i=0;i<10;i++)
	{
		cout << arr[i] << " " ; 
	}
	cout << endl;
	return 0 ;
}