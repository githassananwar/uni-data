#ifndef UNDIRECTED_UndirectedGraph_H
#define UNDIRECTED_UndirectedGraph_H

#include "MyQueue.h"
#include <iostream>
#include "MinHeap.h"
#include "DisjointSet.h"
using namespace std ;

struct tuple
{
	int u ;
	int v ;
	int weight ;
	tuple(int u = 0 ,int v = 0 ,int wt = 0)
	{
		this->u = u ;
		this->v = v ;
		this->weight = wt ;
	}
	bool operator<(const tuple & obj)
	{
		return (this->weight < obj.weight) ;
	}
	bool operator>(const tuple & obj)
	{
		return (this->weight > obj.weight) ;
	}
	
};

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

class UndirectedGraph
{
	int vertices ;
	int ** data ;
public:
	UndirectedGraph MinimumSpanningTreeKruskelsAlgorithm()
	{
		if(!this->isConnected())
			throw "Graph is not connected.\n" ;
		MinHeap<tuple> weights((this->vertices * (this->vertices - 1)) / 2) ;
		for(int i = 0 ; i < this->vertices ; i++)
		{
			for(int j = 0 ; j < this->vertices ; j++)
			{
				if(j >= i && data[i][j] != 0)
				{
					weights.insert(tuple(i,j,data[i][j])) ;
				}
			}
		}
		DisjointSet sets(vertices) ;
		UndirectedGraph g(vertices) ;
		tuple temp ;
		while(!weights.isEmpty())
		{
			temp = weights.remove() ;
			if(!sets.isConnected(temp.u,temp.v))
			{
				sets.Union(temp.u,temp.v) ;
				g.addEdge(temp.u,temp.v,temp.weight) ;
			}
		}
		return g ;
	}
	UndirectedGraph(int vertices)
	{
		if(vertices < 1 )
			throw "Invalid number of vertices.\n" ;
		this->vertices = vertices ;
		this->data = new int* [this->vertices] ;
		for(int i = 0 ; i < this->vertices ; i++)
			this->data[i] = new int [this->vertices] ;
		for(int i = 0 ; i < this->vertices ; i++)
			for(int j = 0 ; j < this->vertices ; j++)
				this->data[i][j] = 0 ;
	}
	UndirectedGraph(const UndirectedGraph & obj)
	{
		if(obj.data)
		{
			this->vertices = obj.vertices ;
			this->data = new int* [this->vertices] ;
			for(int i = 0 ; i < this->vertices ; i++)
				this->data[i] = new int [this->vertices] ;
			for(int i = 0 ; i < this->vertices ; i++)
				for(int j = 0 ; j < this->vertices ; j++)
					this->data[i][j] = obj.data[i][j] ;
		}
	}
	UndirectedGraph & operator=(const UndirectedGraph & obj)
	{
		if(this->data)
			this->~UndirectedGraph() ;
		this->vertices = obj.vertices ;
		this->data = new int* [this->vertices] ;
		for(int i = 0 ; i < this->vertices ; i++)
			this->data[i] = new int [this->vertices] ;
		for(int i = 0 ; i < this->vertices ; i++)
			for(int j = 0 ; j < this->vertices ; j++)
				this->data[i][j] = obj.data[i][j] ;
		return *this ;
	}
	UndirectedGraph BFS(int sv)
	{
		bool * visited = new bool[vertices] ;
		for(int i = 0 ; i < vertices ; i++ )
			visited[i] = false ;
		UndirectedGraph g(vertices) ;
		BFSWH(sv,visited,g) ;
		for(int i = 0 ; i < vertices ; i++)
		{
			if(visited[i] == false)
				BFSWH(i,visited,g) ;
		}
		cout << endl ;
		delete [] visited ;
		return g ;
	}
	UndirectedGraph BFSWH(int sv, bool * visited, UndirectedGraph & g)
	{
		MyQueue<Edge> q ;
		q.enqueue(Edge(sv,sv)) ;
		while (!q.isEmpty())
		{
			Edge curr = q.dequeue() ;
			if(visited[curr.v] == false)
			{
				if(curr.u != curr.v)
					g.addEdge(curr.u,curr.v) ;
				cout << curr.v << " " ;
				visited[curr.v] = true ;
				for(int i = 0 ; i < vertices ; i++)
				{
					if(data[curr.v][i] != 0 && visited[i] == false)
						q.enqueue(Edge(curr.v,i)) ;
				}
			}
		}
		return g ;
	}
	UndirectedGraph DFS(int sv)
	{
		bool * visited = new bool[this->vertices] ;
		for(int i = 0 ; i < vertices ; i++)
			visited[i] = false ;
		UndirectedGraph g(vertices) ;
		DFSWH(g,sv,visited) ;
		for(int i = 0 ; i < vertices ; i++)
		{
			if(!visited[i])
			{
				DFSWH(g,i,visited) ;
			}
		}
		cout << endl ;
		delete [] visited ;
		return g ;
	}
	void DFSWH(UndirectedGraph & g ,int sv, bool * visited)
	{
		visited[sv] = true ;
		cout << sv << " " ;
		for(int i = 0 ; i < vertices ; i++)
		{
			if(data[sv][i] != 0 && !visited[i])
			{
				g.addEdge(sv,i) ;
				DFSWH(g,i,visited) ;
			}
		}
	}
	public:
	void addEdge(int u, int v, int weight = 1 )
	{
		if((u >= 0 && u < this->vertices) && (v >= 0 && v < this->vertices) && (u != v))
		{
			this->data[u][v] = weight ;
			this->data[v][u] = weight ;
		}
	}
	void removeEdge(int u, int v)
	{
		if((u >= 0 && u < this->vertices) && (v >= 0 && v < this->vertices) && (u != v))
		{
			this->data[u][v] = 0 ;
			this->data[v][u] = 0 ;
		}
	}
	bool isConnected()
	{
		bool * visited = new bool[this->vertices] ;
		for(int i = 0 ; i < vertices ; i++)
			visited[i] = false ;
		isConnectedHorse(0,visited,this->data) ;
		bool connected = true ;
		for(int i = 0 ; i < this->vertices ; i++)
		{
			if(!visited[i])
			{
				connected = false ;
			}
		}
		delete [] visited ;		
		return connected ;
	}
	void isConnectedHorse(int sv, bool * visited, int ** UndirectedGraph)
	{
		visited[sv] = true ;
		for(int i = 0 ; i < vertices ; i++)
		{
			if(UndirectedGraph[sv][i] != 0 && !visited[i])
			{
				isConnectedHorse(i,visited,UndirectedGraph) ;
			}
		}
	}
	~UndirectedGraph()
	{
		if(data)
		{
			for(int i = 0 ; i < this->vertices ; i++)
			{
				delete [] this->data[i] ;
				this->data[i] = NULL ;
			}
			delete [] data ;
			data = NULL ;
		}
	}
	void displayMatrix()
	{
		cout << "\n" ;
		for(int i = 0 ; i < this->vertices ; i++)
		{
			for(int j = 0 ; j < this->vertices ; j++)
			{
				cout << this->data[i][j] << " " ;
			}
			cout << endl ;
		}
		cout << endl ;
	}
	void display()
	{
		bool * visited = new bool[this->vertices] ;
		for(int i = 0 ; i < vertices ; i++)
			visited[i] = false ;
		displayHorse(0,visited) ;
		for(int i = 0 ; i < vertices ; i++)
		{
			if(!visited[i])
			{
				displayHorse(i,visited) ;
			}
		}
		cout << endl ;
		delete [] visited ;
	}
	private :
	void displayHorse(int sv , bool* visited) 
	{
		visited[sv] = true ;
		cout << sv << " " ;
		for(int i = 0 ; i < vertices ; i++)
		{
			if(data[sv][i] != 0 && !visited[i])
			{
				displayHorse(i,visited) ;
			}
		}
	}
};

#endif 