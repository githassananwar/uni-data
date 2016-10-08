#include "Mat.h"
#include<iostream>

using namespace std;

int main()
{
	Mat m1;
	m1.input();
	m1.output();

	Mat m2;
	m2.input();
	m2.output();

	Mat m3;

	m3=m1+m2;

	cout<<endl;

	cout<<"Addition result:-"<<endl;
	m3.output();

	cout<<endl;

	Mat m4;
	cout<<"Multiplication result:-"<<endl;
	m3=m1*m2;
	m3.output();

	cout<<endl;

	cout<<"Inverse result:-"<<endl;
	m3=!m1;
	m3.output();

	return 0;
}