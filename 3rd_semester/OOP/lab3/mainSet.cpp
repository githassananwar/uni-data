#include "Set.h"

#include<iostream>

using namespace std;

int main()
{
	cout<<"Ctor test. ."<<endl;
	Set s1(4);
	s1.print();

	cout<<endl;

	Set s2(5);
	s2.print();

	cout<<endl<<"Copy ctor test. ."<<endl;
	Set s3(s1);
	s3.print();


	cout<<endl<<"Union. ."<<endl;
	Set s4(s1.Union(s2));
	s4.print();


	cout<<endl<<"Intersection. ."<<endl;
	Set s5(s1.intersection(s2));
	s5.print();
	
	cout<<endl<<"Equal. ."<<endl;
	if(s2.isEqualTo(s1))
	{
		cout<<"Equal sets."<<endl;
	}
	else
	{
		cout<<"Not equal."<<endl;
	}

	return 0;
}