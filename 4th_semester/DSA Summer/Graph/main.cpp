#include "Graph.h"
#include <iostream>

using namespace std;
	
int main()
{
	Graph<int> g(10);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,3);
	g.addEdge(3,1);
	g.addEdge(3,2);
	g.addEdge(2,7);
	g.addEdge(9,7);
	g.addEdge(5,9);
	g.addEdge(6,5);
	g.addEdge(7,5);
	g.addEdge(7,6);
	g.addEdge(2,8);
	g.addEdge(8,4);
	g.addEdge(4,8);

	//.display();
	cout<<"DFS: ";
	g.dfs(0);
	cout<<endl<<"BFS: ";
	g.bfs(0);
	cout<<endl;

	return 0;
}