#include "HugeInteger.h"
#include<iostream>

using namespace std;

int main()
{
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		HugeInteger h1, h2, h3;
		
		cout<<"Input and printing values:-"<<endl;
		cin>>h1;
		cout<<h1;

		cout<<endl;

		cin>>h2;
		cout<<h2;
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Addition result:-"<<endl;
		h3=h1+h2;
		cout<<h3;
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Subtraction result:-"<<endl;
		h3=h1-h2;
		cout<<h3;
		cout<<endl;
		/////////////////////////////////////////
	
		cout<<"Equality check:-"<<endl;
		if(h1==h2)
		{
			cout<<"True."<<endl;
		}
		else
		{
			cout<<"False."<<endl;
		}
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Non Equality check:-"<<endl;
		if(h1!=h2)
		{
			cout<<"True."<<endl;
		}
		else
		{
			cout<<"False."<<endl;
		}
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Greater value check:-"<<endl;
		if(h1>h2)
		{
			cout<<"True."<<endl;
		}
		else
		{
			cout<<"False."<<endl;
		}
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Lesser value check:-"<<endl;
		if(h1<h2)
		{
			cout<<"True."<<endl;
		}
		else
		{
			cout<<"False."<<endl;
		}
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Greater or equal to check:-"<<endl;
		if(h1>=h2)
		{
			cout<<"True."<<endl;
		}
		else
		{
			cout<<"False."<<endl;
		}
		cout<<endl;
		/////////////////////////////////////////

		cout<<"Lesser or equal to check:-"<<endl;
		if(h1<=h2)
		{
			cout<<"True."<<endl;
		}
		else
		{
			cout<<"False."<<endl;
		}
		cout<<endl;
		/////////////////////////////////////////

		cout<<"For other Huge Integers press 'Y' otherwise any key to quit: ";
		cin.ignore();
		cin.get(ch);
		cout<<endl;

	}
	
	return 0;

}