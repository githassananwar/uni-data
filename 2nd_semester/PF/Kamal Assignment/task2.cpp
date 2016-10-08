#include<iostream>

using namespace std;


//Custom Functions
bool checkAlpha(char n)
{
	//Comparing askiis
	if( n>=65 && n<=90  )
	{
		return 1;
	}
	else if(n>=97 && n<=122)
	{
		return 1;
	}

	return 0;
}

bool checkAlnum(int n)
{
	//Comparing askiis
	if( n>=0 && n<=9)
	{
		return 1;
	}
	else if(n>=65 && n<=90  )
	{
		return 1;
	}
	else if(n>=97 && n<=122)
	{
		return 1;
	}

	return 0;
}


bool checkDigit(int n)
{
	if( n>=0 && n<=9)
	{
		return 1;
	}

	return 0;
}


bool checkLower(char n)
{
	if(n>=97 && n<=122)
	{
		return 1;
	}

	return 0;
}


bool checkUpper(char n)
{
	if( n>=65 && n<=90  )
	{
		return 1;
	}

	return 0;
}


bool checkSpace(char n)
{
	if( n==32 || n==10 || n==9 ||n==11)
	{
		return 1;
	}

	return 0;
}


int main ()
{
	int num=2;
	char ch='a';

	cout<<"Testing checkAlpha() ..."<<endl;
	if(checkAlpha(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a letter of alphabet"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a letter alphabet"<<endl;
	}


	cout<<endl<<"Testing checkAlnum() ..."<<endl;
	if(checkAlnum(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a letter of the alphabet or a digit"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a letter of the alphabet or a digit"<<endl;
	}


	cout<<endl<<"Testing checkDigit() ..."<<endl;
	if(checkDigit(num))
	{
		cout<<"Given Parameter '"<<num<<"' is a digit through 0 to 9"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<num<<"' is NOT a digit through 0 to 9"<<endl;
	}


	cout<<endl<<"Testing checkLower() ..."<<endl;
	if(checkLower(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is a lowercase letter"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT a lowercase letter"<<endl;
	}


	cout<<endl<<"Testing checkUpper() ..."<<endl;
	if(checkUpper(ch))
	{
		cout<<"Given Parameter '"<<ch<<"' is an uppercase letter"<<endl;
	}
	else
	{
		cout<<"Given Parameter '"<<ch<<"' is NOT an uppercase letter"<<endl;
	}


	cout<<endl<<"Testing checkSpace() ..."<<endl;
	if(checkSpace('\n'))
	{
		cout<<"Given Parameter is a whitespace character"<<endl;
	}
	else
	{
		cout<<"Given Parameter is NOT a whitespace character"<<endl<<endl;
	}



	return 0;


}