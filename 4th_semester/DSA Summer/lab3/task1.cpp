#include "Stackk.h"
#include <iostream>
using namespace std;

bool isLessOrEqualPrecedence(char sign, char stackSign) //Nikalne wala kaam
{
	if(sign=='+' && ( stackSign=='+' || stackSign=='-'|| stackSign=='*' || stackSign=='/') )
	{
		return 1;
	}
	else if(sign=='-' && ( stackSign=='+' || stackSign=='-'|| stackSign=='*' || stackSign=='/') )
	{
		return 1;
	}
	else if(sign=='*' && ( stackSign=='*' || stackSign=='/') )
	{
		return 1;
	}
	else if(sign=='/' && ( stackSign=='*' || stackSign=='/') )
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

char* infix_to_postfix (char* exp)
{
	int expSize=strlen(exp), postIndex=0;
	char* postFix=new char[expSize+1];

	Stackk<char>s(expSize);

	for(int i=0;i<expSize;i++)
	{
		if(exp[i]=='+')
		{
			if(!s.isEmpty() && isLessOrEqualPrecedence(exp[i],s.stackTop()))
			{
				postFix[postIndex++]=s.pop();
				s.push(exp[i]);
			}
			else
			{
				s.push(exp[i]);
			}
		}
		else if(exp[i]=='-')
		{
			if(!s.isEmpty() && isLessOrEqualPrecedence(exp[i],s.stackTop()))
			{
				postFix[postIndex++]=s.pop();
				s.push(exp[i]);
			}
			else
			{
				s.push(exp[i]);
			}
			
		}
		else if(exp[i]=='/')
		{
			if(!s.isEmpty() && isLessOrEqualPrecedence(exp[i],s.stackTop()))
			{
				postFix[postIndex++]=s.pop();
				s.push(exp[i]);
			}
			else
			{
				s.push(exp[i]);
			}
			
		}
		else if(exp[i]=='*')
		{
			if(!s.isEmpty() && isLessOrEqualPrecedence(exp[i],s.stackTop()))
			{
				postFix[postIndex++]=s.pop();
				s.push(exp[i]);
			}
			else
			{
				s.push(exp[i]);
			}
			
		}
		else if(exp[i]=='(')
		{
			s.push(exp[i]);
		}
		else if(exp[i]==')')
		{
			while(s.stackTop()!='(')
			{
				postFix[postIndex++]=s.pop();
			}
			s.pop();
		}
		else
		{
			postFix[postIndex++]=exp[i];	
		}

	}

	while(!s.isEmpty())
	{
		if(s.stackTop()=='(' || s.stackTop()==')' || s.stackTop()=='&' || s.stackTop()=='$')
		{
			exit(0);
		}

		postFix[postIndex++]=s.pop();
	}

	postFix[postIndex]='\0';

	return postFix;
}

int main()
{
	char infix[]="a+b*c+d";
	char* postFix=0;
	postFix=infix_to_postfix(infix);

	cout<<"PostFix: "<<postFix<<endl;

	return 0;
}
