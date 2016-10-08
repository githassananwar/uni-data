#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#include<cmath>
#include<iostream>
using namespace std;
template <typename T>
class SegmentTree
{
	T* st;
	bool* status;
	int size;

	int getSum(int node, int lb, int rb, int rangeL, int rangeR)
	{
		int sum=0, mid=floor((double)(lb+rb)/2);

		if(rangeL<=lb && rangeR>=rb)
		{
			return st[node];
		}
		if(2*node+1<size && status[2*node+1]==1)
		{
			sum=sum+getSum(2*node+1, lb, mid , rangeL , rangeR);
		}
		if(2*node+2<size && status[2*node+2]==1)
		{
			sum=sum+getSum(2*node+2, mid+1, rb , rangeL , rangeR);
		}

		return sum;

	}
	int updateST(int arr[], int ss, int se, int* st, int si)
	{
		if (ss==se)
		{
			st[si]=arr[ss];
			status[si]=1;
			return arr[ss];
		}

		int mid= getMid(ss,se);
		status[si]=1;
		st[si]=constructSTUntil(arr, ss, mid, st, si*2+1) + constructSTUntil(arr, mid+1, se, st, si*2+2);
		return st[si];

	}


public:
	SegmentTree(int arr[], int n)
	{
		int x = (int)(ceil( log((double)n)/log(2.0) ) );
		size = 2*(int)pow(2.0,x)-1;
		st=new T [size];
		status=new bool [size];

		for(int i=0; i<size; i++)
		{
			status[i]=0;
		}

		constructSTUntil(arr, 0, n-1, st, 0);
	}

	int constructSTUntil(int arr[], int ss, int se, int* st, int si)
	{	
		if (ss==se)
		{
			st[si]=arr[ss];
			status[si]=1;
			return arr[ss];
		}

		int mid= getMid(ss,se);
		status[si]=1;
		st[si]=constructSTUntil(arr, ss, mid, st, si*2+1) + constructSTUntil(arr, mid+1, se, st, si*2+2);
		return st[si];
	}

	int getMid(int s, int e)
	{	
		return s+(e-s)/2;
	}

	int getSum(int size, int l, int r)
	{
		 return getSum(0, 0, size-1, l, r);
	}

	void updateValue(T arr[], int size, int index, int value)
	{
		cout<<size<<endl;
		if(index>=0 && index<size)
		{
			arr[index]=value;
		}
		else
		{
			exit(0);
		}

		for(int i=0; i<size; i++)
		{
			status[i]=0;
		}
		updateST(arr, 0, size-1, st, 0);
		
	}

	~SegmentTree()
	{
		delete [] st;
		st=0;
	}

	
};

#endif