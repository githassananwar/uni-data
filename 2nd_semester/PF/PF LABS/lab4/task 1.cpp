#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main ()
{

	char name[1000];
	cout << "Enter the file name: ";
	cin >> name;
	cout << endl << endl;


	ifstream fin(name);
	if(!fin)
	{
		cout << "ERROR!!! File can't be opened" << endl;
	}
	else
	{
		int countCh=0, countSpace=0, countPrint=0, countCap=0;
		int countSmall=0, countDig=0;
		char ch;
		int askii=0, countLine=1;

		fin.get(ch);
		while(!fin.eof())
		{
			askii=ch;
		
			//Print and white space characters check.
			if(askii>32)
			{
				countPrint = countPrint+1;
			}
			else if(askii>=1 && askii<=33)
			{
				countSpace = countSpace+1;
			}


			//Printable character type check.
		    if(askii>=48 && askii<=57)
			{
				countDig = countDig+1;
			}
			
			else if(askii>=65 && askii<=90)
			{
				countCap = countCap+1;
			}

			else if(askii>=97 && askii<=122)
			{
				countSmall = countSmall+1;
			}
			
			else if(askii==10)
			{
				countLine = countLine+1;
			}
			
			countCh = countCh+1;

			fin.get(ch);
		}

		cout << "No. of line: " << countLine << endl << endl;

		cout << "Total characters: " << countCh << endl << endl;

		cout << "No. of white-space characters: " << countSpace << endl;

		cout << "No. of printable characters: " << countPrint << endl << endl;

		cout << "No. of Capital alphabets: " << countCap << endl;

		cout << "No. of Small alphabets: " << countSmall << endl;

		cout << "No. of digits: " << countDig << endl << endl;

		
		fin.close();

	}

	return 0;

}


