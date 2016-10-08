#ifndef MY_QUEUE
#define MY_QUEUE

#include "MyQueueExceptions.h"
#include <iostream>
using namespace std ;


template <typename T>

class MyQueue
{
	int noOfElements ;
	int rear ;
	int front ;
	int capacity ;
	T * data ;
public:
	MyQueue();
	MyQueue(const MyQueue<T> & ref) ;
	MyQueue<T> & operator=(const MyQueue<T> & ref) ;
	bool isFull() ;
	bool isEmpty() ;
	int getNoOfElements() ;
	int getCapacity() ;
	void enqueue (T val) ;
	T dequeue () ;
	void resize(int capacity) ;
	void displayQueue() ;
	~MyQueue();
};

template <typename T>
MyQueue<T>::MyQueue()
{
	this->noOfElements = 0 ;
	this->rear = 0 ;
	this->front = 0 ;
	this->capacity = 1 ;
	this->data = new T[capacity] ;
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T> & ref)
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
MyQueue<T> & MyQueue<T>::operator=(const MyQueue<T> & ref)
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
void MyQueue<T>::enqueue(T value)
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
T MyQueue<T>::dequeue()
{
	if( isEmpty() )
	{
		throw MyQueueExceptions("Error! Queue is empty.\n") ;
	}
	T temp = this->data[front++] ;
	this->noOfElements-- ;
	if ( front == this->capacity )
		front = 0 ;
	if ( this->noOfElements > 0 && this->noOfElements == ( this->capacity / 4 ) )
	{
		this->resize(capacity / 2) ;
	}
	return temp ;
}

template <typename T>
void MyQueue<T>::resize(int newCapacity)
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
bool MyQueue<T>::isFull()
{
	if(this->noOfElements == this->capacity)
		return true ;
	return false ;
}

template <typename T>
bool MyQueue<T>::isEmpty()
{
	if(this->noOfElements == 0)
		return true ;
	return false ;
}

template <typename T>
int MyQueue<T>::getNoOfElements()
{
	return this->noOfElements ;
}

template <typename T>
int MyQueue<T>::getCapacity()
{
	return this->capacity ;
}

template <typename T>
MyQueue<T>::~MyQueue()
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
void MyQueue<T>::displayQueue()
{
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