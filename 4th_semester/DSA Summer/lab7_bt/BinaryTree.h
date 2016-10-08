#include "Node.h"
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTree
{
private:
	Node<T>*  root;

	void VLR(Node<T>* p)
	{
		cout<<p->info<<" ";

		if(p->left)
		{
			VLR(p->left);
		}
		if(p->right)
		{
			VLR(p->right);
		}
	}

	void LRV(Node<T>* p)
	{
		if(p->left)
		{
			LRV(p->left);
		}
		if(p->right)
		{
			LRV(p->right);
		}

		cout<<p->info<<" ";
	}

	void LVR(Node<T>* p)
	{
		if(p->left)
		{
			LVR(p->left);
		}

		cout<<p->info<<" ";

		if(p->right)
		{
			LVR(p->right);
		}
	}

	Node<T>* getParent(T key, Node<T>*p)
	{
		Node<T>*x=0;

		if(p->left && p->left->info==key)
			return p;

		if(p->right && p->right->info==key)
			return p;

		if(p->left)
			x=getParent(key,p->left);

		if(x==0 && p->right)
			x=getParent(key,p->right);

		return x;

	}

	Node<T>* findNode(T key, Node<T>* p) 
	{
		Node<T>* x=0;

		if(p->info==key)
			return p;

		if(p->left)
		{
			x=findNode(key, p->left);
		}
		if(x==0 && p->right)
		{
			x=findNode(key, p->right);
		}

		return x;
	}

	void removeDecendent(Node<T>* p)
	{
		if(p==0)
			return;

		if(p->left)
		{
			removeDecendent(p->left);
		}
		if(p->right)
		{
			removeDecendent(p->right);
		}

		delete p;
	}


	int getHeight(Node<T>* p)
	{
		int rh=0, lh=0;

		if(p->left==0 && p->right==0)
		{
			return 1;
		}

		if(p->left)
		{
			lh = getHeight(p->left);
		}
		if(p->right)
		{
			rh = getHeight(p->right);
		}

		if(lh>rh)
		{
			return lh+1;
		}
		else
		{
			return rh+1;
		}

	}
	
	void displayParenthesis(Node<T>* p)
	{
		if(p==0)
			return;

		if(p->left || p->right)
		{
			cout<<p->info<<" ( ";
		}
		else
		{
			cout<<p->info;
			return;
		}

		if(p->left)
		{
			displayParenthesis(p->left);
		}

		cout<<" , ";

		if(p->right)
		{
			displayParenthesis(p->right);
			
		}
		cout<<" ) ";

	}

	void createCopy(Node<T>* t1, Node<T>* t2)
	{
		if(t1->left)
		{
			t2->left=new Node<T>(t1->left->info);
			createCopy(t1->left, t2->left);
		}

		if(t1->right)
		{
			t2->right=new Node<T>(t1->right->info);
			createCopy(t1->right, t2->right);
		}
		
	}

	bool displayAcendent(Node<T>* p, T key)
	{
		bool flag=false;

		if(p->info==key)
		{
			return true;
		}
		
		if(p->left)
		{
			flag = displayAcendent(p->left, key);
		}		

		if( p->right && flag == false)
		{
			flag = displayAcendent(p->right, key);
		}

		if(flag == true)
			cout << p -> info << "   ";

		return flag;
	}

	void explorer(Node<T>* p, int tabCount)
	{
		if(p==0)
			return;

		if(p->left || p->right)
		{
			for(int i=0;i<tabCount;i++)
				cout<<"\t";

			cout<<p->info<<endl;
		}
		else
		{
			for(int i=0;i<tabCount;i++)
				cout<<"\t";
			cout<<p->info<<endl;
			return;
		}

		if(p->left)
		{
			explorer(p->left,tabCount+1);
		}


		if(p->right)
		{
			explorer(p->right, tabCount+1);
		}

	}

//----------------------------------------PUBLIC---------------------------------------- 

public:

	void explorer()
	{
		explorer(root,0);
	}

	void displayAcendent(T key)
	{
		displayAcendent(root, key);
	}

	BinaryTree()
	{
		root=0;
	}

	void setRoot(T val) 
	{
		if(root)
			root->info=val;
		else
			root=new Node<T>(val);
	}

	T getRoot() 
	{
		if(root)
			return root->info;

		return -1;
	}

	void setLeftChild(T parent, T child) 
	{
		Node<T>* p=findNode(parent,root);
		if(p->left)
			p->left->info=child;
		else
			p->left=new Node<T>(child);
	}

	void setRightChild(T parent, T child)
	{
		Node<T>* p=findNode(parent,root);
		if(p->right)
			p->left->info=child;
		else
			p->right=new Node<T>(child);
	}

	T getParent(T node)
	{
		Node<T>* p=getParent(node, root);
		if(p)
			return p->info;
		else
			return -1;
	}

	void remove(T node)
	{
		Node<T>* p=getParent(node, root);
		if(p!=0 && p->left->info==node)
		{
			removeDecendent(p->left);
			p->left=0;
		}
		else if(p!=0 && p->right->info==node)
		{
			removeDecendent(p->right);
			p->right=0;
		}
		
	}

	bool isInternalNode(T node)
	{
		Node<T>*p=findNode(node, root);
		if(p->left || p->right)
			return 1;
		else 
			return 0;
	}

	bool isExternalNode(T node)
	{
		Node<T>*p=findNode(node, root);
		if(p->left || p->right)
			return 0;
		else 
			return 1;
	}

	T findNodeSiblings( T node )
	{
		Node<T>*p=getParent(node,root);
		if(p==0)
		{
			return -1;
		}

		if(p->left && p->right)
		{
			if(p->left->info==node)
			{
				return p->right->info;
			}
			else if(p->right->info==node)
			{
				return p->left->info;
			}
		}
		
		return -1;

	}

	void preOrder()
	{
		VLR(root);
	}

	void postOrder()
	{
		LRV(root);
	}

	void inOrder()
	{
		LVR(root);
	}

	void levelOrder()
	{
		Node<T>* p=0;
		queue<Node<T>*> q;
		q.push(root);

		while(!q.empty())
		{
			p=q.front();
			q.pop();
			cout<<p->info;
			if(p->left)
				q.push(p->left);

			if(p->right)
				q.push(p->right);
		}

	}

	void displayDescendents(T node)
	{
		if(root==0)
			return;

		Node<T>*p=findNode(node, root);
		if(p==0)
			return;

		if(p->left)
		{
			VLR(p->left);
		}
		if(p->right)
		{
			VLR(p->right);
		}
	}

	int heightOfTree()
	{
		int h=getHeight(root);
		return h;
	}

	void displayParenthesisView()
	{
		displayParenthesis(root);
	}
	
	~BinaryTree()
	{
		removeDecendent(root);
	}

	BinaryTree<T>& operator = (BinaryTree<T> & t)
	{
		if(this!=&t)
		{
			this->removeDecendent(root);
			root=new Node<T>(t.getRoot());
			createCopy(t.root, root);
		}

		return *this;
	}

	BinaryTree(BinaryTree<T> & t)
	{
		root=new Node<T>(t.getRoot());
		createCopy(t.root, root);
	}

};

#endif
