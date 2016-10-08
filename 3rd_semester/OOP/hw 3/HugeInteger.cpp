#include "HugeInteger.h"
#include<iostream>
#include<cmath>

using namespace std;

istream& operator>>(istream& ip, HugeInteger& h)
{
	int i=0, lastInd=0;
	char str[42]; //40(HI)+1(signbit)+1(nullchar)=42
	h.sign='+';

	cout<<"Enter integer value: ";
	ip>>str;

	if(str[0]=='-')
	{
		h.sign='-';

		for(i=0;str[i]!='\0';i++)
		{
			lastInd=i;
		}

		for(i=39;lastInd>0;i--)
		{
			h.arr[i]=str[lastInd];
			lastInd--;
		}
	}
	else
	{
		for(i=0;str[i]!='\0';i++)
		{
			lastInd=i;
		}

		for(i=39;lastInd>=0;i--)
		{
			h.arr[i]=str[lastInd];
			lastInd--;
		}

	}


	return ip;
	
}

ostream&::operator<<(ostream& out, const HugeInteger& h) 
{
	bool flag=0, zeroVal=1, minus=1;
	out<<"Integer value: ";


	for(int i=0;i<40;i++)
	{
		if(h.arr[i]!='0'||flag)
		{
			if(h.sign=='-' && minus)
			{
				cout<<" -";
				minus=0;
			}
			out<<h.arr[i];
			flag=1;
			zeroVal=0;
		}
		
	}
	if(zeroVal)
	{
		cout<<"0";
	}
		
	cout<<endl;

	return out;
}

HugeInteger::HugeInteger()
{
	arr=new char [41];
	for(int i=0;i<41;i++)
	{
		arr[i]='0';
	}
}

HugeInteger ::HugeInteger (const HugeInteger&h)
{
	arr=new char [41];
	sign=h.sign;
	for(int i=0;i<41;i++)
	{
		arr[i]=h.arr[i];
	}

}

HugeInteger& HugeInteger :: operator=(const HugeInteger& h)
{	
	if(this!=&h)
	{
		sign=h.sign;
		for(int i=0;i<41;i++)
		{
			arr[i]=h.arr[i];
		}
	}

	return *this;

}

HugeInteger HugeInteger :: operator+(const HugeInteger& h)
{
	HugeInteger hr, hu, hl;
	int i=0, res=0, valR=0, valL=0, rem=0, carry=0;
	bool flag=1;
	hu=*this;
	hl=h;

	if( (sign=='-'&& h.sign=='-') || (sign=='+'&& h.sign=='+') )
	{
		if(sign=='-')
		{
			hr.sign='-';
		}
		else
		{
			hr.sign='+';
		}

		for(i=39;i>=0;i--)
		{
			valL=(int)hu.arr[i];
			valL=valL-48;

			valR=(int)hl.arr[i];
			valR=valR-48;

			//Result calculation
			if(flag)
			{
				res=valL+valR;
			}
			else
			{
				res=valL+valR+carry;
				flag=1;
			}
		
			//Assignment in array indexes
			if(res<=9)
			{
				hr.arr[i]=res+48;
			}
			else
			{
				rem=res%10;
				hr.arr[i]=rem+48;
				carry=res/10;
				flag=0;
			}

		}

		return hr;
	}
	else
	{	
		hu.sign='+';
		hl.sign='+';
		hr=hu-hl;
		if( this->greater(h) )
		{
			hr.sign=sign;
		}
		else
		{
			hr.sign=h.sign;
		}
		return hr;
	}
	
}

HugeInteger HugeInteger :: operator-(const HugeInteger& h)
{
	HugeInteger hr, hu, hl;
	int i=0, res=0, valR=0, valL=0;
	bool flag=1;

	hu=*this;
	hl=h;

	if(sign=='+'&& h.sign=='+' || sign=='-'&& h.sign=='-')
	{
		if( this->greater(h) )
		{
			hr.sign=sign;
		}
		else
		{
			hu=h;
			hl=*this;	
			
			if(sign=='-')
			{
				hr.sign='+';
			}
			else
			{
				hr.sign='-';
			}

		}
		
		for(i=39;i>=0;i--)
		{
			valL=(int)hu.arr[i];

			if(flag)
			{
				valL=valL-48;	
			}
			else
			{
				valL=valL-48-1;
				flag=1;
			}

			valR=(int)hl.arr[i];
			valR=valR-48;

			//Result calculation
			if(valL>=valR)
			{
				res=valL-valR;
			}
			else
			{
				res=(10+valL)-valR;
				flag=0;
			}
		
			//Assignment in array indexes
			hr.arr[i]=res+48;
		
		}

		return hr;

	}
	else
	{
		hu.sign='+';
		hl.sign='+';
		hr=hu+hl;

		if( this->greater(h) )
		{
			hr.sign=sign;
		}
		else
		{
			hr.sign=sign;
		}

		return hr;

	}

	
}

bool HugeInteger :: operator==(const HugeInteger& h)
{
	int i=0, count=0;
	for(i=0; i<41; i++)
	{
		if(arr[i]==h.arr[i] && sign==h.sign)
		{
			count++;
		}
	}

	if(count==41)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

bool HugeInteger :: operator!=(const HugeInteger& h)
{
	int i=0, count=0;
	for(i=0; i<41; i++)
	{
		if(arr[i]==h.arr[i] && sign==h.sign)
		{
			count++;
		}
	}

	if(count!=41)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool HugeInteger :: operator>(const HugeInteger& h)
{
	for(int i=0;i<40;i++)
	{
		if( (int)arr[i]>(int)h.arr[i] )
		{
			if(sign==h.sign)
			{
				if(sign=='+')
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(sign=='-' && h.sign=='+')
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}

		else if( (int)arr[i]<(int)h.arr[i] )
		{
			if(sign==h.sign)
			{
				if(sign=='+')
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else if(sign=='+' && h.sign=='-')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		else if( arr[i]!='0' && (int)arr[i]==(int)h.arr[i] )
		{
			if(sign==h.sign)
			{
				return 0;
			}
			else if(sign=='+' && h.sign=='-')
			{
				return 1;
			}

		}

	}
	return 0;

}

bool HugeInteger :: greater(const HugeInteger& h)
{
	for(int i=0;i<40;i++)
	{
		if((int)arr[i]>(int)h.arr[i] || *this==h)
		{
			return 1;
		}
		else if((int)arr[i]<(int)h.arr[i])
		{
			return 0;
		}
		
	}
	return 0;

}

bool HugeInteger :: operator<(const HugeInteger& h)
{
	if( !(*this>h || *this==h) )
	{
		return 1;
	}
	return 0;

}

bool HugeInteger::operator>=(const HugeInteger& h)
{
	if(*this>h || *this==h)
	{
		return 1;
	}
	return 0;


}

bool HugeInteger::operator<=(const HugeInteger& h)
{
	if(*this<h || *this==h)
	{
		return 1;
	}
	return 0;


}


HugeInteger::~HugeInteger()
{
	delete [] arr;
	arr=0;
}
