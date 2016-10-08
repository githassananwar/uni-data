#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main ()
{


	ifstream fin("file.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be opened" << endl;
	}
	else 
	{

		int count=1, totalCount=0;

		char name[40];
		char fruit[40];
		
		cout << "Enter fruit name: ";
		cin >> name;

		cout << "The word " << name << " occurs on these lines:" <<endl;

		fin>>fruit;
		while(!fin.eof())
		{
			if (strcmp(name,fruit) == 0)
			{
				cout << "Line " << count << endl;
				totalCount++;

			}

			count++;
			fin>>fruit;

		}
	
		cout << "Total occurences: " << totalCount << endl;


		fin.close();

	}

	return 0;

}


