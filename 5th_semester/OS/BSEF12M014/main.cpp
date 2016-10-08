#include "Process.h"
#include<iostream>
#include<fstream>

using namespace std;

void sortWithTime(Process* p, int n)
{
	Process temp;
	for(int i=0;i<n;i++)
	{

		for(int j=0;j<n;j++)
		{
			if(p[j].arrivalTime>p[i].arrivalTime)
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	
	}

}

void sortWithPriority(Process * p, int n)
{
	int clock=0;
	Process temp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p[j].arrivalTime>p[i].arrivalTime)
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	
	}

	
	for(int i=0;i<n;i++)
	{

		for(int j=i;j<n;j++)
		{
			if(p[j].priority<p[i].priority && clock>=p[j].arrivalTime )
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
			
		}
		clock=clock+p[i].cpuBurst;
	}

	
}

void sortWithJob(Process * p, int n)
{
	int clock=0;
	Process temp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p[j].arrivalTime>p[i].arrivalTime)
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	
	}

	
	for(int i=0;i<n;i++)
	{

		for(int j=i;j<n;j++)
		{
			if(p[j].cpuBurst<p[i].cpuBurst && clock>=p[j].arrivalTime )
			{
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
			
		}
		clock=clock+p[i].cpuBurst;
	}

	
}


void FCFS(Process* p, int n)
{
	ofstream fout;
	fout .open("output.txt");
	sortWithTime(p,n);

	int clock=0, startTime=0;
	float wtSum=0;

	for(int i=0;i<n;i++)
		{
			if(clock>=p[i].arrivalTime)
			{
				fout<<clock<<" ";
				startTime=clock;

				cout<<"(P"<<p[i].pNum<<")"<<clock;
				for(int j=0;j<p[i].cpuBurst;j++)
				{
					cout<<"-";
				}
				clock=clock+p[i].cpuBurst;
				
				fout<<clock<<" ";
				fout<<startTime-p[i].arrivalTime;
				wtSum=wtSum+ (startTime-p[i].arrivalTime);
			}
			else
			{
				while(clock!=p[i].arrivalTime)
				{
					cout<<".";
					clock++;
				}

				fout<<clock<<" ";
				startTime=clock;

				cout<<"(P"<<p[i].pNum<<")"<<clock;
				for(int j=0;j<p[i].cpuBurst;j++)
				{
					cout<<"-";
				}
				clock=clock+p[i].cpuBurst;

				fout<<clock<<" ";
				fout<<startTime-p[i].arrivalTime;
				wtSum=wtSum+ (startTime-p[i].arrivalTime);
			}
			
			fout<<endl;

		}
		
	fout<<wtSum/n;
	cout<<endl;
	fout.close();

}

void priority(Process* p, int n)
{
	ofstream fout;
	fout .open("output.txt");

	sortWithPriority(p, n);

	int clock=0, startTime=0;
	float wtSum=0;

	for(int i=0;i<n;i++)
		{
			if(clock>=p[i].arrivalTime)
			{
				fout<<clock<<" ";
				startTime=clock;

				cout<<"(P"<<p[i].pNum<<")"<<clock;
				for(int j=0;j<p[i].cpuBurst;j++)
				{
					cout<<"-";
				}
				clock=clock+p[i].cpuBurst;
				
				fout<<clock<<" ";
				fout<<startTime-p[i].arrivalTime;
				wtSum=wtSum+ (startTime-p[i].arrivalTime);
			}
			else
			{
				while(clock!=p[i].arrivalTime)
				{
					cout<<".";
					clock++;
				}

				fout<<clock<<" ";
				startTime=clock;

				cout<<"(P"<<p[i].pNum<<")"<<clock;
				for(int j=0;j<p[i].cpuBurst;j++)
				{
					cout<<"-";
				}
				clock=clock+p[i].cpuBurst;

				fout<<clock<<" ";
				fout<<startTime-p[i].arrivalTime;
				wtSum=wtSum+ (startTime-p[i].arrivalTime);
			}
			
			fout<<endl;

		}
		
	fout<<wtSum/n;
	cout<<endl;
	fout.close();
}

void shortestJob(Process* p, int n)
{
	ofstream fout;
	fout .open("output.txt");

	sortWithJob(p, n);

	int clock=0, startTime=0;
	float wtSum=0;

	for(int i=0;i<n;i++)
		{
			if(clock>=p[i].arrivalTime)
			{
				fout<<clock<<" ";
				startTime=clock;

				cout<<"(P"<<p[i].pNum<<")"<<clock;
				for(int j=0;j<p[i].cpuBurst;j++)
				{
					cout<<"-";
				}
				clock=clock+p[i].cpuBurst;
				
				fout<<clock<<" ";
				fout<<startTime-p[i].arrivalTime;
				wtSum=wtSum+ (startTime-p[i].arrivalTime);
			}
			else
			{
				while(clock!=p[i].arrivalTime)
				{
					cout<<".";
					clock++;
				}

				fout<<clock<<" ";
				startTime=clock;

				cout<<"(P"<<p[i].pNum<<")"<<clock;
				for(int j=0;j<p[i].cpuBurst;j++)
				{
					cout<<"-";
				}
				clock=clock+p[i].cpuBurst;

				fout<<clock<<" ";
				fout<<startTime-p[i].arrivalTime;
				wtSum=wtSum+ (startTime-p[i].arrivalTime);
			}
			
			fout<<endl;

		}
		
	fout<<wtSum/n;
	cout<<endl;
	fout.close();



}


int main()
{
	ifstream fin("input.txt");
	if(!fin)
	{
		cout<<"ERROR!!! File not found"<<endl;
	}
	else
	{
		int numOfProcess;
		fin>>numOfProcess;

		Process * p=new Process[numOfProcess];

		for(int i=0;i<numOfProcess;i++)
		{
			fin>>p[i].arrivalTime;
			fin>>p[i].cpuBurst;
			fin>>p[i].priority;
			p[i].pNum=i+1;

		}

		int choice=0;
		cout<<"-------------------------------SCHEDULER-------------------------------"<<endl;
		cout<<"1: First Come First Serve"<<endl;
		cout<<"2: Priority"<<endl;
		cout<<"3: Shortest Job first"<<endl;
		cout<<"4: Exit"<<endl;

		while(choice!=4)
		{
			cout<<"Enter choice: ";
			cin>>choice;
			while(choice<1 || choice>4)
			{
				cout<<"Invalid choice. Enter again: ";
				cin>>choice;
			}

			if(choice==1)
			{
				FCFS(p, numOfProcess);
			}
			else if(choice==2)
			{
				priority(p, numOfProcess);
			}
			else if(choice==3)
			{
				shortestJob(p, numOfProcess);
			}

		}

	fin.close();

	}

}