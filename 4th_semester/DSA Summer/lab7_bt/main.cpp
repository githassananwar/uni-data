#include "Node.h"
#include "BinaryTree.h"
#include<iostream>

using namespace std;


int main()
{
	BinaryTree <int> bt;

	bt.setRoot(1);
	bt.setLeftChild(1,2);
	bt.setRightChild(1,3);
	bt.setLeftChild(2,4);
	bt.setRightChild(2,5);
	bt.setLeftChild(5 , 8);

	//bt.displayAcendent(3);
	bt.displayParenthesisView();
	cout<<endl;
	bt.explorer();
	
	cout<<endl;
	return 0;
}