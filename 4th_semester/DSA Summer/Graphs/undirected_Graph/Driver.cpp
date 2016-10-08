#include "UndirectedGraph.h"
#include <vector>

int main()
{
	vector<int> v ;
	v.push_back(1) ;
	v.push_back(2) ;
	v.push_back(3) ;
	v.push_back(4) ;
	auto iter = v.begin() ;
	while (iter != v.end() )
	{cout << *iter << endl ; iter++ ; }
	cout << endl ;
	v.resize(v.size()-1) ;
	iter = v.begin() ;
	while (iter != v.end() )
	{cout << *iter ; iter++ ;}
	//try
	//{
	//	UndirectedGraph g1(6) ;
	//	g1.addEdge(0,1,7) ;
	//	g1.addEdge(0,2,7) ;
	//	g1.addEdge(0,3,5) ;
	//	g1.addEdge(2,3,2) ;
	//	g1.addEdge(2,4,10) ;
	//	g1.addEdge(2,5,16) ;


	//	g1.addEdge(4,5,3) ;
	//	g1.display() ;
	//	g1.displayMatrix() ;
	//	cout << "spanning tree: \n" ;
	//	g1.MinimumSpanningTreeKruskelsAlgorithm().displayMatrix() ;
	//	cout << endl ;
	//}
	//catch (char* error)
	//{
	//	cout << error << endl ;
	//}

	return 0 ;
}