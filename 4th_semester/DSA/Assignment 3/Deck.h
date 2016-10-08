#ifndef DECK_H
#define DECK_H

template<typename T>

class Deck
{
private:
	T* data;
	int capacity;
	int rear;
	int front;
	int numOfElements;

	void resize(int newSize)
	{
		capacity=newSize;
		T* tempData=new T[capacity];
		for(int i=0;i<numOfElements;i++)
		{
			tempData[i]=data[rear];
			rear++;
		}

		this->~Deck();
		data=tempData;
		front=0;
		rear=numOfElements-1;

		tempData=0;
	}

public:
	Deck()
	{
		capacity=1;
		data=new T[capacity];
		rear=0;
		front=0;
		numOfElements=0;
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

	Deck& operator = (const Deck<T> & d)
	{
		if(this!=&d)
		{
			capacity=d.capacity;
			rear=d.rear;
			front=d.front;
			numOfElements=d.numOfElements;

			delete [] data;
			data=new T [capacity];

			for(int i=0;i<capacity;i++)
			{
				data[i]=d.data[i];
			}
		}

		return *this;
	}

	void insertAtTail(T val)
	{
		data[rear]=val;
		rear=(rear+1)%capacity;
		numOfElements++;
		if(isFull())
		{
			this->resize(capacity*2);
		}
	}

	T deleteAtTail()
	{
		if(!isEmpty())
		{
			T ret;
			if(rear-1==-1)
			{
				ret=data[numOfElements-1];
				rear=numOfElements-1;
			}
			else
			{
				ret=data[rear-1];
				rear--;
			}

			numOfElements--;

			if( numOfElements< (capacity/4) )
			{
				this->resize(capacity/2);
			}

			return ret;
		}
		else
		{
			exit(0);
		}
	}

	bool isEmpty()
	{
		if(numOfElements==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool isFull()
	{
		if(numOfElements==capacity)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int getCapacity()
	{
		return capacity;
	}

	int getNoOfElements()
	{
		return numOfElements;
	}

	~Deck()
	{
		delete [] data;
		data=0;
	}

};

#endif
