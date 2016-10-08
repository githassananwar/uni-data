#include "Node.h"
#ifndef LSLL_H
#define LSLL_H

#include<iostream>
using namespace std;

template <typename T>
class Lsll
{
	Node<T>*  head;
public:
	Lsll()
	{
		head= 0;
	}

	void insertAtHead(T val)
	{
		if(head == 0)
		{
			head = new Node<T>[1];
			head -> info = val;
			head -> next = 0;
		}
		else
		{
			Node<T>* temp = new Node<T>[1];
			temp -> info = val;
			temp -> next = head;
			head = temp;
		}
	}

	void display()
	{
		Node<T>* temp = head;
		while(temp != NULL)
		{
			cout << temp -> info << " ";
			temp = temp -> next;
		}
		cout << endl;
	}

	void insertAtEnd(T val)
	{
		if(head == NULL)
		{
			head = new Node<T>[1];
			head -> info = val;
			head -> next = NULL;
		}
		else
		{
			Node<T>* temp = head;
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = new Node<T>[1];
			temp -> next -> info = val;
			temp -> next -> next = NULL;
		}
	}

	T removeFromHead()
	{
		if(head != NULL)
		{
			T ret = head -> info;
			Node<T>* temp = head;
			head = head -> next;
			delete [] temp;
			return ret;
		}
		exit(0);
	}

	T removeFromEnd()
	{
		if(head != NULL)
		{
			Node<T>* temp = head;
			Node<T>* prev = head;
			while(temp -> next != NULL)
			{
				prev = temp;
				temp = temp -> next;
			}
			T ret = temp -> info;
			delete [] temp;
			prev -> next = NULL;
			return ret;
		}
	}

	T remove(T key)
	{
		if(head != NULL)
		{
			T ret;
			Node<T>* temp = head , * prev = head;
			while(temp -> info != key && temp -> next != NULL)
			{
				prev = temp;
				temp = temp -> next;
			}
			if(temp -> info == key)
			{
				if(prev == head)
				{
					head = temp -> next;
				}
				else
				{
					prev -> next = temp -> next;
				}
				ret = key;
				delete [] temp;
				return ret;
			}
			else
			{
				cout << "The Key not found in the Link List." << endl << endl;
			}
		}
	}

	T removeAfter(T key)
	{
		if(head != NULL)
		{
			if(head -> next != NULL)
			{
				Node<T>* after = head , *temp = head;
				while(temp -> info != key && after -> next != NULL)
				{
					temp = after;
					after = after -> next;
				}
				if(after -> info != key && temp -> info != key && after -> next == NULL)
				{
					cout << "The Key " << key << " not Found in the Link List." << endl << endl;
					exit(0);
				}
				
				if(temp == after)
				{
					T ret;
					 after = after -> next;
					 ret = after -> info;
					 temp -> next = NULL;
					 delete [] after;
					 return ret;
				}
				if(temp -> info != key && after -> info == key)
				{
					cout << "Nothing after key " << key << " in the Link List." << endl << endl;
					exit(0);
				}
				temp -> next = after -> next;
				T ret = after -> info;
				delete [] after;
				return ret;
			}
			else
			{
				cout << "Nothing after key " << key << " in the Link List." << endl << endl;
				exit(0);
			}
		}
		else
		{
			cout << "The Link List is Empty." << endl << endl;
		}
	}

	T removeBefore(T key)
	{
		if(head != NULL)
		{
			Node<T>* temp = head , *before = head , *after = head;
			while(after -> info != key && after -> next != NULL)
			{
				before = temp;
				temp = after;
				after = after -> next;
			}
			if(after == head && after == before)
			{
				cout << "Nothing before key " << key << " in the Link List." << endl << endl;
				exit(0);
			}
			if(before == temp)
			{
				head = after;
				T ret = before -> info;
				delete [] before;
				return ret;
			}
			before -> next = after;
			T ret = temp -> info;
			delete [] temp;
			return ret;
		}
	}

	T getItemAtIndex(int ind)
	{
		int count = 0;
		Node<T>* temp = head;
		T ret = 0;
		while(temp -> next != NULL)
		{
			if(count == ind)
			{
				ret = temp -> info;
			}
			temp = temp -> next;
			count++;
		}
		if(count < ind || ind < 0)
		{
			cout << "Invalid Index!" << endl << endl;
			exit(0);
		}
		else
		{
			return ret;
		}
	}

	void reverseListIt()
	{
		if(head!=0)
		{
			if(head->next==0)
			{
				return;
			}

			if(head->next->next!=0)
			{
				Node <T>*p=head, *q=head->next, *r=head->next->next;
				while(r->next!=0)
				{
					q->next=p;
					p=q;
					q=r;
					r=r->next;
				}
				q->next=p;
				head->next=0;
				r->next=q;
				head=r;
			}
			else
			{
				Node <T>*p=head->next;
				p->next=head;
				head->next=0;
				head=p;
			}
		}
		
		
	}

	void recursiveReverse(Node<T>* &p, Node<T>* &q, Node<T>* &r)
	{
		if(r->next==0)
		{
			return;
		}
		
		q->next=p;
		p=q;
		q=r;
		r=r->next;

		recursiveReverse(p, q, r);

	}

	void reverseListRe()
	{
		if(head!=0)
		{
			if(head->next==0)
			{
				return;
			}

			if(head->next->next!=0)
			{
				Node <T>*p=head, *q=head->next, *r=head->next->next;
				recursiveReverse(p, q, r);
				q->next=p;
				head->next=0;
				head=r;
				r->next=q;
			}
			else
			{
				Node <T>*p=head->next;
				p->next=head;
				head->next=0;
				head=p;
			}
		}

	}

	bool searching(T key)
	{
		Node<T>* temp;
		while(temp -> next)
		{
			if(temp -> info == key)
			{
				return true;
			}
		}
		return false;
	}

	~Lsll()
	{

	}
};
#endif;
