#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

using namespace std;

template<typename T>
class MinHeap
{
	int height;
	int numOfNodes;
	T* data;

	void heapUp(int root, int bottom)
	{
		if(bottom<=root)
			return;

		int parent=(bottom-1)/2;
		if(data[bottom]<data[parent])
		{
			int temp=data[parent];
			data[parent]=data[bottom];
			data[bottom]=temp;
		}

		heapUp(root,parent);
	}

	void heapDown(int root, int bottom)
	{
		if(root>=bottom)
			return;

		int lc=2*root+1, rc=2*root+2;
		if(lc<numOfNodes && data[root]>data[lc])
		{
			int temp=data[root];
			data[root]=data[lc];
			data[lc]=temp;
			heapDown(lc,bottom);
		}
		else if(lc<numOfNodes && data[root]>data[rc])
		{
			int temp=data[root];
			data[root]=data[rc];
			data[rc]=temp;
			heapDown(rc,bottom);
		}
		
	}


public:
	MinHeap()
	{
		height=0;
		numOfNodes=0;
		data=0;
	}

	MinHeap(int h)
	{
		height=h;
		data=new T[2*pow(height,2.0)-1];
		numOfNodes=0;
	}
	
	T getMinimum()
	{
		return data[0];
	}

	void insert(T val)
	{
		data[numOfNodes]=val;
		heapUp(0,numOfNodes);
		numOfNodes++;
	}

	void remove()
	{
		if(numOfNodes>0)
		{
			data[0]=data[numOfNodes-1];
			numOfNodes--;
			heapDown(0,numOfNodes);
		}
	}

	void display()
	{
		for(int i=0;i<numOfNodes;i++)
		{
			cout<<data[i]<<"   ";
		}
		cout<<endl;

	}

	~MinHeap()
	{
		delete [] data;
		data=0;
	}

};

#endif