#include "CharString.h"

#include<iostream>

using namespace std;

//Prototype of string length function
int strLength(const char*); //returns length of string including place of null character

CharString::CharString()
{
	cout<<"Default ctor called."<<endl;
	size=0;
	cstr=0;
}


CharString:: CharString(const char* src)
{
	cout<<"Ctor(const char*) called."<<endl;
	int i=0;
	
	size=strLength(src);
	cstr=new char[size];
	for(i=0;src[i]!='\0';i++)
	{
		cstr[i]=src[i];
	}

	cstr[i]='\0';

}

CharString::CharString(const char* src, int n)
{
	cout<<"Ctor(const char*,int) called."<<endl;

	int i=0, count=0;

	size=strLength(src);

	if(n<0)
	{
		n=0;
	}

	cstr=new char[size];

	for(i=0;i<n && src[i]!='\0';i++)
	{
		cstr[i]=src[i];
	}
	
	cstr[i]='\0';


}

CharString::CharString(const CharString & src)
{
	cout<<"Ctor(const CharString&) called."<<endl;

	int i=0;

	size=src.Size()+1;

	cstr=new char[size];
	for(i=0;src.cstr[i]!='\0';i++)
	{
		cstr[i]=src.cstr[i];
	}

	cstr[i]='\0';

}

CharString::CharString(const CharString& src, int n)
{
	cout<<"Ctor(const CharString&, int) called."<<endl;
	int i=0;

	size=src.Size()+1;

	if(n<0)
	{
		n=0;
	}

	cstr=new char[size];

	for(i=0;i<n && src.cstr[i]!='\0';i++)
	{
		cstr[i]=src.cstr[i];
	}
	
	cstr[i]='\0';

}

int CharString::Size() const
{
	int i=0, len=0;
	
	for(i=0;cstr[i]!='\0';i++)
	{
		len++;
	}

	return len;
}

void CharString :: clear()
{
	delete [] cstr;
	size=0;
	cstr=0;
	cout<<"Cleared"<<endl;

}

void CharString :: print() const
{
	cout<<"Print string: "<<cstr<<endl;

}

void CharString :: CopyFrom(const char* src)
{
	int i=0, count=0;
	this->clear();

	size=strLength(src);

	cstr=new char[size];

	for(i=0;src[i]!='\0';i++)
	{
		cstr[i]=src[i];
	}

	cstr[i]='\0';


}

void CharString :: CopyFrom(const char* src, int n, int start)
{
	int i=0, len=0;

	this->clear();

	size=strLength(src);
	len=size-1;

	cstr=new char[size];

	if(n<0)
	{
		n=0;
	}

	if(start<0 || start>len)
	{
		start=0;
	}

	while(i<n)
	{
		if(src[start]!='\0')
		{
			cstr[i]=src[start];
		}
		else
			break;
		i++;
		start++;
	}

	cstr[i]='\0';


}

void CharString::CopyFrom(const CharString& src)
{
	int i=0, count=0;
	this->clear();
	
	size=src.size; //as this size if of object's data member size, it already includes null char space.
	
	cstr=new char[size];

	for(i=0;src.cstr[i]!='\0';i++)
	{
		cstr[i]=src.cstr[i];
	}

	cstr[i]='\0';

}

void CharString::CopyFrom(const CharString& src, int n, int start)
{
	int i=0, count=0;
	this->clear();
	
	size=src.size;

	cstr=new char[size];

	if(n<0)
	{
		n=0;
	}

	if(start<0 || start>size-1) //size-1 represents that start can be at null char place for its maximum value.
	{
		start=0;
	}

	while(i<n)
	{
		if(src.cstr[start]!='\0')
		{
			cstr[i]=src.cstr[start];
		}
		else
			break;
		i++;
		start++;
	}

	cstr[i]='\0';

}

CharString CharString::Substring(int n , int start) const
{
	CharString cs;

	if(n<0)
	{
		n=0;
	}

	if(start<0 || start>size-1) //size-1 explained above.
	{
		start=0;
	}
	
	cs.CopyFrom(cstr,n,start);

	return cs;

}

int CharString::FindSubstring(const char* str, int start) const
{
	int i=0, j=0, count=0, len=0, found=-1;
	
	len=strLength(str)-1; //minus 1 - length of str excluding null char place.
	
	if(start<0 || start>size-1)
	{
		start=0;
	}

	if(len < this->Size() && len!=0) //if check to ensure that it must be a substring and not an empty string
	{
		for(i=start;cstr[i]!='\0';i++)
		{
			if(str[j]==cstr[i])
			{
				found=i;
				count++;
				j++;
			}
			else
			{
				count=0;
				j=0;
			}

			if(count==len)
			{
				found=found-len+1;
				break;
			}		

		}

	}

	if(count==len)
	{
		return found;

	}
	else
		return -1;
	

}

int CharString::FindSubstring(const CharString& str, int start) const
{
	int i=0, j=0, count=0, len=0, found=-1;
	
	len=str.Size();

	if(start<0 || start>size-1)
	{
		start=0;
	}

	if(len < this->Size() && len!=0) //if check to ensure that it must be a substring and not an empty string
	{
		for(i=start;cstr[i]!='\0';i++)
		{
			if(str.cstr[j]==cstr[i])
			{
				found=i;
				count++;
				j++;
			}
			else
			{
				count=0;
				j=0;
			}

			if(count==len)
			{
				found=found-len+1;
				break;
			}		

		}

	}
	
	if(count==len)
	{
		return found;

	}
	else
		return -1;


}

