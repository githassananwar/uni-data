#include<iostream>
#include<cstring>

using namespace std;

int main ()
{
	char string[50];
	char search[50];
	char nword[50];
	int count=0;

	cout<<"Enter string: ";
	cin.getline(string,50);

	int strL=strlen(string);

	char *strPtr=0;

	cout<<"Enter word to be replaced in the string: ";
	cin>>search;
	int searchL=strlen(search);

	cout<<"Enter word to be placed in the string: ";
	cin>>nword;

	int wordL=strlen(nword);

	int result=wordL-searchL;

	char *ptr=string;

	while(ptr!=0)
	{
		ptr=strstr(ptr,search);
		if(ptr!=0)
		{
			count=count+1;
			ptr=ptr+1;
		}

	}

	int n=strL+(result*count)+1;

	strPtr=new char[n];

	count=0;
	int count2=0;

	char *chkPtr=string;
	ptr=string;

	while(ptr!=0)
	{

		ptr=strstr(ptr,search);

        if(ptr!=0)
		{
			//it will copy the string array upto search word occurence.
		    while(chkPtr<ptr)
            {
                strPtr[count]=string[count2];
                count++;
                count2++;
                chkPtr++;
            }

			//it will replace the other word
			strncpy(strPtr+count,nword,wordL);

			//increment in counts to set the position after the placement of word.
			count=count+wordL;
			count2=count2+searchL;

			//to set the position of pointer accordingly. .
			chkPtr=chkPtr+searchL;

			ptr++;

		}
		else if(ptr==0)
		{
			//for copying the remaining array.
		    while(chkPtr<string+strL)
		    {
		        strPtr[count]=string[count2];
                count++;
                count2++;
                chkPtr++;
		    }
		    strPtr[count]='\0';
		}

	}

	cout<<strPtr<<endl;

	delete [] strPtr;
	//strPtr=0;

    return 0;

}

