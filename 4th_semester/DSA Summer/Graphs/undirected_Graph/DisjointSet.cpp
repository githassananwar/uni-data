#include "DisjointSet.h"





void DisjointSet::display(int size)
{
	for(int i = 0 ; i < size ; i++ )
		cout << data[i] << " " ;
	cout << endl ;
	cout << "\n" ;
}

















DisjointSet::DisjointSet(int size)
{
	if(size < 1)
		throw "Invalid size.\n" ;
	this->data = new int[size] ;
	for (int i = 0 ; i < size ; i++)
		data[i] = -1 ;
}

bool DisjointSet::isConnected(int data1, int data2)
{
	return find(data1) == find(data2) ;
}

int DisjointSet::find(int node)
{
	if(data[node] < 0 )
		return node ;
	data[node] = find(data[node]) ;
	return data[node] ;
}

void DisjointSet::Union(int node1, int node2)
{
	int root1, root2 ;
	root1 = find(node1) ;
	root2 = find(node2) ;
	if(data[root1] <= data[root2])
	{
		data[root1] = data[root1] + data[root2] ;
		data[root2] = root1 ;
	}
	else
	{
		data[root2] = data[root1] + data[root2] ;
		data[root1] = root2 ;
	}
}

DisjointSet::~DisjointSet(void)
{
	if(data)
	{
		delete [] data ;
		data = NULL ;
	}
}
