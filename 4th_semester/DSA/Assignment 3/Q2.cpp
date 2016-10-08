#include "Stacked.h"
#include <iostream>
#include <cmath>

using namespace std;

void popHandle(Stacked<char> & s, char* postFix, int& postIndex, char sign);
double evaluate(char* postfix);

int main()
{
	char infix[100];

	cout<<"Enter infix expression: ";
	cin.getline(infix,100);

	int postIndex=0, postSize=strlen(infix);

	char* postFix=new char [2*postSize];

	Stacked<char> s; //for operators

	for(int i=0;i<postSize;i++)
	{
		if(infix[i]=='+')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, '+');
			s.push(infix[i]);
		}
		else if(infix[i]=='-')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, '-');
			s.push(infix[i]);
		}
		else if(infix[i]=='/')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, '/');
			s.push(infix[i]);
		}
		else if(infix[i]=='*')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, '*');
			s.push(infix[i]);
		}
		else if(infix[i]=='%')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, '%');
			s.push(infix[i]);
		
		}
		else if(infix[i]=='^')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, '^');
			s.push(infix[i]);
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			postFix[postIndex++]=',';
			popHandle(s, postFix, postIndex, ')');
		}
		else
		{
			postFix[postIndex++]=infix[i];	
		}

	}
	while(!s.isEmpty())
	{
		postFix[postIndex++]=',';
		postFix[postIndex++]=s.pop();
	}
	postFix[postIndex]='\0';
	cout<<"Evaluated value: "<<evaluate(postFix)<<endl;

	delete [] postFix;
	postFix=0;

	return 0;
}

void popHandle(Stacked<char> & s, char* postFix, int& postIndex, char sign)
{
	if(sign=='+')
	{
		while( !s.isEmpty() && s.stackTop()!='('  && s.stackTop()!='^')
		{
			postFix[postIndex++]=s.pop();
			postFix[postIndex++]=',';
		}
		
	}
	else if(sign=='-')
	{
		while(!s.isEmpty() && s.stackTop()!='(' && s.stackTop()!='^' )
		{
			postFix[postIndex++]=s.pop();
			postFix[postIndex++]=',';
		}
		
	}
	else if(sign=='/')
	{
		while(!s.isEmpty() && s.stackTop()!='(' && s.stackTop()!='+' && s.stackTop()!='-' && s.stackTop()!='^' )
		{
			postFix[postIndex++]=s.pop();
			postFix[postIndex++]=',';
		}

	}
	else if(sign=='*')
	{
		while(!s.isEmpty() && s.stackTop()!='(' && s.stackTop()!='+' && s.stackTop()!='-' && s.stackTop()!='^' )
		{
			postFix[postIndex++]=s.pop();
			postFix[postIndex++]=',';
		}

	}
	else if(sign=='%')
	{
		while(!s.isEmpty() && s.stackTop()!='(' && s.stackTop()!='+' && s.stackTop()!='-' && s.stackTop()!='^'  )
		{
			postFix[postIndex++]=s.pop();
			postFix[postIndex++]=',';
		}
		
	}
	else if(sign=='^')
	{
		while(!s.isEmpty() && s.stackTop()!='(')
		{
			postFix[postIndex++]=s.pop();
			postFix[postIndex++]=',';
		}	
	}
	else if(sign==')')
	{
		int comma=0;
		while(!s.isEmpty() && s.stackTop()!='(')
		{
			postFix[postIndex++]=s.pop();
			if(comma>0)
			{
				postFix[postIndex++]=',';
			}
		}

		char garbage=s.pop();
	}

}

double evaluate(char* postfix)
{	
	double value=0, ans=0, val1=0, val2=0;
	Stacked<double> s;
	char* operand= strtok (postfix,",");
	while (operand != NULL)
	{
		if(operand[0]=='+' || operand[0]=='-' || operand[0]=='*' || operand[0]=='/' || operand[0]=='^' || operand[0]=='%')
		{
			if(operand[0]=='+')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1+val2;
				s.push(ans);
			}
			else if(operand[0]=='-')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1-val2;
				s.push(ans);
			}
			else if(operand[0]=='*')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1*val2;
				s.push(ans);
			}
			else if(operand[0]=='/')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1/val2;
				s.push(ans);
			}
			else if(operand[0]=='^')
			{
				val2=s.pop();
				val1=s.pop();
				ans=pow(val1,val2);
				s.push(ans);
			}
			else if(operand[0]=='%')
			{
				val2=s.pop();
				val1=s.pop();
				ans=(int)val1 % (int)val2;
				s.push(ans);
			}

			operand=operand+1;
			value=atof(operand);
			if(value!=0)
			{
				s.push(value);
			}
			
		}
		else
		{
			value=atof(operand);
			s.push(value);
		}
		
		operand= strtok (NULL,",");
		
	}
	return ans;

}
