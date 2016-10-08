#include<iostream>
#include<cctype>
using namespace std;

int main ()
{
	int num=32;
	char ch='a';

	cout<<"Testing isalpha() ..."<<endl;
	if(isalpha(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a letter of alphabet"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a letter alphabet"<<endl;
	}


	cout<<endl<<"Testing isalnum() ..."<<endl;
	if(isalnum(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a letter of the alphabet or a digit"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a letter of the alphabet or a digit"<<endl;
	}


	cout<<endl<<"Testing isdigit() ..."<<endl;
	if(isdigit(num))
	{
		cout<<"Given Parameter '"<<num<<"' is a digit through 0 to 9"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<num<<"' is NOT a digit through 0 to 9"<<endl;
	}

	cout<<endl<<"Testing islower() ..."<<endl;
	if(islower(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a lowercase letter"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a lowercase letter"<<endl;
	}


	cout<<endl<<"Testing isupper() ..."<<endl;
	if(isupper(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a uppercase letter"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a uppercase letter"<<endl;
	}

	cout<<endl<<"Testing isspace() ..."<<endl;
	if(isspace('\n'))
	{
		cout<<"Given Parameter is a whitespace character"<<endl;
	}
	else
	{
		cout<<"Given Parameter is NOT a whitespace character"<<endl<<endl;
	}

   

	return 0;

}
