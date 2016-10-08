#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
#ifndef LSLL_H
#define LSLL_H
template<typename T>
class LSLL
{
	Node<T>*head;
public:
	LSLL(void);
	void InsertAtHead(T);
	void InsertAtTail(T);
	void InsertAfter(T val,T);
	void InsertBefore(T val,T);
	void removeAfter(T key);
	void ReverseLinks(Node<T> * p);
	void recursiveLinks(Node<T>*p,Node<T>*q,Node<T>*r);
	int sumRecursive();
	void call2();
	LSLL(T val);
	void call();
	void Display();
	~LSLL(void);
};
#endif
template<typename T>
LSLL<T>::LSLL()
{
	head = 0;
}
template<typename T>
LSLL<T>::LSLL(T val)
{
	head = 0;
	info = val;
}
template<typename T>
void LSLL<T>::InsertAtHead(T val)
{
	Node<T> *p = new Node <T>(val);
	p->next =this->head;
	head = p;
}
template<typename T>
void LSLL<T>::InsertAtTail(T val)
{
	if(this->head==0)
	{
		this->head= new Node <T>(val);
		return;
	}
     Node <T>*p = this->head;
	 while(p->next!=0)
	 {
		 p = p->next;
	 }
	 p->next = new Node<T>(val);
	 p->next->next=0;

}
template<typename T>
void LSLL<T>::InsertAfter(T val,T num)
{
	Node <T>*p = this->head;
	bool found = false;
	while(p->next!=0)
	{
		if(p->info== val)
		{
			Node<T> *temp = p->next;
			p->next = new Node<T>(num);
			p->next->next = temp;
			found = true;
			break;
		}
		p = p->next;
	}
	if(!found)
	{
		cout << "value cannot be inserted because required value is not found" << endl;
	}

}
template<typename T>
void LSLL<T>::Display()
{
	Node <T>*p = head;
	while(p!=0)
	{
		cout << p->info << endl;
		p = p->next;
	}
}
template<typename T>
void LSLL<T>::InsertBefore(T val,T key)
{
	Node<T>*p = head;
	Node<T>*t =0;
	Node<T>*x=0;
	while(p!=0)
	{
		if(p->info== key )
		{
			x = t->next;
			t->next= new Node<T>(val);
			t->next->next = x;
		}
		t=p;
		p=p->next;
	}
}
template<typename T>
void LSLL<T>::removeAfter(T key)
{
	Node<T>*p = head;
	Node<T>*t=0;
	while(p!=0)
	{
		if(p->info== key)
		{
			t = p->next;
			p->next= t->next;
			delete t;
			t=0;
			return;
		}
		p = p->next;
	}
}
template<typename T>
void LSLL<T>::ReverseLinks(Node<T> * p)
{
	
	Node <T>*q = p->next;
	Node <T>*r = q->next;
	p->next = 0;
	while(r!=0)
	{
		q->next = p;
		p=q;
		q=r;
		r = r->next;
	}
	q->next = p;
	head = q;
}
template<typename T>
void LSLL<T>::call()
{
	Node <T>*p = head;
	//ReverseLinks(p);
	Node <T>*q = p->next;
	Node <T>*r = q->next;
	recursiveLinks(p,q,r);
	//ReverseLinks(p);
}
template<typename T>
void LSLL<T>::call2()
{
	Node <T>*p = head;
	ReverseLinks(p);

}
template<typename T>
void LSLL<T>::recursiveLinks(Node<T>*p,Node<T>*q,Node<T>*r)
{
	if(r!=0)
	{
		//p->next = 0;
		q->next = p;
		p=q;
		q=r;
		r = r->next;
		q->next = p;
	}
	else
	{
		q->next = p;
	head->next=0;
		head = q;
		return;;
	}
recursiveLinks(p,q,r);
}
template<typename T>
int LSLL<T>::sumRecursive()
{
	Node<T>*p = head;

}
template<typename T>
LSLL<T>::~LSLL(void)
{
	Node<T>*x = this->head;
	Node<T>*p = this->head;
	//while(p!=0)
	//{
		x=p;
		p= p->next;
		delete x;
		//delete head;
}
