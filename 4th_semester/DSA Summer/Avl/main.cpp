#include "Node.h"
#include "Avl.h"

#include<iostream>
using namespace std;

int main()
{
	Avl<int> a;
	a.insert(56);
	a.insert(10);
	a.insert(33);
	a.insert(44);
	a.insert(12);

	a.inOrder();
	return 0;
}