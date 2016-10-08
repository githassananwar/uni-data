#include "Node.h"
#include <stack>
#include<iostream>
using namespace std;

#ifndef MINHEAP_H
#define MINHEAP_H
template<typename T>
class MinHeap
{
	Node<T>* root;
	int numOfNodes;

	void convertToBinary(int n, stack<int>& s)
	{
		int rem=0;
		while(n!=0)
		{
			rem=n%2;
			s.push(rem);
			n=n/2;
		}

		s.pop();
	}

	void insert(Node<T>* p, T val)
	{
		int num=(numOfNodes+1)/2;
		stack<int> s;
		stack<Node<T>*> par;

		convertToBinary(num, s);
		Node<T>* curr=0;
	
		par.push(p);
		while(!s.empty())
		{
			if(p->left && s.top()==0)
			{
				p=p->left;
				par.push(p);
			}
			else if(p->right && s.top()==1)
			{
				p=p->right;
				par.push(p);
			}
			s.pop();
		}

		if(p->left==0)
		{
			p->left=new Node<T>(val);
			curr=p->left;
		}
		else if(p->right==0)
		{
			p->right=new Node<T>(val);
			curr=p->right;
		}

		while(!par.empty())
		{
			if(curr->info < par.top()->info)
			{
				T temp=par.top()->info;
				par.top()->info=curr->info;
				curr->info=temp;

				curr=par.top();
			}
			par.pop();
		}

	}



	void remove(Node<T>* p)
	{
		stack<int> s;
		Node<T>* par=0;
		convertToBinary(numOfNodes, s);

		par=root;
		while(!s.empty())
		{
			if(p->left && s.top()==0)
			{
				par=p;
				p=p->left;
			}
			else if(p->right && s.top()==1)
			{
				par=p;
				p=p->right;
			}
			s.pop();
		}

		if(p==root)
		{
			delete root;
			root=0;
		}
		else
		{T val=p->info;
		delete p; 
		if(par->right)
			par->right=0;
		else
			par->left=0;

		p=root;
		root->info=val;

		while(p->left || p->right)
		{
			if(p->left && p->info > p->left->info)
			{
				T temp=p->info;
				p->info=p->left->info;
				p->left->info=temp;
				p=p->left;
			}
			else if(p->right && p->info > p->right->info)
			{
				T temp=p->info;
				p->info=p->right->info;
				p->right->info=temp;
				p=p->right;
			}
		
		}
		}

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

//--------------------------------Public--------------------------------

public:
	MinHeap()
	{
		root=0;
		numOfNodes=0;
	}

	MinHeap(T val)
	{
		root=new Node<T>(val);
		numOfNodes=1;
	}

	void insert(T val)
	{
		insert(root, val);
		numOfNodes++;
	}

	void remove()
	{
		remove(root);
	}

	void displayParenthesis()
	{
		displayParenthesis(root);
	}

	~MinHeap()
	{
		removeDecendent(root);
	}

};

#endif