#include <iostream>
#include <cmath>
using namespace std;

int lastDigit(int num);
char* floatToBinary(char* number);

int main()
{
	char number[20];
	
	char choice='y';

	while(choice=='y' || choice=='Y')
	{

		cout<<"Enter Number to get Single Precision Floating Point Representation: ";
		cin>>number;

		char* answer=floatToBinary(number);
		cout<<"32 bit form: "<<answer<<endl;

		delete [] answer;
		answer=0;

		cout<<endl<<"Do you want test another number [Y/N]: ";
		cin>>choice;
		cout<<endl;
	}

	return 0;
}

char* floatToBinary(char* number)
{
	bool negative=0;
	int point, count=0;

	int size=strlen(number);

	int i;
	for(i=0;i<size;i++)
	{
		if(number[0]=='-')
		{
			negative=1;
		}

		if(number[i]=='.')
		{
			point=i; //decimal point
		}
		else
		{
			count++; //size count
		}
	}

	//----------------------------Decimal part conversion in binary----------------------------

	char* decimal= new char [count+1];
	if(negative)
	{
		for(i=0; number[i]!='.';i++)
		{
			decimal[i]=number[i+1];
		}
		decimal[i]='\0';
	}
	else
	{
		for(i=0; number[i]!='.';i++)
		{
			decimal[i]=number[i];
		}
		decimal[i]='\0';

	}

	int decimalNum = atoi(decimal), decimalBin=0;
	int	rem=0, power=0;

	while(decimalNum>0)
	{
			rem =decimalNum %2;
			decimalBin = (rem*(pow(10.0,power)))+ decimalBin;
			decimalNum=decimalNum/2;
			power++;
	}

	delete [] decimal;
	decimal=0;
	decimal=new char [power];
	itoa(decimalBin, decimal, 10);

	//------------------------Fraction part conversion in binary------------------------

	char* fractionPart=number+ (point+1);
	int fractionNum=0;

	char* fraction=new char[23]; //max possibility

	int lastNum;
	for(i=0; atoi(fractionPart)!=0 && i<23; i++)
	{
		fractionNum=atoi(fractionPart)*2;

		lastNum=lastDigit(fractionNum);
		itoa(fractionNum, fractionPart, 10);
		
		if(lastNum==1)
		{
			fraction[i]='1';
			fractionPart=fractionPart+1;
		}
		else
		{
			fraction[i]='0';
		}
	}

	fraction[i]='\0';
	fractionPart=0;

	//----------------------Full binary form of float number----------------------

	int binSize=strlen(decimal)+strlen(fraction)+2; //+2 for null and point

	char* fullBin=new char [binSize];
	
	//Decimal part
	for(i=0;i<strlen(decimal);i++)
	{
		fullBin[i]=decimal[i];
	}

	point=i; //decimal point
	fullBin[i++]='.'; //placing point

	//Fraction part
	for(int j=0;j<strlen(fraction);j++)
	{
		fullBin[i]=fraction[j];
		i++;
	}
	fullBin[i]='\0';

	//-----------------------Calculating exponent and conversion to binary-----------------------
	count=0;
	for(i=point-1;i>0;i--)
	{
		count++; //counting exponent value
	}

	int exp=count+127, expBin=0;
	
	rem=0, power=0;
	while(exp>0)
	{
			rem =exp %2;
			expBin = (rem*(pow(10.0,power)))+ expBin;
			exp=exp/2;
			power++;
	}

	char* expArr=new char [power];
	itoa(expBin,expArr,10);

	//--------------------Final 32 bits allocation and calculation--------------------
	char* final32Bits=new char [33];
	for(i=0;i<32;i++)
	{
		final32Bits[i]='0';
	}

	//Handling negative number
	if(negative)
	{
		final32Bits[0]='1';
	}
	else
	{
		final32Bits[0]='0';
	}

	//Placing bits 
	for(i=0;i<8;i++)
	{
		final32Bits[i+1]=expArr[i];
	}

	i++; //come to 9th index

	for(int j=1;j<strlen(fullBin);j++)
	{
		if(fullBin[j]!='.')
		{
			final32Bits[i]=fullBin[j];
		}
		else
		{
			final32Bits[i]=fullBin[++j];
		}
		i++;
	}

	final32Bits[32]='\0';
	
	//
	delete [] fullBin;
	fullBin=0;
	//

	return final32Bits;
}

int lastDigit(int num)
{
	int digit=0;
	while(num !=0)
	{
		digit=num%10; 
		num=num/10;
		if(num==0)
		{
			return digit;
		}
	}
	return -1;
}