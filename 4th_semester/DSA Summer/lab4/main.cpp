#include "Queue.h"
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream fin("names.txt");
	if(!fin)
	{
		cout << "ERROR!!! File Not Found." << endl;
	}
	else
	{
		int numOfNames, num=0;
		fin>>numOfNames;

		char** names=new char* [numOfNames];
		for(int i=0;i<numOfNames;i++)
		{
			names[i]=new char[30]; //different location memories
		}

		Queue<char*> q(numOfNames);
	
		for(int i=0;i<numOfNames;i++)
		{
			
			fin>>names[i];
			q.enqueue(names[i]);
		}
	
		cout<<"Enter rotation count: ";
		cin>>num;
	
		while(q.getNumOfElements()!=1)
		{
			for(int i=0;i<num;i++)
			{
				q.enqueue(q.dequeue());
			}

			q.dequeue();
		}

		cout<<"Winner: "<<q.dequeue()<<endl;

		//deAllocation

		for(int i=0;i<numOfNames;i++)
		{
			delete [] names[i];
			names[i]=0;
		}
		delete [] names;
		names=0;

	}

	return 0;
}