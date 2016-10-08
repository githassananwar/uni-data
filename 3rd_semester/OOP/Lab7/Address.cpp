#include "Address.h"
#include "CharString.h"
#include<iostream>

using namespace std;


Address::Address(int h, char b, int s, CharString cn)
{
	houseNo=h;
	block=b;
	streetNo=s;
	city=cn;
}

void Address::operator=(const Address& add)
{
	houseNo=add.houseNo;
	block=add.block;
	streetNo=add.streetNo;
	city=add.city;
}

void Address::displayAddress()
{
	cout<<"House no: "<<houseNo<<", Block : "<<block<<", Street no: "<<streetNo<<", ";
	cout<<city;
	cout<<"."<<endl;
}


Address::~Address(void)
{
}
