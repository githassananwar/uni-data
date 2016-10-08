#include "Polynomial.h"

#include<iostream>

using namespace std;

int main()
{
	int val=0;
	Polynomial p1;

	cout<<p1;
	cout<<endl;

	Polynomial p2;
	cout<<p2;
	cout<<endl;

	cout<<"Addition result:-"<<endl;
	cout<<p1+p2;
	cout<<endl;

	cout<<"Enter evaluation value: ";
	cin>>val;
	cout<<endl;

	cout<<"Evaluation results:-"<<endl;
	cout<<p1.evaluate(val)<<endl;
	cout<<p2.evaluate(val)<<endl;

	return 0;
}