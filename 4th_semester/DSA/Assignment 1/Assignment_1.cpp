#include<iostream>

using namespace std;

int main()
{
	int const SIZE=30;
	bool flag=1;
	int count=0;
	char email[SIZE];
	char hostId[11]="@yahoo.com";

	cout<<"Enter email: ";
	cin.getline(email,SIZE);

	int i;
	for(i=0;i<strlen(email) && flag; i++)
	{
		//Comparing askii codes
		if(email[0]==95 || email[0]>=48 && email[0]<=57)
		{
			flag=0;
		}
		else if(email[i]>=65 && email[i]<=90 || email[i]>=97 && email[i]<=122 || email[i]>=48 && email[i]<=57 || email[i]==95)
		{
			flag=1;
			count++;
		}
		else
		{
			flag=0;
		}
	}

	i--;

	if(count>0)
	{
		char * host=email+i;
		if(strcmp(host,hostId)==0)
		{
			cout<<"Valid ID"<<endl;
		}
		else
		{
			cout<<"Invalid ID"<<endl;
		}
	}
	else
	{
		cout<<"Invalid ID"<<endl;
	}
	

}