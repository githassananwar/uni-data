#pragma once
template<class T>
class Node
{public:
	T info;
	Node<T> * left;
	Node<T> * right;

	Node()
	{
		left = 0;
		right = 0;
	}
	Node(int n)
	{
		info = n;
		left = 0;
		right = 0;
	}
	//~Node(void);
};

