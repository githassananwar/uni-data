#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main ()
{
	cout << "hello";
	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be created" << endl;
	}
	else
	{
		double num1=0, num2=0, num3=0, num4=0, num5=0;
		double total=0;
		
		fin >> num1;
		fin >> num2;
		fin >> num3;
		fin >> num4;
		fin >> num5;

		total = num1+num2+num3+num4+num5;

		cout << "First number: "<< num1 << endl;
		cout << "Second number: "<< num2 << endl;
		cout << "Third number: "<< num3 << endl;
		cout << "Fourth number: "<< num4 << endl;
		cout << "Fifth number: "<< num5 << endl;

		cout << "Sum of five numbers: " << total << endl;


		

		fin.close();
		
	}

	return 0;

}


