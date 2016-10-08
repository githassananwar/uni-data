#include <iostream>
#include<fstream>

using namespace std;

struct Account {
int accountID; char name [51]; double balance;
};

int main()
{	
	int accounts=0, i=0;
    ifstream fin("account.txt");
	
	fin>>accounts;

	Account *ptr=new Account[accounts];

	for(i=0;i<accounts;i++)
	{
		fin>>ptr[i].accountID;
		fin.getline(ptr[i].name,51);
		fin>>ptr[i].balance;

	}

	fin.close();

	cout<<accounts<<endl;

	for(i=0;i<accounts;i++)
	{
		cout<<ptr[i].accountID<<"  ";
		cout<<ptr[i].name<<endl;
		cout<<ptr[i].balance;
		cout<<endl;
	}

	ofstream fout("account.dat",ios::binary);
	if(!fout)
	{
		cout<<"Error! File can't be created."<<endl;

	}
	else
	{
		fout.write(reinterpret_cast<char*>(&accounts),sizeof(int));
		for(i=0;i<accounts;i++)
		{
			fout.write(reinterpret_cast<char*>(&ptr[i]),sizeof(ptr[i]));
			
		}

		fout.close();

	}

	delete [] ptr;
	ptr=0;

    return 0;

}
