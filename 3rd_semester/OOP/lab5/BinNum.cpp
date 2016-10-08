#include "BinNum.h"

#include<iostream>
#include<cmath>

using namespace std;


BinNum::BinNum()
{
	size=0;
	arr=0;
}

BinNum::BinNum(int n)
{
	int r=0, con =0, p=0, val=0;
	while(n>0)
	{
		r=n%2;
		con=(r*(pow(10.0,p)))+con;
		n=n/2;
		p=p+1;
	}

	size=log10( (double)con )+1;
	arr=new bool [size];
	for(int i=size-1;i>=0;i--)
	{
		val=con%10;
		if(val==0)
		{
			arr[i]=0;
		}
		else
		{
			arr[i]=1;
		}
		con=con/10;
	}

}

BinNum :: BinNum(const BinNum& b) 
{
	this->size=b.size;
	this->arr=new bool [size];
	for(int i=0;i<size;i++)
	{
		this->arr[i]=b.arr[i];
	}

}

BinNum& BinNum::operator=(const BinNum& b)
{
	if(this!=&b)
	{
		size=b.size;
		if(arr!=0)
		{
			delete [] arr;
		}
		arr=new bool[size];
		for(int i=0;i<size;i++)
		{
			arr[i]=b.arr[i];
		}

	}
	return *this;
}

bool& BinNum::operator[](int i) const
{
	if(i<0 || i>size-1)
	{
		exit(0);
	}
	else
	{
		return arr[i];
	}

}


BinNum BinNum::operator!() const
{
	cout<<"NOT operation... "<<endl;
	int count=0;
	bool flag=1;
	BinNum br;

	//Calculation of size
	for(int i=0;i<size;i++)
	{
		if(arr[i] && flag)
		{
			count=0;
		}
		else
		{
			count++;
			flag=0;
		}
	}

	br.size=count;
	br.arr=new bool [br.size];
	flag=1;
	int k=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i] && flag)
		{
			
		}
		else if(arr[i])
		{
			br.arr[k]=0;
			k++;
		}
		else
		{
			br.arr[k]=1;
			k++;
			flag=0;
		}

	}

	return br;

}

void BinNum::operator()(int i, int j)
{
	if(i<0||i>size-1)
	{
		i=0;
	}
	if(j<0||j>size-1)
	{
		j=size-1;
	}
	if(i==j)
	{
		j=j+1;
	}

	cout<<"Index "<<i<<" to "<<j<<" : ";
	for(int k=i;k<=j;k++)
	{
		cout<<(int)arr[k];
	}
	cout<<endl;

}

void BinNum :: print()
{
	cout<<"Binary form: ";
	for(int i=0;i<size;i++)
	{
		cout<<(int)arr[i];
	}
	cout<<endl;
}

BinNum::~BinNum()
{
	delete [] arr;
	arr=0;
}
