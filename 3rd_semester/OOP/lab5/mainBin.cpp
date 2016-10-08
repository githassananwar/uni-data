#include "BinNum.h"

#include<iostream>

using namespace std;

int main()
{
	BinNum b1(10);
	b1.print();
	cout<<endl;

	BinNum b2(b1);
	b2.print();
	cout<<endl;

	cout<<"Getter value: "<<b2[1]<<endl;
	cout<<endl;

	cout<<"Setter:-"<<endl;
	b2[1]=1;
	b2.print();
	cout<<endl;

	BinNum b3;
	b3=!b1;
	b3.print();
	cout<<endl;

	b3(0,1);
	cout<<endl;

	return 0;
}