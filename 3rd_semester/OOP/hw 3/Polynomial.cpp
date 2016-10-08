#include "Polynomial.h"

#include<iostream>
#include<cmath>

using namespace std;


Polynomial::Polynomial()
{
	for(int i=0;i<15;i++)
	{
		arr[i]=0;
	}
	input();
}

Polynomial::Polynomial(int)
{
	for(int i=0;i<15;i++)
	{
		arr[i]=0;
	}
}

void Polynomial ::input()
{
	int i=0, terms=0, exp=0;
	cout<<"Enter number of terms of P(x): ";
	cin>>terms;
	while(terms<0||terms>15)
	{
		cout<<"Invalid number of terms. Enter again: ";
		cin>>terms;
	}
	
	for(i=0;i<terms;i++)
	{
		cout<<"Enter exponent: ";
		cin>>exp;
		while(exp<0 || exp>14 || arr[exp]!=0)
		{
			cout<<"Invalid exponent. Enter again: ";
			cin>>exp;
		}
		cout<<"Enter co-efficient of x^"<<exp<<" : ";
		cin>>arr[exp];
	}

}

Polynomial Polynomial :: operator+(const Polynomial& p)
{
	Polynomial pr(5); //5 just to call other default constructor defined.
	for(int i=0;i<15;i++)
	{
		pr.arr[i]=arr[i]+p.arr[i];
	}

	return pr;

}

int Polynomial :: evaluate(int n)
{
	int res=0;
	for(int i=0;i<15;i++)
	{
		if(arr[i]!=0)
		{
			res=( arr[i] * pow(n,(double)i) )+res;
		}
	}

	return res;
}


void operator <<(ostream & out, const Polynomial& p)
{
	out<<"P(x) = ";
	bool flag=1;
	for(int i=14;i>=0;i--)
	{
		if(p.arr[i]!=0)
		{
			if(p.arr[i]>=0 && flag)
			{
				out<<p.arr[i]<<"x^"<<i;
				flag=0;
			}
			else if(p.arr[i]<0 && flag)
			{
				out<<p.arr[i]<<"x^"<<i;
				flag=0;
			}
			else if(p.arr[i]>=0)
			{
				out<<" + "<<p.arr[i]<<"x^"<<i;

			}
			else
			{
				out<<" "<<p.arr[i]<<"x^"<<i;
			}

		}

	}
	cout<<endl;

}


Polynomial::~Polynomial(void)
{
}
