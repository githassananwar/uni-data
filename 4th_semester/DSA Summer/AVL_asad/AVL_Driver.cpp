#include<iostream>
using namespace std ;
class TNode;

class ChildNode
{
public:
	ChildNode *nextSib;
	TNode * nextChild;
	ChildNode(int);
};

class ChildList
{
public:
	ChildNode *childListHead;
	ChildList();
	void addChild(int); //insert at head
};

class TNode
{
public:
	int info;
	ChildList childList;
	TNode(int);
};

class KAryTree // This tree don't have any limit on degree.
{
private:
public:
	TNode * root;
public:
	KAryTree();
	void setRoot(int );
	int getRoot();
	void setChild(int , int );
	void preOrder(TNode *);
	TNode* searchNode(TNode *, int);
	void displayTreeView(TNode *, int tabCount);
	void displayParenthicView(TNode *);
};

ChildNode::ChildNode(int x)
{
	nextSib = 0;
	nextChild = new TNode(x);;
}
ChildList::ChildList()
{
	childListHead=0;
}
void ChildList::addChild(int ch)
{
	ChildNode *p=new ChildNode(ch);
	p->nextSib = childListHead;
	childListHead = p;
}
TNode::TNode(int x=10)
{
	info = x;
}
KAryTree::KAryTree()
{
	root=0;
}
void KAryTree::setRoot(int v)
{
	if (root!=0)
		root -> info = v;
	else
		root = new TNode(v);
}
int KAryTree::getRoot()
{
	return root->info;
}
void KAryTree::setChild(int par, int ch)
{
	TNode * p = searchNode(root,par);
	if (p!=0)
	{
		p->childList.addChild(ch);
	}
}
TNode* KAryTree::searchNode(TNode * p, int key)
{
	if (p==0)
		return 0;

	if ( p->info == key)
		return p;
	ChildNode *q = p -> childList.childListHead;

	TNode *temp = 0;

	while(q!=0)
	{
		temp = searchNode(q->nextChild, key);
		if (temp!=0)
			return temp;
		q = q->nextSib;
	}
	return 0;
}
void KAryTree::preOrder(TNode * p)
{
	if (p==0)
		return;

	cout<<p->info<<"  ";
	ChildNode *q = p -> childList.childListHead;

	while(q!=0)
	{
		preOrder(q->nextChild);
		q = q->nextSib;
	}
}

void KAryTree::displayParenthicView(TNode *p)
{

	if (p==0)
		return;

	cout<<p->info;

	ChildNode *q = p -> childList.childListHead;

	if ( q -> nextChild )// check it as internal node
	{
		cout<<" (";
		//displayTreeView(q->nextChild);
		while(q!=0)
		{
			cout<<" ";
			displayParenthicView(q->nextChild);

			q = q->nextSib;
		}
		cout<<" )";
	}
}
void KAryTree::displayTreeView(TNode *p, int tabCount)
{
	if (p==0)
		return;

	int i=1;
	while(i<= tabCount)
	{
		cout<<"\t";
		i++;
	}
	cout<<p->info<<endl;

	ChildNode *q = p -> childList.childListHead;

	if (q &&  q -> nextChild )//inter
	{
		while(q!=0)
		{
			displayTreeView(q->nextChild, tabCount+1);
			q = q->nextSib;
		}
		tabCount--;
	}
}
void main()
{

	KAryTree tree;
	tree.setRoot(10);
	tree.setChild(10,5);
	tree.setChild(10,7);
	tree.setChild(5,3);
	tree.setChild(5,2);
	tree.setChild(5,1);
	tree.setChild(2,78);
	tree.setChild(7,100);
//	tree.preOrder(tree.root);
	tree.displayTreeView(tree.root,0);

}

//#include <iostream>
//using namespace std ;
//
//#include "AVL.h"
//
//int main()
//{
//	AVL<int> t1 ;
//
//	//example
//	t1.insert(10) ;
//	t1.insert(8) ;
//	t1.insert(11) ;
//	t1.insert(7) ;
//	t1.insert(9) ;
//	/*t1.insert(40) ;
//	t1.insert(35) ;
//	t1.insert(45) ;
//	t1.insert(34) ;*/
//
//	//example involving all rotations
//	/*t1.insert(3) ;
//	t1.insert(2) ;
//	t1.insert(1) ;
//	t1.insert(4) ;
//	t1.insert(5) ;
//	t1.insert(6) ;
//	t1.insert(7) ;
//	t1.insert(16) ;
//	t1.insert(15) ;
//	t1.insert(14) ;
//	t1.explorerView() ;*/
//
//	/*t1.insert(12) ;
//	t1.insert(8) ;
//	t1.insert(16) ;
//	t1.insert(4) ;
//	t1.insert(10) ;
//	t1.insert(14) ;
//	t1.insert(2) ;
//	t1.insert(6) ;
//	t1.insert(1) ;*/
//	t1.explorerView() ;
//	t1.remove(11) ;
//	t1.explorerView() ;
//	return 0 ;
//}