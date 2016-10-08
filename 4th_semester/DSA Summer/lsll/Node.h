#pragma once
#ifndef	NODE_H
#define NODE_H
template<typename T>
class Node
{
public:
	T info;
	Node<T> *next;
	Node(void);
	Node(T val);
	~Node(void);
};
#endif
template<typename T>
Node<T>::Node()
{
	this->next=0;
}
template<typename T>
Node<T>::Node(T val)
{
	this->info= val;
	this->next=0;
}
template<typename T>
Node<T>::~Node(void)
{
	if(next)
	{
		//cout << info << " ";
		delete next;
		//cout <<"dtor";
	}
}



