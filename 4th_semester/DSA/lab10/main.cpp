#include "SegmentTree.h"

#include<iostream>
using namespace std;

int main()
{
	int arr[]={1,3,5,7,9,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	SegmentTree<int> st(arr,n);
	
	cout<<"Sum: "<<st.getSum(n,2,4)<<endl;

	st.updateValue(arr,n,2,22);

	cout<<"Updated Sum: "<<st.getSum(n,2,4)<<endl;
	
	return 0;
}