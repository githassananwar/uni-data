#include "Rational.h"
#include<iostream>

using namespace std;

int main()
{
	Rational r1(8,7);
	r1.print();

	Rational r2(2,0);
	r2.print();

	Rational r3(r1.add(r2));
	r3.print();

	Rational r4(r1.subtract(r2));
	r4.print();

	Rational r5(r1.multiply(r2));
	r5.print();

	Rational r6(r1.multiply(r2));
	r6.print();


	return 0;
}