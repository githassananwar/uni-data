#include "Set.h"

#include<iostream>

using namespace std;

Set::Set(int size)
{
	if(size<0)
	{
		this->size=0;
		this->set=0;
	}
	else
	{
		this->size=size;
		this->set=new int[size];

		int i=0, input=0;
		for(i=0;i<size;i++)
		{
			cout<<"Enter number at "<<i<<" index: ";
			cin>>input;
			while(input<0||input>100)
			{
				cout<<"Invalid input. Enter again: ";
				cin>>input;
			}
			this->set[i]=input;
		}
		
	}
	
}

Set::Set(const Set& s)
{
	int i=0;
	this->size=s.size;
	this->set=new int[size];
	for(i=0;i<size;i++)
	{
		this->set[i]=s.set[i];
	}

}

Set Set::Union(const Set& s)
{
	int i=0,ind=0, j=0, check=0;
	Set sr;
	sr.size=this->size+s.size;
	sr.set=new int[sr.size];
	for(i=0;i<this->size;i++)
	{
		sr.set[ind]=this->set[i];
		ind++;
	}
	for(i=0;i<s.size;i++)
	{
		check=0;
		for(j=0;j<this->size;j++)
		{
			if(sr.set[j]==s.set[i])
			{
				check=1;
				break;
			}

		}
		if(check==0)
		{
			sr.set[ind]=s.set[i];
			ind++;
		}	
		
	}

	if(ind<sr.size)
	{
		for(ind;ind<sr.size;ind++)
		{
			sr.set[ind]=-1;
		}
	}

	return sr;

}

Set Set::intersection(const Set& s) const
{
	int i=0, j=0, ind=0, check=0;
	Set sr;
	sr.size=this->size+s.size;
	sr.set=new int[sr.size];
	for(i=0;i<this->size;i++)
	{
		check=0;
		for(j=0;j<s.size;j++)
		{
			if(this->set[i]==s.set[j])
			{
				check=1;
				break;
			}
		}
		if(check==1)
		{
			sr.set[ind]=this->set[i];
			ind++;

		}
	}
	
	if(ind<sr.size)
	{
		for(ind;ind<sr.size;ind++)
		{
			sr.set[ind]=-1;
		}
	}


	return sr;
}

bool Set::isEqualTo(const Set& s) const
{
	int i=0, j=0, count=0;
	if(this->size==s.size)
	{
		for(i=0;i<this->size;i++)
		{
			if(this->set[i]==s.set[i])
			{
				count++;
			}
		}
	}
	if(count==size)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void Set::print( ) const
{
	int i=0;
	cout<<"Set elements: "<<endl;
	for(i=0;i<this->size && this->set[i]!=-1 ;i++)
	{
		cout<<this->set[i]<<"  ";
	}

	cout<<endl;

}

Set::~Set()
{
	delete [] set;
	set=0;
}
