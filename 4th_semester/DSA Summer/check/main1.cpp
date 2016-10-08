#include "Stack.h"

#include <iostream>

using namespace std;

char* reverse(char* str)
{
	int len=strlen(str);
	char* newstr=new char[len];
	int index=0;

	Stack<char>s(len);

	for(int i=len-1;i>=0;i--)
	{
		if(str[i]!=' ')
		{
			s.push(str[i]);
		}
		if(str[i]==' ' || i==0)
		{
			while(!s.isEmpty())
			{
				newstr[index++]=s.pop();
			}
			if(i!=0)
			{
				newstr[index++]=' ';
			}
			else
			{
				newstr[index]='\0';
			}


		}
	}

	return newstr;

}

int main()
{
	char str[]="My name is Bond : James Bond";
	cout<<reverse(str)<<endl;

	return 0;

}