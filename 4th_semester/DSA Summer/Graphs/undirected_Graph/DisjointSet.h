#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include<iostream>
using namespace std;

class DisjointSet
{
	int *data ;
public:
	DisjointSet(int size) ;
	bool isConnected(int data1, int data2 ) ;
	int find(int node) ;
	void Union(int node1, int node2) ;
	~DisjointSet();

	void display(int size) ;

};

#endif