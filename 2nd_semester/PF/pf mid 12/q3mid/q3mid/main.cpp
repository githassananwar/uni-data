#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	/*ifstream fin("data.txt");

	if(!fin)
	{
		cout<<"ERROR!!! File not found."<<endl;
	}

	else
	{

		int const size=100;
		char mor='M';
		char after='A';
		char ip;

		char input[size];

		int total=0,max=0, maxMor=0, maxAfter=0;
		int count=1;

		fin>>total;

		for(count=1;count<=total;count++)
		{
			fin>>input;

			ip=input[6];

			if(ip==mor)
			{
				fin>>max;

				if(max>maxMor)
				{
					maxMor=max;

				}

			}
			else if(ip==after)
			{
				fin>>max;

				if(max>maxAfter)
				{
					maxAfter=max;

				}


			}


		}

		cout<<"Maximum marks in Morning: "<<maxMor<<endl;
		cout<<"Maximum marks in Afternoon: "<<maxAfter<<endl;*/

	int n=22;
	int*p=&n;
	cout<<*p<<endl;
	int* &q=p;
	*q=*q+1;
	cout<<&p<<endl;
	cout<<&q<<endl;
	cout<<*p<<endl;
	cout<<&n<<endl;
	cout<<p<<endl;
	cout<<q<<endl;



	//}









}
