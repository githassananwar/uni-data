#ifndef DECK_H
#define DECK_H

template<class T>
class Deck
{
	int rear;
	int front;
	int numOfElements;
	int capacity;
	T* data;

public:

	Deck(int cap = 0)
	{
		capacity = cap;
		numOfElements = 0;
		front = 0;
		rear = 0;
		data = new T[capacity];
	}

	Deck(const Deck<T> & d)
	{
		capacity=d.capacity;
		rear=d.rear;
		front=d.front;
		numOfElements=d.numOfElements;

		data=new T[capacity];

		for(int i=0;i<capacity;i++)
		{
			data[i]=d.data[i];
		}

	}

	void insertAtTail(T val)
	{
		if(isFull())
		{
			exit(0);
		}

		data[rear] = val;
		rear = (rear+1) % capacity;
		numOfElements++;
		
	}

	T removeAtHead()
	{
		if(isEmpty())
		{
			exit(0);
		}

		T x=data[front];
		front=(front+1)%capacity;
		numOfElements--;

		return x;

	}

	void insertAtHead(T val)
	{
		if(isFull())
		{
			exit(0);
		}

		if(front==0)
		{
			front=capacity-1;
		}
		else
		{
			front=front-1;
		}
		data[front]=val;
		numOfElements++;
	}

	T removeAtTail()
	{
		if(isEmpty())
		{
			exit(0);
		}

		T x=data[rear];
		rear=rear-1;

		return x;

	}

	bool isEmpty()
	{
		if(numOfElements == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull()
	{
		if(numOfElements == capacity)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getNumOfElements()
	{
		return numOfElements;
	}

	int getCapacity()
	{
		return capacity;
	}

	~Deck()
	{
		delete [] data;
		data = 0;
	}
};

#endif
