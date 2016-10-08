#ifndef BST_H
#define BST_H
#include "Node.h"

template<typename T>
class BST
{
	Node<T> * root;
	void delSub(Node<T>* p)
	{
		if(p == 0)
			return;
		if(p ->left)
			p = p ->left;
		if(p ->right)
			p = p ->right;
		delete p;
	}

	void LVR(Node<T>* p)
	{
		if(p == 0)
		{
			return;
		}
		LVR(p ->left);
		cout << p ->info << " ";
		LVR(p ->right);
	}

public:
	BST()
	{
		root = 0;
	}

	void insert(T val)
	{
		if(root == 0)
		{
			root = new Node<T>(val);
			return;
		}
		Node<T>* p = root;
		while(p != 0)
		{
			if(val < p ->info)
			{
				if(p ->left == 0)
				{
					p ->left = new Node<T>(val);
					break;
				}
				else
					p = p ->left;
			}
			else
			{
				if(p ->right == 0)
				{
					p ->right = new Node<T>(val);
					break;
				}
				else
					p = p ->right;
			}
		}
	}

	bool search(T key)
	{
		Node<T>* p = root;
		while(p != 0)
		{
			if(p ->info == key)
				return true;
			if(p ->info > key)
				p = p ->left;
			else
				p = p ->right;
		}
		return false;
	}

	void remove(T key)
	{
		Node<T>* p = root , *q = root;
		while(p != 0)
		{
			if(p ->info == key)
			{
				break;
			}
			q = p;
			if(p ->info > key)
			{
				p = p ->left;
			}
			else
			{
				p = p ->right;
			}
		}
		if(p ->left == 0 && p ->right == 0)
		{
			if(p == root)
			{
				delete root;
				root = 0;
				return;
			}
			delete p;
			if(q ->left == p)
			{
				q ->left = 0;
			}
			else
			{
				q ->right = 0;
			}
		}
		else if((p ->left != 0 && p ->right == 0) || (p ->left == 0 && p ->right != 0))
		{
			if(p == root)
			{
				if(p ->left != 0)
				{
					p = p ->left;
				}
				else
				{
					p = p ->right;
				}
				delete root;
				root = p;
				return;
			}
			if(p ->left != 0)
			{
				if(q ->right == p)
				{
					q ->right = p ->left;
				}
				else
				{
					q ->left = p ->left;
				}
				delete p;
			}
			else
			{
				if(q ->right == p)
				{
					q ->right = p ->right;
				}
				else
				{
					q ->left = p ->right;
				}
				delete p;
			}
		}
		else if(p ->left != 0 && p ->right != 0)
		{
			Node<T>* par = p ->right;
			q = p ->right;
			while(q ->left != 0)
			{
				par = q;
				q = q ->left;
			}
			if(q == par)
			{
				p ->info = q ->info;
				p ->right = q ->right;
				delete q;
			}
			else
			{
				p ->info = q ->info;
				par ->left = q ->right;
				delete q;
			}
		}
	}

	void inOrder()
	{
		LVR(root);
	}

	~BST()
	{
		delSub(root);
		root = 0;
	}
};
#endif
