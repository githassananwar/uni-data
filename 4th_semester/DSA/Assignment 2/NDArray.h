#ifndef NDARRAY_H
#define NDARRAY_H
#include<iostream>
using namespace std;
template<typename T>
class NDArray
{
private:
	int* dimension;
	int* startingIndex;
	int noOfDimension;
	T* data;
	int size;

public:
	NDArray(int noOfDimension=0, T* dimension=0, int* startingIndex=0)
	{
		size=1;
		this->noOfDimension=noOfDimension;
		this->startingIndex=startingIndex;
		this->dimension=dimension;

		for(int i=0; i<noOfDimension; i++)
		{
			size=size*dimension[i];
		}
		data= new T [size];

	}

	NDArray(const NDArray & arr)
	{
		size=arr.size;
		noOfDimension=arr.noOfDimension;
		startingIndex=arr.startingIndex;
		dimension=arr.dimension;

		data=new T [size];

		for(int i=0;i<size;i++)
		{
			data[i]=arr.data[i];
		}

	}

	NDArray& NDArray:: operator=(const NDArray & arr)
	{
		if(this!=&arr)
		{
			size=arr.size;
			noOfDimension=arr.noOfDimension;
			startingIndex=arr.startingIndex;
			dimension=arr.dimension;

			delete [] data;
			data=new T [size];

			for(int i=0;i<size;i++)
			{
				data[i]=arr.data[i];
			}
		}

		return *this;
	}

	int calculateIndex(int* indexSet)
	{
		int index=0, dimProduct=1, inStart=1;
		for(int i=0; i<noOfDimension; i++)
		{
			dimProduct=1;
			for(int j=inStart; j<=noOfDimension-1; j++)
			{
				 dimProduct=dimProduct*dimension[j];
			}

			if(indexSet[i]>=startingIndex[i] && indexSet[i]<startingIndex[i]+dimension[i])
			{
				dimProduct=dimProduct* (indexSet[i]-startingIndex[i]);
				index=index+dimProduct;
				inStart++;
			}
			else
			{
				exit(0);
			}
		}

		return index;

	}


	void setValue(int* indexSet, T value)
	{
		data[calculateIndex(indexSet)]=value;
	}

	T getValue(int* indexSet)
	{
	
		return data[calculateIndex(indexSet)];

	}

	int get1DIndex(T val)
	{
		for(int i=0;i<size;i++)
		{
			if(data[i]==val)
			{
				return i;
			}
		}
		return -1;
	}

	~NDArray()
	{
		delete [] data;
		data=0;
	}
};

#endif