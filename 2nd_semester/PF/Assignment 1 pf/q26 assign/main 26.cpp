#include<iostream> #include<fstream>
#include<iomanip>
#include<fstream>


using namespace std;


int main ()
{

	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File not found. ." << endl;
	}
	else
	{


	double temp=0;
	fin>>temp;



	if(temp<=-173)
	{
		cout<<"Ethyl alcohol will freeze at "<<temp<<" F"<<endl;

	}
	else if(temp>=172)
	{
		cout<<"Ethyl alcohol will boil at "<<temp<<" F"<<endl;
	}


	if(temp<=-38)
	{
		cout<<"Mercury will freeze at "<<temp<<" F"<<endl;

	}
	else if(temp>=676)
	{
		cout<<"Mercury will boil at "<<temp<<" F"<<endl;
	}


	if(temp<=-362)
	{
		cout<<"Oxygen will freeze at "<<temp<<" F"<<endl;

	}
	else if(temp>=-306)
	{
		cout<<"Oxygen will boil at "<<temp<<" F"<<endl;
	}


	if(temp<=32)
	{
		cout<<"Water will freeze at "<<temp<<" F"<<endl;

	}
	else if(temp>=212)
	{
		cout<<"Water will boil at "<<temp<<" F"<<endl;
	}




	}
	return 0;

}


