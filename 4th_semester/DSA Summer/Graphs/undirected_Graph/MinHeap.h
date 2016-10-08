#ifndef MINHEAP_H
#define MINHEAP_H

template <typename T>
class MinHeap
{
	int height ;
	T * data ;
	int noOfNodes ;
	void swap(int parent,int curr) ;
public:
	MinHeap(int height);
	void insert(T val) ;
	T remove() ;
	void displayTree() ;
	bool isEmpty() ;
	~MinHeap();
};

template <typename T>
bool MinHeap<T>::isEmpty()
{
	return noOfNodes == 0 ;
}

template <typename T>
void MinHeap<T>::displayTree()
{
	for(int i = 0 ; i < noOfNodes ; i++)
		cout << data[i].u << " " << data[i].v << " " << data[i].weight  << "\n";
	cout << endl ;
}

template <typename T>
MinHeap<T>::MinHeap(int noOfNodes)
{
	if(noOfNodes < 1)
		throw "Invalid Height" ;
	this->height = ceil(log(double(noOfNodes+1))/ log(double(2))) ;
	data = new T[pow(2.0,(double)height) - 1] ;
	this->noOfNodes = 0 ;
}

template <typename T>
void MinHeap<T>::insert(T val) 
{
	data[noOfNodes] = val ;
	int curr = noOfNodes ;
	noOfNodes++ ;
	int p = (curr - 1) / 2 ;
	while (p >= 0 && data[p] > data[curr])
	{
		if(data[p] > data[curr])
		{
			swap(p,curr) ;
		}
		curr = p ;
		p = (curr - 1) / 2 ;
	}
}

template <typename T>
void MinHeap<T>::swap(int parent, int curr)
{
	if(parent < noOfNodes && curr < noOfNodes)
	{
		T temp = data[parent] ;
		data[parent] = data[curr] ;
		data[curr] = temp ;
	}
}

template <typename T>
T MinHeap<T>::remove()
{
	T temp = data[0] ;
	data[0] = data[noOfNodes-1] ;
	noOfNodes-- ;
	int curr = 0 ;
	while(curr < noOfNodes)
	{
		if(curr*2+1 < noOfNodes &&  curr*2+2 < noOfNodes)
		{
			if(data[curr*2+1] < data[curr*2+2])
			{
				if(data[curr] > data[curr*2+1])
				{
					swap(curr,curr*2+1) ;
				}
				curr = curr*2+1 ;
			}
			else
			{
				if(data[curr] > data[curr*2+2])
				{
					swap(curr,curr*2+2) ;
				}
				curr = curr*2+2 ;
			}
		}
		else if (curr*2+1 < noOfNodes)
		{
			if(data[curr] > data[curr*2+1])
			{
				swap(curr,curr*2+1) ;
			}
			curr = curr*2+1 ;
		}
		else
			break ;
	}
	return temp ;
}

template <typename T>
MinHeap<T>::~MinHeap()
{
	if(data)
	{
		delete [] data ;
		data = NULL ;
	}
}
#endif