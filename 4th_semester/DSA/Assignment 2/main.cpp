#include "NDArray.h"
#include<iostream>

using namespace std;

int main()
{
	int dimSize[3]={5,3,10};
	int startingIndex[3] = {-3,0,10};
	NDArray<int> arr(3,dimSize, startingIndex); // first parameter = number of dimension
	// second parameter = size of each dimension
	int indexSet[3]={-3,0,11};
	arr.setValue( indexSet , 2);

	cout<<"Value: "<<arr.getValue(indexSet)<<endl;
	
	cout<<"One D index: "<<arr.get1DIndex(2)<<endl;
	
	return 0;
}