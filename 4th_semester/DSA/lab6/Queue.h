#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue
{
private:
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

	void enqueue(T val)
	{
		if(!isFull())
		{
			data[rear] = val;
			rear = (++rear) % capacity;
			numOfElements++;
		}
		else
		{
			T * tempData = new T[capacity];
			for(int i = 0 ; i < numOfElements ; i++)
			{
				tempData[i] = data[rear++];
			}
			this -> ~Queue();
			capacity *= 2;
			data = new T[capacity];
			for(int i = 0 ; i < numOfElements ; i++)
			{
				data[i] = tempData[i];
			}
			front = 0;
			rear = numOfElements;
			data[rear] = val;
			rear = (++rear) % capacity;
			numOfElements++;
		}
	}
	T dequeue()
	{
		if(!isEmpty())
		{
			T ret = data[front];
			front = (front + 1) % capacity;
			numOfElements--;
			if(numOfElements < capacity / 4)
			{
				T* temp = new T[numOfElements];
				for(int i = 0 ; i < numOfElements ; i++)
				{
					temp[i] = data[front++];
				}
				this -> ~Queue();
				capacity /= 2;
				data = new T[capacity];
				for(int i = 0 ; i < numOfElements ; i++)
				{
					data[i] = temp[i];
				}
				front = 0;
				rear = numOfElements;
			}

			return ret;
		}
		
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
