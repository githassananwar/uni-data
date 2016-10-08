#include<iostream> 
#include<iomanip>
#include<fstream>
using namespace std;

int main ()
{
	
	ifstream fin("data.txt");
	if(!fin) 
	{
		cout << "ERROR!!! File can't be opened" << endl;
	}
	else
	{
		int countNum=1;
		double num=0, fst=0, scnd=0, mid=0;
		bool oddCheck;
		double odd=0, even=0, n1=0, n2=0;
		
		fin>>num;
		while(!fin.eof())
		{
			fin>>num;
			countNum = countNum+1;
		}

		//Check whether total numbers are even or odd.
		if(countNum%2 == 0)
		{
			fst = countNum/2;
			scnd = fst+1;
			oddCheck = false;
		}
		else
		{
			mid = (countNum/2)+1;
			oddCheck = true;
		}

		fin.close();

		//Again opening file. .
		ifstream fin("data.txt");
		if(!fin) 
		{
			cout << "ERROR!!! File can't be opened" << endl;
		}

		if(oddCheck == false)
		{
			countNum = 1;
			fin >> num;
			while(!fin.eof())
			{
				if(countNum == fst)
				{
					n1 = num;
				}
				else if(countNum == scnd)
				{
					n2 = num;
				}

				fin >> num;
				countNum = countNum+1;
			}

			even = (n1+n2)/2;
			cout << "Median is(for even): " << even << endl;
			fin.close();

		}
		else if(oddCheck == true)
		{
			countNum = 1;
			fin >> num;
			while(!fin.eof())
			{
				if(countNum == mid)
				{
					odd = num;
				}
				
				fin >> num;
				countNum = countNum+1;
			}
			
			
			cout << "Median is(for odd): " << odd << endl;
			fin.close();

		}		

	}

	return 0;

}


