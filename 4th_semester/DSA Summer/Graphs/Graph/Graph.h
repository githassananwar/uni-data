#ifndef GRAPH_H
#define GRAPH_H

#include "MyQueue.h"
#include <iostream>
#include "MinHeap.h"
using namespace std ;

struct Edge
{
	int u ; 
	int v ;
	Edge(int u = 0 , int v = 0)
	{
		this->u = u ;
		this->v = v ;
	}
};

class Graph
{
	int vertices ;
	int ** data ;

	Graph BFSWH(int sv, bool * visited, Graph & g) ;
	void DFSWH(Graph & g ,int sv, bool * visited) ;
	bool checkBackEdge(int * discovery, int* finish, int index1, int index2) ;
	void isCyclicHorse(int sv, bool * visited, int * discovery, int* finish, int & time) ;
	void isStronglyConnectedHorse(int sv, bool * visited, int ** graph) ;
	void displayHorse(int sv , bool* visited) ;
public:
	Graph(int vertices) ;
	Graph(const Graph & obj) ;
	Graph & operator=(const Graph & obj) ;
	void addEdge(int u, int v, int weight = 1 ) ;
	void removeEdge(int u, int v) ;
	Graph BFS(int sv) ;
	Graph DFS(int sv) ;
	int stronglyConnectedComponentsNumber() ;
	bool isStronglyConnected() ;
	void displayMatrix() ;
	void display() ;
	bool isACyclic() ;
	~Graph() ;
};
#endif 