#ifndef NODE_H
#define NODE_H

template<typename T>

class Node
{
public:
	T info;
	int height;
	Node<T>* left;
	Node<T>* right;

	Node()
	{
		left=right=0;
		height=0;
	}

	Node(T x)
	{
		info = x;
		left = right = 0;
		height=1;
	}

};
#endif
