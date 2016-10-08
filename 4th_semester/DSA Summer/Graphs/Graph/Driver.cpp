#include "Graph.h"
#include <vector>

int main()
{
	Graph g1 (6) ;
	g1.addEdge(0,1) ;
	g1.addEdge(1,2) ;
	g1.addEdge(2,0) ;
	g1.addEdge(3,4) ;
	g1.addEdge(4,5) ;
	g1.addEdge(5,3) ;

	//Graph g1(10) ;
	//g1.addEdge(0,1) ;
	//g1.addEdge(1,2) ;
	//g1.addEdge(2,3) ;
	//g1.addEdge(3,4) ;
	//g1.addEdge(4,5) ;
	//g1.addEdge(5,2) ;
	//g1.addEdge(2,6) ;

	//g1.addEdge(6,0) ;
	//g1.addEdge(7,6) ;
	//g1.addEdge(0,7) ;
	//g1.addEdge(6,8) ;
	////g1.addEdge(8,6) ;
	//g1.addEdge(8,9) ;
	//g1.addEdge(9,8) ;

	//input for checking connected
	//Graph g1(10) ;
	//g1.addEdge(0,1) ;
	//g1.addEdge(1,2) ;
	//g1.addEdge(2,3) ;
	//g1.addEdge(3,4) ;
	//g1.addEdge(4,5) ;
	//g1.addEdge(5,2) ;
	//g1.addEdge(2,6) ;

	//g1.addEdge(6,0) ;
	//g1.addEdge(7,6) ;
	//g1.addEdge(0,7) ;
	//g1.addEdge(6,8) ;
	////g1.addEdge(8,6) ; // add this to make connected
	//g1.addEdge(8,9) ;
	//g1.addEdge(9,8) ;

	g1.display() ;
	g1.displayMatrix() ;
	cout << "Strongly connected components are: " << g1.stronglyConnectedComponentsNumber() << endl ;
	return 0 ;
}