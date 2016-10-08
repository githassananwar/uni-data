#ifndef STACKED_H
#define STACKED_H

template<typename T>

class Stacked
{
private:
	T * data;
	int capacity;
	int top;

public:

	Stacked()
	{
		capacity = 1;
		data = new T[capacity];
		top = 0;	
	}

	void push(T val)
	{
		if (isFull())
			reSize(capacity*2);
		data[top++] = val;
	}


	T pop()
	{
		if (isEmpty())
			exit(0);
		T val = data[--top];
		if (top > 0 && top == capacity/4)
			reSize(capacity/2);
		return val;
	}	
	

	void reSize(int newSize)
	{
		T * temp = new T[newSize];
		for(int i=0; i<top; i++)
			temp[i] = data[i];
		this->~Stacked();
		data = temp;
		capacity = newSize;
	}


	T stackTop()
	{
		if (isEmpty())
			exit(0);
		return data[top-1];
	}

	
	int getCapacity()
	{
		return capacity;
	}


	int getNumberOfElements()
	{
		return top;
	}

	Stacked(const Stacked<T> & ref)
	{
		this->capacity = ref.capacity;
		this->top = ref.top;
		for(int i = 0 ; i < top ; i++)
		{
			this->data[i] = ref.data[i];
		}
	}


	Stacked & operator=(const Stacked<T> & ref)
	{
		if( this == &ref )
		{
			return (*this);
		}
		this->capacity = ref.capacity;
		this->top = ref.top;
		for(int i = 0 ; i < top ; i++)
		{
			this->data[i] = ref.data[i];
		}
		return *this;
	}

	~Stacked()
	{
		if(!data)
			return;
		delete [] data;
	}

	bool isEmpty()
	{
		return top==0;
	}

	bool isFull()
	{
		return top==capacity;
	}


};
#endif