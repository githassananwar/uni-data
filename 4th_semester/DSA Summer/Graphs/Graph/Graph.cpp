#include "Graph.h"

int Graph::stronglyConnectedComponentsNumber()
{
	bool * visited = new bool[this->vertices] ;
	bool * visitedAfterTranspose = new bool [this->vertices] ;
	for(int i = 0 ; i < vertices ; i++)
	{
		visited[i] = false ;
		visitedAfterTranspose[i] = false ;
	}
	int** transpose = new int * [this->vertices] ;
	for(int i = 0 ; i < this->vertices ; i++)
	{
		transpose[i] = new int[this->vertices] ;
	}
	for(int i = 0 ; i < this->vertices ; i++)
	{
		for(int j = 0 ; j < this->vertices ; j++)
		{
			transpose[j][i] = data[i][j] ;
		}
	}
	int stronglyConnectedComponents = 0 ;
	for(int i = 0 ; i < this->vertices ; i++)
	{
		if(!visited[i])
		{
			cout << "Strongly connected component # " << stronglyConnectedComponents+1 << " has vertices : \n" ; 
			isStronglyConnectedHorse(i,visited,this->data) ;
			isStronglyConnectedHorse(i,visitedAfterTranspose,transpose) ;
			for(int j = i ; j < this->vertices ; j++)
			{
				if(visited[j] && visitedAfterTranspose[j])
				{
					visited [j] = true ;
					cout << j << " " ;
				}
				else
					visited[j] = false ;
			}
			cout << endl ;
			stronglyConnectedComponents++ ;
		}
	}
	delete [] visited ;		
	return stronglyConnectedComponents ;
}
Graph::Graph(int vertices)
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
Graph::Graph(const Graph & obj)
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
Graph & Graph::operator=(const Graph & obj)
{
	if(this->data)
		this->~Graph() ;
	this->vertices = obj.vertices ;
	this->data = new int* [this->vertices] ;
	for(int i = 0 ; i < this->vertices ; i++)
		this->data[i] = new int [this->vertices] ;
	for(int i = 0 ; i < this->vertices ; i++)
		for(int j = 0 ; j < this->vertices ; j++)
			this->data[i][j] = obj.data[i][j] ;
	return *this ;
}
Graph Graph::BFS(int sv)
{
	bool * visited = new bool[vertices] ;
	for(int i = 0 ; i < vertices ; i++ )
		visited[i] = false ;
	Graph g(vertices) ;
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
Graph Graph::BFSWH(int sv, bool * visited, Graph & g)
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
Graph Graph::DFS(int sv)
{
	bool * visited = new bool[this->vertices] ;
	for(int i = 0 ; i < vertices ; i++)
		visited[i] = false ;
	Graph g(vertices) ;
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
void Graph::DFSWH(Graph & g ,int sv, bool * visited)
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
bool Graph::isACyclic()
{
	bool * visited = new bool[this->vertices] ;
	for(int i = 0 ; i < vertices ; i++)
		visited[i] = false ;
	int * discovery = new int[this->vertices] ;
	int * finish = new int[this->vertices] ;
	int time = 1 ;
	for(int i = 0 ; i < vertices ; i++)
	{
		if(!visited[i])
		{
			isCyclicHorse(i,visited,discovery,finish,time) ;
		}
	}
	for(int i = 0 ; i < this->vertices ; i++)
		cout << discovery[i] << " " ;
	cout << endl ;
	for(int i = 0 ; i < this->vertices ; i++)
		cout << finish[i] << " " ;
	cout << endl ;
	bool cyclic = false ;
	for(int i = 0 ; !cyclic && i < vertices ; i++)
	{
		for(int j = 0 ; j < vertices ; j++)
		{
			if(i != j)
			{
				if(data[i][j] != 0 && checkBackEdge(discovery,finish,i,j))
				{
					cyclic = true ;
					break ;
				}
			}
		}
	}
	delete [] visited ;
	delete [] discovery ;
	delete [] finish ;
	return cyclic ;
}
bool Graph::checkBackEdge(int * discovery, int* finish, int index1, int index2)
{
	if((discovery[index2] < discovery[index1]) && (discovery[index1] < finish[index1]) && (finish[index1] < finish[index2]))
		return true ;
	return false ;
}
void Graph::isCyclicHorse(int sv, bool * visited, int * discovery, int* finish, int & time)
{
	visited[sv] = true ;
	discovery[sv] = time ;
	time++ ;
	for(int i = 0 ; i < vertices ; i++)
	{
		if(data[sv][i] != 0 && !visited[i])
		{
			isCyclicHorse(i,visited,discovery,finish,time) ;
		}
	}
	finish[sv] = time ;
	time++ ;
}
void Graph::addEdge(int u, int v, int weight )
{
	if((u >= 0 && u < this->vertices) && (v >= 0 && v < this->vertices) && (u != v))
	{
		this->data[u][v] = weight ;
	}
}
void Graph::removeEdge(int u, int v)
{
	if((u >= 0 && u < this->vertices) && (v >= 0 && v < this->vertices) && (u != v))
	{
		this->data[u][v] = 0 ;
	}
}
bool Graph::isStronglyConnected()
{
	bool * visited = new bool[this->vertices] ;
	for(int i = 0 ; i < vertices ; i++)
		visited[i] = false ;
	isStronglyConnectedHorse(0,visited,this->data) ;
	bool connected = true ;
	for(int i = 0 ; i < vertices ; i++)
	{
		if(!visited[i])
		{
			connected = false ;
			break ;
		}
	}
	if(connected)
	{
		int** transpose = new int * [this->vertices] ;
		for(int i = 0 ; i < this->vertices ; i++)
		{
			transpose[i] = new int[this->vertices] ;
		}
		for(int i = 0 ; i < this->vertices ; i++)
		{
			for(int j = 0 ; j < this->vertices ; j++)
			{
				transpose[j][i] = data[i][j] ;
			}
		}
		for(int i = 0 ; i < this->vertices ; i++)
			visited[i] = 0 ;
		isStronglyConnectedHorse(0,visited,transpose) ;
		for(int i = 0 ; i < this->vertices ; i++)
		{
			if(!visited[i])
			{
				connected = false ;
				break ;
			}
		}
	}
	delete [] visited ;		
	return connected ;
}
void Graph::isStronglyConnectedHorse(int sv, bool * visited, int ** graph)
{
	visited[sv] = true ;
	for(int i = 0 ; i < vertices ; i++)
	{
		if(graph[sv][i] != 0 && !visited[i])
		{
			isStronglyConnectedHorse(i,visited,graph) ;
		}
	}
}
void Graph::displayMatrix()
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
void Graph::display()
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
void Graph::displayHorse(int sv , bool* visited) 
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
Graph::~Graph()
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