#include "Rational.h"
#include<iostream>
using namespace std;



Rational::Rational(int num, int den)
{
	int i=1, comFac=0;
	if(den==0)
	{
		den=1;
	}
	
	for(i=1; i<=abs(num) || i<=abs(den); i++)
	{
		if(num%i==0 && den%i==0)
		{
			comFac=i;

		}
	}
	
	if(comFac!=1)
	{
		this->numerator=num/comFac;
		this->denominator=den/comFac;
	}
	else
	{
		this->numerator=num;
		this->denominator=den;
	}
	
}

Rational::Rational (const Rational & r)
{
	this->numerator=r.numerator;

	this->denominator=r.denominator;

}

Rational Rational::add(const Rational& r) const
{
	int num=this->numerator+r.numerator;
	int den=this->denominator+r.denominator;
	Rational rt(num,den);
	
	return rt;

}

Rational Rational::subtract(const Rational & r) const
{
	int num=this->numerator-r.numerator;
	int den=this->denominator-r.denominator;
	Rational rt(num,den);
	
	return rt;

}

Rational Rational::multiply(const Rational & r) const
{
	int num=this->numerator * r.numerator;
	int den=this->denominator * r.denominator;
	Rational rt(num,den);
	
	return rt;

}

Rational Rational::divide(const Rational & r) const
{
	int num=this->numerator / r.numerator;
	int den=this->denominator / r.denominator;
	Rational rt(num,den);
	
	return rt;

}

void Rational::print( ) const
{

	cout<<"Fraction: "<<this->numerator <<"/"<<this->denominator<<endl;

}
Rational::~Rational()
{
}
