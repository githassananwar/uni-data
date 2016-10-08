#include "Stacked.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be opened" << endl;
	}
	else
	{
		Stacked<int> s;
		int diameter;
		char ch='a';
		fin>>diameter;
		while(!fin.eof())
		{	
			if(ch!=10)
			{
				s.push(diameter);
			}
			
			fin>>diameter;
			if(!fin.eof())
			{
				fin.get(ch);
			}

			if(fin.eof() || ch==10)
			{
				s.push(diameter);
				s.reverse();
				for(int i=0;i<6;i++)
				{
					cout<<s.pop()<<endl;
				}

			}

		}

	}

	return 0;
}