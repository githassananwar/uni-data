#ifndef STACKK_H
#define STACKK_H

template<typename T>

class Stackk
{
	T * data;
	int capacity;
	int top;

public:

	Stackk(int size)
	{
		if(size<=0)
			exit(0);

		capacity = size;
		data = new T[capacity];
		top = 0;	
	}

	Stackk(const Stackk<T> & ref)
	{
		this->capacity = ref.capacity;
		this->top = ref.top;
		for(int i = 0 ; i < top ; i++)
		{
			this->data[i] = ref.data[i];
		}
	}

	Stackk & operator=(const Stackk<T> & ref)
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


	void push(T val)
	{
		if (isFull())
			exit(0);
		data[top++] = val;
	}


	T pop()
	{
		if (isEmpty())
			exit(0);
		T val = data[--top];
		return val;
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

	bool isEmpty()
	{
		return top==0;
	}

	bool isFull()
	{
		return top==capacity;
	}


	~Stackk()
	{
		delete [] data;
	}

};
#endif