void CharString::concat(const char* str)
{
	int i=0, lastInd=0, count=0, nSize=0, oSize=size; //oSize includes place for null char

	//a reserve dynamic array to store string of object. 
	char *res=new char[oSize];
	for(i=0;i<oSize;i++)
	{
		res[i]=cstr[i];
	}

	//to calculate length of incoming string
	nSize=strLength(str)-1; //excluding place of null char

	//to create a new cstr array of required size
	delete [] cstr;

	//updating size and allocating memory
	size=oSize+nSize;
	cstr=new char[size];

	//copying back in cstr. 
	for(i=0;i<oSize;i++)
	{
		cstr[i]=res[i];
	}

	delete [] res;
	res=0;

	//Concat
	for(i=0;cstr[i]!='\0';i++)
	{
		lastInd=i;
	}
	lastInd++;
	for(i=0;str[i]!='\0';i++)
	{
		cstr[lastInd]=str[i];
		lastInd++;
	}

	cstr[lastInd]='\0';

	cout<<"Concatenated String: "<<cstr<<endl;

}

void CharString::concat(const char* str, int n, int start)
{
	int i=0,count=0, lastInd=0, len=0, nSize=0, oSize=size;

	//a reserve dynamic array to store string of object. 
	char *res=new char[oSize];
	for(i=0;i<oSize;i++)
	{
		res[i]=cstr[i];
	}
	
	//to calculate length of incoming string
	nSize=strLength(str)-1; //excluding place of null char

	//to create a new cstr array of required size
	delete [] cstr;

	//updating size and allocating memory
	size=oSize+nSize;
	cstr=new char[size];

	//copying back in cstr. 
	for(i=0;i<oSize;i++)
	{
		cstr[i]=res[i];
	}

	delete [] res;
	res=0;

	////
	if(n<0)
	{
		n=0;
	}

	if(start<0 || start>nSize)
	{
		start=0;
	}

	/////

	//Concat
	count=0;

	for(i=0;cstr[i]!='\0';i++)
	{
		lastInd=i;
	}
	lastInd++;
	for(i=start;count<n && str[i]!='\0';i++)
	{
		cstr[lastInd]=str[i];
		lastInd++;
		count++;
	
	}

	cstr[lastInd]='\0';

	cout<<"Concatenated String: "<<cstr<<endl;


}

void CharString::append ( const CharString& str )
{
	int i=0, lastInd=0, count=0, nSize=0, oSize=size;

	//a reserve dynamic array to store string of object. 
	char *res=new char[oSize];
	for(i=0;i<oSize;i++)
	{
		res[i]=cstr[i];
	}

	//to calculate length of incoming string
	nSize=str.Size();

	//to create a new cstr array of required size
	delete [] cstr;

	//updating and allocating memory
	size=oSize+nSize;
	cstr=new char[size];

	//copying back in cstr. 
	for(i=0;i<oSize;i++)
	{
		cstr[i]=res[i];
	}

	delete [] res;
	res=0;

	//Concat
	for(i=0;cstr[i]!='\0';i++)
	{
		lastInd=i;
	}
	lastInd++;
	for(i=0;str.cstr[i]!='\0';i++)
	{
		cstr[lastInd]=str.cstr[i];
		lastInd++;
	}

	cstr[lastInd]='\0';

	cout<<"Concatenated String: "<<cstr<<endl;

}

void CharString::append ( const CharString& str, int n, int start)
{
	int i=0,count=0, lastInd=0, len=0, nSize=0, oSize=size;

	//a reserve dynamic array to store string of object. 
	char *res=new char[oSize];
	for(i=0;i<oSize;i++)
	{
		res[i]=cstr[i];
	}

	//to calculate length of incoming string
	nSize=str.Size();

	//to create a new cstr array of required size
	delete [] cstr;

	//updating size and allocating memory
	size=oSize+nSize;
	cstr=new char[size];

	//copying back in cstr. 
	for(i=0;i<oSize;i++)
	{
		cstr[i]=res[i];
	}

	delete [] res;
	res=0;

	//Validation
	if(n<0)
	{
		n=0;
	}

	if(start<0 || start>nSize)
	{
		start=0;
	}


	//Concat
	count=0;
	for(i=0;cstr[i]!='\0';i++)
	{
		lastInd=i;
	}
	lastInd++;
	for(i=start;count<n && str.cstr[i]!='\0';i++)
	{
		cstr[lastInd]=str.cstr[i];
		lastInd++;
		count++;
	
	}

	cstr[lastInd]='\0';

	cout<<"Concatenated String: "<<cstr<<endl;

}


CharString::~CharString()
{
	delete [] cstr;
	cstr=0;

}

//Our own defined function
int strLength(const char* string)
{
	int count=0;
	for(int i=0;string[i]!='\0';i++)
	{
		count++;
	}

	count=count+1;

	return count;

}
