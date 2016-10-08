#include "Stackk.h"
#include<iostream>

using namespace std;

double evaluate_postfix1(const char* exp)
{
	double value=0, ans=0, val1=0, val2=0;
	int expSize=strlen(exp);

	Stackk<double>s(expSize);
	
	for(int i=0;i<expSize;i++)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			if(exp[i]=='+')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1+val2;
				s.push(ans);
			}
			else if(exp[i]=='-')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1-val2;
				s.push(ans);
			}
			else if(exp[i]=='*')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1*val2;
				s.push(ans);
			}
			else if(exp[i]=='/')
			{
				val2=s.pop();
				val1=s.pop();
				ans=val1/val2;
				s.push(ans);
			}			
		}
		else if(exp[i]!=' ')
		{
			value=exp[i]-48;
			s.push(value);
		}
		
		
	}

	return ans;
}

int main()
{
	char postFix[]="5 9 3 / 2 * + 7 -";
	cout<<"PostFix Answer: "<<evaluate_postfix1(postFix)<<endl;

	return 0;
}