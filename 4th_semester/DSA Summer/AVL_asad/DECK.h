#ifndef DECK_H
#define DECK_H

#include "DECK_Exceptions.h"
#include <iostream>
using namespace std ;

template <typename T>

class DECK
{
	int noOfElements ;
	int rear ;
	int front ;
	int capacity ;
	T * data ;
	void resize(int capacity) ;
public:
	DECK();
	DECK(const DECK<T> & ref) ;
	DECK<T> & operator=(const DECK<T> & ref) ;
	bool isFull() ;
	bool isEmpty() ;
	int getNoOfElements() ;
	int getCapacity() ;
	void insertAtTail( T val ) ; 
	void insertAtHead ( T val ) ;
	T deleteAtHead () ;
	T deleteAtTail() ;
	~DECK();
	void displayQueue() ; /*Only added for ease of checking */
};


template <typename T>
DECK<T>::DECK()
{
	this->noOfElements = 0 ;
	this->rear = 0 ;
	this->front = 0 ;
	this->capacity = 1 ;
	this->data = new T[capacity] ;
}

template <typename T>
DECK<T>::DECK(const DECK<T> & ref)
{
	this->noOfElements = ref.noOfElements ;
	this->front = ref.front ;
	this->rear = ref.rear ;
	this->capacity = ref.capacity ;
	this->data = new T [capacity] ;
	for(int i = 0 ; i < this->capacity ; i++)
		this->data[i] = ref.data[i] ;
}

template <typename T>
DECK<T> & DECK<T>::operator=(const DECK<T> & ref)
{
	if(this != &ref)
	{
		delete [] this->data ;
		this->noOfElements = ref.noOfElements ;
		this->rear = ref.rear ;
		this->front = ref.front ;
		this->capacity = ref.capacity ;
		this->data = new T [capacity] ;
		for (int i = 0 ; i < this->capacity ; i++)
		{
			this->data[i] = ref.data[i] ;
		}
	}
}

template <typename T>
void DECK<T>::insertAtTail(T value)
{
	if( isFull() )
	{
		this->resize(this->capacity * 2 ) ;
	}
	this->data[rear] = value ;
	this->noOfElements++ ;
	this->rear = ( rear + 1 ) % this->capacity ;
}

template <typename T>
void DECK<T>::insertAtHead ( T val)
{
	if ( isFull() )
		this->resize( this->capacity * 2 ) ;
	this->front-- ;
	if (front < 0 )
		this->front = this->capacity - 1 ;
	this->data[front] = val ;
	this->noOfElements++ ;
}

template <typename T>
T DECK<T>::deleteAtHead()
{
	if( isEmpty() )
	{
		throw DECK_Exceptions("Error! Queue is empty.\n") ;
	}
	T temp = this->data[front++] ;
	this->noOfElements-- ;
	if ( front == this->capacity )
		front = 0 ;
	if ( this->noOfElements == ( this->capacity / 4 ) )
	{
		this->resize(capacity / 2) ;
	}
	return temp ;
}

template <typename T>
T DECK<T>::deleteAtTail()
{
	if ( isEmpty() )
	{
		throw DECK_Exceptions("Error! Queue is empty.\n") ;
	}
	T temp = this->data[rear--] ;
	this->noOfElements-- ;
	if(rear < 0)
		this->rear = this->capacity - 1 ;
	if ( this->noOfElements > 0 && this->noOfElements == ( this->capacity / 4 ) )
	{
		this->resize(capacity / 2) ;
	}
	return temp ;
}

template <typename T>
void DECK<T>::resize(int newCapacity)
{
	T * temp = new T [newCapacity] ;
	for(int i = 0 ; i < this->noOfElements ; i++)
	{
		temp[i] = this->data[front++] ;
		if(front == this->capacity)
			front = 0 ;
	}
	this->capacity = newCapacity ;
	this->front = 0 ; 
	this->rear = this->noOfElements ;
	delete [] this->data ;
	this->data = temp ;
}


template <typename T>
bool DECK<T>::isFull()
{
	if(this->noOfElements == this->capacity)
		return true ;
	return false ;
}

template <typename T>
bool DECK<T>::isEmpty()
{
	if(this->noOfElements == 0)
		return true ;
	return false ;
}

template <typename T>
int DECK<T>::getNoOfElements()
{
	return this->noOfElements ;
}

template <typename T>
int DECK<T>::getCapacity()
{
	return this->capacity ;
}

template <typename T>
DECK<T>::~DECK()
{
	if(this->data != NULL)
	{
		delete [] this->data ;
		this->data = NULL ;
		this->noOfElements = 0 ;
		this->rear = 0 ;
		this->front = 0 ;
	}
}

template <typename T>
void DECK<T>::displayQueue()
{
	if(isEmpty())
	{
		cout << "empty queue.\n" ;
		return ;
	}
	int temp = this->front ;
	for(int i = 0 ; i < this->noOfElements ; i++)
	{
		cout << this->data[temp++] << " " ;
		if (temp == this->capacity)
			temp = 0 ;
	}
	cout << endl ;
}

#endif