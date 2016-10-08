
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int sradix,tradix,dec=0,num=0,chk=0,st_num=0,con=0,b=0,p=0,v=0;

	cout<<"Enter the source index:"<<endl;
	cin>>sradix;
	while(sradix<2||sradix>9)
	{
		cout<<"Enter source index again:"<<endl;
		cin>>sradix;
	}
	cout<<"Enter the target index:"<<endl;
	cin>>tradix;
	while(tradix<2||tradix>9)
	{
		cout<<"Enter target index again:"<<endl;
		cin>>tradix;
	}


	if(sradix==2)
	{

		cout<<"Enter numbers from 0 to 1. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>1||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
       else
           {st_num=st_num/10;}
    }


	}
	if(sradix==3)
	{
		cout<<"Enter numbers from 0 to 2. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>2||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
       else
           {st_num=st_num/10;}
    }



	}
	if(sradix==4)
	{
		cout<<"Enter numbers from 0 to 3. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>3||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
           else
           {st_num=st_num/10;}
    }


	}
	if(sradix==5)
	{
		cout<<"Enter numbers from 0 to 4. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>4||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
           else
           {st_num=st_num/10;}
    }

	}
	if(sradix==6)
	{
		cout<<"Enter numbers from 0 to 5. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>5||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
           else
           {st_num=st_num/10;}
    }


	}
	if(sradix==7)
	{
		cout<<"Enter numbers from 0 to 6. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>6||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
           else
           {st_num=st_num/10;}
    }


	}
	if(sradix==8)
	{
		cout<<"Enter numbers from 0 to 7. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>7||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
           else
           {st_num=st_num/10;}
    }


	}
	if(sradix==9)
	{
		cout<<"Enter numbers from 0 and 8. ."<<endl;
		cin>>num;
		st_num=num;
		while(st_num>0)
    {
         chk=st_num%10;
         if(chk>8||chk<0)
       {
           cout<<"Enter correct number:"<<endl;
           cin>>num;
           st_num=num;
       }
           else
           {st_num=st_num/10;}
    }


	}
	if(sradix==tradix)
	{
		cout<<"The converted value is:"<<num<<endl;
	}
	else
	{


		while(num>0)
		{
			v=num%10;
			dec=(v*(pow(sradix,p)))+dec;
			num=num/10;
			p=p+1;

		}
		cout<<"The decimal value is "<<dec<<endl;
		p=0;
		while(dec>0)
		{
			b=dec%tradix;
			con=(b*(pow(10,p)))+con;
			dec=dec/tradix;
			p=p+1;
		}
		cout<<"The converted value is "<<con<<endl;


	}


}
