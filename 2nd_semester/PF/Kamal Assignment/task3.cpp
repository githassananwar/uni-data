#include<iostream>
#include<string>
using namespace std;

int main ()
{
	
	int length=0;
	char s1[100]="Kamal Ahmed";
	char s2[100]="Pucit";
	char rs[100];

	cout<<"Testing strlen() ..."<<endl;
	length=strlen(s1);
	cout<<"Length of String '"<<s1<<"' : "<<length<<endl;

	cout<<endl<<"Testing strcat() ..."<<endl;
	strcat(s1,s2);
	cout<<"Resultant String: "<<s1<<endl;


	cout<<endl<<"Testing strcpy() ..."<<endl;
	strcpy(s1,s2);
	cout<<"Resultant String: "<<s1<<endl;

	cout<<endl<<"Testing strncat() ..."<<endl;
	strncat(s1,s2,2);
	cout<<"Resultant String: "<<s1<<endl;
	
	cout<<endl<<"Testing strncpy() ..."<<endl;
	strncpy(s1,s2,6); //Here n i.e. 6 is greater then size of s2 "Pucit"
	cout<<"Resultant String: "<<s1<<endl;

	cout<<endl<<"Testing strcmp() ..."<<endl;
	if( strcmp(s1,s2) ) // returns 0 in case of match
	{
		cout<<"Strings are NOT equal"<<endl;
	}
	else
	{
		cout<<"Strings are equal"<<endl;
	}

	cout<<endl<<"Testing strstr() ..."<<endl;
	cout<<"Occurence: "<<strstr(s1,s2)<<endl<<endl;

	return 0;

}
