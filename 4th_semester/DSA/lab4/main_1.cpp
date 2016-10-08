#include "Stacked.h"
#include<iostream>
#include<string.h>
#include<cstdlib>


double evaluate(char* postfix);

using namespace std;

int main()
{
	char arr[]="134,21,+,79,/,3,*";

	cout<<evaluate(arr)<<endl;

	return 0;
}

double evaluate(char* postfix)
{	
	double value=0, ans=0, val1=0, val2=0;
	Stacked<double> s;
	char* operand= strtok (postfix,",");
	while (operand != NULL)
	{
		if(operand[0]=='+' || operand[0]=='-' || operand[0]=='*' || operand[0]=='/')
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
