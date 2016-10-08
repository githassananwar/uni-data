#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue
{
	int rear;
	int front;
	int numOfElements;
	int capacity;
	T* data;

public:

	Queue(int cap = 0)
	{
		capacity = cap;
		numOfElements = 0;
		front = 0;
		rear = 0;
		data = new T[capacity];

	}

	Queue(const Queue<T> & d)
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

	void enqueue(T val) //insert at tail
	{
		if(isFull())
		{
			exit(0);
		}
		
		data[rear]=val;
		rear = (rear+1) % capacity;
		numOfElements++;
		
	}

	T dequeue() //remove at head
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

	~Queue()
	{
		delete [] data;
		data = 0;
	}
};

#endif
