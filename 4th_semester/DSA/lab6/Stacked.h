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

	void reverse()
	{
		int size=this->getNumberOfElements();
		T* temp=new T [size];
		int ind=0;
		for(int i=size-1;i>=0;i--)
		{
			temp[ind]=data[i];
			ind++;
		}
		delete [] data;
		data=temp;
	}

	int flip()
	{
		int size=this->getNumberOfElements();
		int count=0;
		int min, max;

		min=data[0];
		for(int i=1;i<size;i++)
		{
			if(data[i]<min)
			{
				min=data[i];
			}
		}
		max=data[0];
		for(int i=1;i<size;i++)
		{
			if(data[i]>max)
			{
				max=data[i];
			}
		}S

		int start=0;
		while(data[0]==min && data[size-1]==max)
		{

		}

	}


};
#endif