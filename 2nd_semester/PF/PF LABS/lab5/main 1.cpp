#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>


using namespace std;


int main ()
{
	
	ifstream fin("names.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be created" << endl;
	}
	else
	{
	
		const int SIZE=1000;
		char name1[SIZE];
		char name2[SIZE];
		char name3[SIZE];

		fin.getline(name1,SIZE);

		fin.getline(name2,SIZE);

		fin.getline(name3,SIZE);

		ofstream fout("sortedNames.txt");

		//first condition check
		if(strcmp(name1,name2)<0 && strcmp(name1,name3)<0 && strcmp(name2,name3)<0)
		{
			
			fout << name1 << endl;
			fout << name2 << endl;
			fout << name3 << endl;
			fout.close();
			cout << "Work done!" << endl;
		}
		else if(strcmp(name1,name2)<0 && strcmp(name1,name3)<0 && strcmp(name3,name2)<0)
		{
			ofstream fout("sortedNames.txt");
			fout << name1 << endl;
			fout << name3 << endl;
			fout << name2 << endl;
			fout.close();
			cout << "Work done!" << endl;
		}



		//second condition check
		else if(strcmp(name2,name1)<0 && strcmp(name2,name3)<0 && strcmp(name1,name3)<0)
		{
			ofstream fout("sortedNames.txt");
			fout << name2 << endl;
			fout << name1 << endl;
			fout << name3 << endl;
			fout.close();
			cout << "Work done!" << endl;
		}
		else if(strcmp(name2,name1)<0 && strcmp(name2,name3)<0 && strcmp(name3,name1)<0)
		{
			ofstream fout("sortedNames.txt");
			fout << name2 << endl;
			fout << name3 << endl;
			fout << name1 << endl;
			fout.close();
			cout << "Work done!" << endl;
		}
		


		//third condition check
		else if(strcmp(name3,name1)<0 && strcmp(name3,name2)<0 && strcmp(name1,name2)<0)
		{
			ofstream fout("sortedNames.txt");
			fout << name3 << endl;
			fout << name1 << endl;
			fout << name2 << endl;
			fout.close();
			cout << "Work done!" << endl;
		}
		else if(strcmp(name3,name1)<0 && strcmp(name3,name2)<0 && strcmp(name2,name1)<0)
		{
			ofstream fout("sortedNames.txt");
			fout << name3 << endl;
			fout << name2 << endl;
			fout << name1 << endl;
			fout.close();
			cout << "Work done!" << endl;
		}



		fin.close();
		
	}

	return 0;

}


