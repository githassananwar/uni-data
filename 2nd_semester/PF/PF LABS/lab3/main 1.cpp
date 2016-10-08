#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main ()
{
	ofstream fout("data.txt");
	if(!fout)
	{
		cout << "ERROR!!! File can't be created" << endl;
	}
	else
	{
		double num1=0, num2=0, num3=0, num4=0, num5=0;

		cout << "Enter five numbers: " << endl;
		
		cin >> num1;
		cin >> num2;
		cin >> num3;
		cin >> num4;
		cin >> num5;

		fout << num1 << endl;
		fout << num2 << endl;
		fout << num3 << endl;
		fout << num4 << endl;
		fout << num5 << endl;

		fout.close();
		
	}

	return 0;

}


