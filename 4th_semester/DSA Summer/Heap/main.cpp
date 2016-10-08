#include "MinHeap_L.h"
#include <iostream>

using namespace std;

int main()
{
	MinHeap<int> mh(5);
	mh.insert(20);
	mh.insert(40);
	mh.insert(100);
	mh.insert(30);
	mh.insert(40);
	mh.insert(300);
	mh.insert(120);
	mh.insert(110);
	mh.insert(35);
	mh.insert(37);
	
	mh.remove();

	mh.displayParenthesis();
	cout<<endl;
	return 0;
}