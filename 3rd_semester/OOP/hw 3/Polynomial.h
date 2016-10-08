#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>

using namespace std;

class Polynomial
{
private:
	int arr[15];
	void input();
public:
	Polynomial();
	Polynomial(int);
	Polynomial operator+(const Polynomial&);
	int evaluate(int n);
	friend void operator <<(ostream &, const Polynomial&);

	~Polynomial(void);
};

#endif