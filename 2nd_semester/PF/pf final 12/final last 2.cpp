#include <iostream>
#include<fstream>

using namespace std;

struct Account {
int accountID; char name [51]; double balance;
};

int main()
{	
	int accounts=0, i=0;
    ifstream fin("account.dat",ios::binary);
	
	fin.read(reinterpret_cast<char*>(&accounts),sizeof(int));

	cout<<accounts<<endl;

	Account *ptr=new Account[accounts];

	for(i=0;i<accounts;i++)
	{

		fin.read(reinterpret_cast<char*>(&ptr[i]),sizeof(ptr[i]));
		cout<<ptr[i].accountID<<"  ";
		cout<<ptr[i].name<<endl;
		cout<<ptr[i].balance;
		cout<<endl;

			

	}

	fin.close();


	delete [] ptr;
	ptr=0;

    return 0;

}
