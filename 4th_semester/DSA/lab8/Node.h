#ifndef NODE_H
#define NODE_H

template<typename T>

class Node
{
public:
	int info;
	Node<T>* next;

	Node()
	{
		next=0;
		info=0;
	}
};
#endif
