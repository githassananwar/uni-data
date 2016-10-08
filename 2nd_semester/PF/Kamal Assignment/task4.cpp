#include<iostream>
using namespace std;

int strLength(const char* string)
{
	int count=0;
	for(int i=0;string[i]!='\0';i++)
	{
		count++;
	}


	return count;

}

void strConcat(char* str1, char* str2)
{
	int i=0, lastInd=0;

	//Concat
	for(i=0;str1[i]!='\0';i++)
	{
		lastInd=i;
	}
	lastInd++;
	for(i=0;str2[i]!='\0';i++)
	{
		str1[lastInd]=str2[i];
		lastInd++;
	}

	str1[lastInd]='\0';


}

void strCopy(char* str1, char* str2)
{
	int i=0;
	
	for(i=0;str1[i]!='\0';i++)
	{
		str1[i]=' ';
	}

	for(i=0;str2[i]!='\0';i++)
	{
		str1[i]=str2[i];
	}

	str1[i]='\0';


}

void strNconcat(char* str1, char* str2, int n)
{
	int i=0, lastInd=0;

	//Concat
	for(i=0;str1[i]!='\0';i++)
	{
		lastInd=i;
	}
	lastInd++;
	for(i=0;str2[i]!='\0' && i<n ;i++)
	{
		str1[lastInd]=str2[i];
		lastInd++;
	}

	str1[lastInd]='\0';


}

void strNcopy(char* str1, char* str2, int n)
{
	int i=0;
	
	if(n>strLength(str2))
	{
		for(i=0;str1[i]!='\0';i++)
		{
			str1[i]=' ';
		}

		for(i=0;str2[i]!='\0' && i<n;i++)
		{
			str1[i]=str2[i];
		}

		str1[i]='\0';

	}


}


bool strCompare(char* str1, char* str2)
{
	if(strLength(str1)!=strLength(str2))
	{
		return 0;
	}
	else
	{
		int i=0;
		bool flag=0;
		
		for(i=0;str1[i]!='\0';i++)
		{
			if(str1[i]!=str2[i])
			{
				flag=1;
			}
		}
		
		return flag;
	}

}

char* myStrStr(char* str1, char* str2)
{
	int i=0;
	bool flag=true;
	if(strLength(str1) >= strLength(str2))
	{
		for(i=0;str1[i]!='\0' && str2[i]!='\0';i++)
		{
			if(str1[i]==str2[i])
			{
				for(int j=i; str1[j]!='\0' && str2[j]!='\0'; j++)
				{
					if(str1[i]!=str2[i])
					{
						flag=false;
						break;
					}
				
				}
			
				break;
			
			}
			else
			{
				flag=false;
			}

		}

		if(flag)
		{
			return str1;
		}
		else
		{
			return "\0";
		}
	}
	else
	{
		return "\0";
	}

}


int main ()
{
	int length=0;
	char s1[100]="Kamal Ahmed";
	char s2[100]="Pucit";

	cout<<"Testing strlen() ..."<<endl;
	length=strLength(s1);
	cout<<"Length of String '"<<s1<<"' : "<<length<<endl;

	cout<<endl<<"Testing strConcat() ..."<<endl;
	strConcat(s1,s2);
	cout<<"Resultant String: "<<s1<<endl;

	cout<<endl<<"Testing strCopy() ..."<<endl;
	strCopy(s1,s2);
	cout<<"Resultant String: "<<s1<<endl;

	cout<<endl<<"Testing strNconcat() ..."<<endl;
	strNconcat(s1,s2,2);
	cout<<"Resultant String: "<<s1<<endl;

	cout<<endl<<"Testing strNcopy() ..."<<endl;
	strNcopy(s1,s2,6); //Here n i.e. 6 is greater then size of s2 "Pucit"
	cout<<"Resultant String: "<<s1<<endl;

	cout<<endl<<"Testing strCompare() ..."<<endl;
	if( strCompare(s1,s2) ) // returns 0 in case of match
	{
		cout<<"Strings are NOT equal"<<endl;
	}
	else
	{
		cout<<"Strings are equal"<<endl;
	}

	cout<<endl<<"Testing myStrStr() ..."<<endl;
	cout<<"Occurence: "<<myStrStr(s1,s2)<<endl<<endl;


	return 0;

}