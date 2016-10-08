#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


int main ()
{
	const int SIZE=100;
	char file[SIZE];
	char lineContents[SIZE];

	char string[SIZE];

	int count=0;

	char *ptr=0;

	cout<<"Enter file name with extension: ";
	cin>>file;

	ifstream fin(file);
	if(!fin)
	{
		cout<<"ERROR!!! File not found."<<endl;

	}
	else
	{

		cout<<"Enter string to be searched: ";
		cin>>string;
		

		fin.getline(lineContents,SIZE);
		while(!fin.eof())
		{
			ptr=lineContents;
			ptr=strstr(ptr,string);
			while(ptr)
			{
				cout<<lineContents<<endl;
				ptr=strstr(ptr+1,string);
				count++;
			}
			fin.getline(lineContents,SIZE);
			

		}
		cout<<"Times occured: "<<count<<endl;
		

		fin.close();		
		

	}


    return 0;

}
