#include"CharString.h"

#include<iostream>

using namespace std;

int main()
{

	char* someString="Hello people";

	cout<<"Function 1 testing. . "<<endl;
	CharString c1;
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 2 testing. . "<<endl;
	CharString c2(someString); //someString="Hello people";
	c2.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 3 testing. . "<<endl;
	CharString c3(someString,4); //someString="Hello people";
	c3.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 4 testing. . "<<endl;
	CharString c4(c2); //c2-cstr="Hello people";
	c4.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 5 testing. . "<<endl;
	CharString c5(c2,7); //c2-cstr="Hello people";
	c5.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 6 testing. . "<<endl;
	cout<<"Size of string: "<<c2.Size()<<endl; //c2-cstr="Hello people";
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 7 testing. . "<<endl;
	c3.clear();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 8 testing. ."<<endl;
	c2.print(); //c2-cstr="Hello people";
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 9 testing. ."<<endl;
	c5.CopyFrom(someString); //someString="Hello people";
	c5.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 10 testing. ."<<endl;
	c5.CopyFrom(someString,5,6); //someString="Hello people";
	c5.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 11 testing. ."<<endl;
	c5.CopyFrom(c2); //c2-cstr="Hello people";
	c5.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 12 testing. ."<<endl;
	c5.CopyFrom(c2,7,2); //c2-cstr="Hello people";
	c5.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 13 testing. ."<<endl;
	CharString c6(someString); //somestring="Hello people";
	CharString c7;
	c7.CopyFrom( c6.Substring(6,6) ); 
	c7.print();
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 14 testing. ."<<endl;
	int ind=c2.FindSubstring("le",2); //c2-cstr="Hello people";
	if(ind!=-1)
	{
		cout<<"String found at index "<<ind<<"."<<endl;
	}
	else
	{
		cout<<"String Not found."<<endl;
	}
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 15 testing. ."<<endl;
	CharString myString("Hello world");
	CharString myString2("wor");
	ind=myString.FindSubstring(myString2,2);
	if(ind!=-1)
	{
		cout<<"String found at index "<<ind<<"."<<endl;
	}
	else
	{
		cout<<"String Not found."<<endl;
	}
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 16 testing. ."<<endl;
	char* someString2="Hello";
	CharString myString3("One More...");
	myString3.concat(someString2);
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 17 testing. ."<<endl;
	myString3.concat(someString2,5,0); //someString2="Hello";
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 18 testing. ."<<endl;
	myString3.append(myString2); //myString2-cstr="wor";
	cout<<endl;
	//////////////////////////////////////////////////////////////////

	cout<<"Function 19 testing. ."<<endl;
	myString3.append(myString2,3,0); //myString2-cstr="wor";
	cout<<endl;
	//////////////////////////////////////////////////////////////////


	return 0;
}