#include<iostream>

using namespace std;

char* encipher(char* key, char* input);
char* decipher(char* key, char* input);

int main()
{
	char key[50];
	char input[100];
	char repeat='y', choice='0';

	while(repeat=='y' || repeat=='Y')
	{
		cout<<"Enter key: ";
		cin.getline(key,50);

		cout<<"Enter message: ";
		cin.getline(input,100);

		cout<<"Choose option:-"<<endl;
		cout<<"1. Encipher"<<endl;
		cout<<"2. Decipher"<<endl;
		cout<<"Enter: ";
		cin>>choice;
		
		while(choice!='1' && choice!='2')
		{
			cout<<"Invalid choice. Enter again: ";
			cin>>choice;
		}

		if(choice=='1')
		{
			char* enciphed = encipher(key,input);
			cout<<"Enciphered: "<<enciphed<<endl;

			delete [] enciphed;
		}
		else if(choice=='2')
		{
			char* deciphed=decipher(key,input);
			cout<<"Deciphered: "<<deciphed<<endl;
		}

		cout<<"Do you want to cipher anohter message? [Y/N]: ";
		cin>>repeat;
		cin.ignore();
		cout<<endl;
	}

	return 0;
}


char* encipher(char* key, char* input)
{
	int inputSize=strlen(input);
	int keySize=strlen(key);		
	char* assignAndEncipher = new char [inputSize+1];
	int keyIndex=0;
	
	for(int i=0;i<inputSize;i++)
	{
		if(input[i]>=65 && input[i]<=90 || input[i]>=97 && input[i]<=122)
		{
			assignAndEncipher[i]=key[keyIndex];
			keyIndex++;
		}
		else
		{
			assignAndEncipher[i]=input[i];
			keyIndex++;
		}

		if(keyIndex==keySize)
		{
			keyIndex=0;
		}
	}

	int i=0;
	for(i=0;i<inputSize;i++)
	{
		if(input[i]>=65 && input[i]<=90)
		{
			int position = (input[i]-65)  + toupper(assignAndEncipher[i]);
			if( position >90 )
			{
				assignAndEncipher[i]= (position -90) +65 -1;
			}
			else
			{
				assignAndEncipher[i]= position;
			}
		}
		else if(input[i]>=97 && input[i]<=122)
		{
			int position = (input[i]-97)  + tolower(assignAndEncipher[i]);
			if( position >122 )
			{
				assignAndEncipher[i]= (position -122) +97 -1;
			}
			else
			{
				assignAndEncipher[i]= position;
			}
		}
	}

	assignAndEncipher[i]='\0';

	return assignAndEncipher;
}

char* decipher(char* key, char* input)
{
	int inputSize=strlen(input);
	int keySize=strlen(key);		
	char* assignAndDecipher = new char [inputSize+1];
	int keyIndex=0;
	
	for(int i=0;i<inputSize;i++)
	{
		if(input[i]>=65 && input[i]<=90 || input[i]>=97 && input[i]<=122)
		{
			assignAndDecipher[i]=key[keyIndex];
			keyIndex++;
		}
		else
		{
			assignAndDecipher[i]=input[i];
			keyIndex++;
		}

		if(keyIndex==keySize)
		{
			keyIndex=0;
		}

	}

	int i=0;
	for(i=0;i<inputSize;i++)
	{
		if(input[i]>=65 && input[i]<=90)
		{
			int position = ( input[i] - toupper(assignAndDecipher[i]) ) +65;
			if( position < 65 )
			{
				assignAndDecipher[i]=90 - (65 - position ) +1;
			}
			else
			{
				assignAndDecipher[i]= position;
			}
		}
		else if(input[i]>=97 && input[i]<=122)
		{
			int position = ( input[i] - tolower(assignAndDecipher[i]) ) +97;
			if( position < 97 )
			{
				assignAndDecipher[i]= 122 - (97 - position ) +1;
			}
			else
			{
				assignAndDecipher[i]= position;
			}
		}
	}

	assignAndDecipher[i]='\0';

	return assignAndDecipher;

}