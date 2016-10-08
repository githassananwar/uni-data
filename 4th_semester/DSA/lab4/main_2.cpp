#include "Stacked.h"
#include<iostream>
#include<fstream>
#include <time.h>
using namespace std;

struct Point
{
	int r;
	int c;

	void setPoint(int r,int c)
	{
		this->r=r;
		this->c=c;
	}
};

int main()
{
	
	ifstream fin("data.txt");
	if(!fin)
	{
		cout << "ERROR!!! File can't be created" << endl;
	}
	else
	{
		int order;
		char ch;
		bool firstLoop=1;
		int count=1;

		srand(time(NULL)); // randomize seed
		
		fin>>order;
		if(order<2 || order>200)
		{
			exit(0);
		}

		char ** board=new char* [order];
		while(order!=0)
		{
			if(!firstLoop)		
			{
				for(int i=0;i<order;i++)
				{
					delete [] board[i];
					board[i]=0;
				}
				delete [] board;
				board=0;

				board=new char* [order];

			}
			

			for(int i=0;i<order;i++)
			{
				board[i]=new char [order];
			}

			for(int i=0;i<order;i++)
			{
				for(int j=0;j<order;j++)
				{
					fin>>ch;
					board[i][j]=ch;
				}
			}

			//-----------------------------------GAME CODE-----------------------------------

			//------------------------------Player A case with B------------------------------
		
			bool notFound=1;
			Point pt;

			for(int row=0;row<order && notFound;row++)
			{
				for(int col=0;col<order && notFound ;col++)
				{
					if(board[row][col]=='r')
					{
						pt.setPoint(row,col);
						board[row][col]='r';
						notFound=0;
					}
				}
			}
			
			Stacked<Point> s;
			s.push(pt);
			
			while(!s.isEmpty())
			{
				if((pt.r-1>=0 && pt.c-1>=0 ) && board[pt.r-1][pt.c-1]=='r')
				{
					pt.r=pt.r-1;
					pt.c=pt.c-1;
					board[pt.r][pt.c]='x';
					s.push(pt);
				}
				else if(pt.r-1>=0 && board[pt.r-1][pt.c]=='r')
				{
					pt.r=pt.r-1;
					board[pt.r][pt.c]='x';
					s.push(pt);
				}
				else if(pt.c-1>=0  && board[pt.r][pt.c-1]=='r')
				{
					pt.c=pt.c-1;
					board[pt.r][pt.c]='x';
					s.push(pt);
				}
				else if( pt.c+1<order && board[pt.r][pt.c+1]=='r')
				{
					pt.c=pt.c+1;
					board[pt.r][pt.c]='x';
					s.push(pt);
				}
				else if(pt.r+1<order && board[pt.r+1][pt.c]=='r')
				{
					pt.r=pt.r+1;
					board[pt.r][pt.c]='x';
					s.push(pt);
				}
				else if((pt.r+1<order && pt.c+1<order ) && board[pt.r+1][pt.c+1]=='r')
				{
					pt.r=pt.r+1;
					pt.c=pt.c+1;
					board[pt.r][pt.c]='x';
					s.push(pt);
				}
				else
				{
					pt=s.pop();
				}

				if(pt.r==order-1)
				{
					break;
				}

			}
			
			if(pt.r==order-1)
			{
				cout<<count<<". Player A won!"<<endl;
			}
			else
			{
				cout<<count<<". Player B won!"<<endl;
			}
			
			fin>>order;
		
			if(order==0)
			{
			
			}
			else if (order<2 || order>200)
			{
				exit(0);
			}
			else
			{
				firstLoop=0;
				count++;
			}

		}

		for(int i=0;i<order;i++)
		{
			delete [] board[i];
			board[i]=0;
		}
		delete [] board;
		board=0;

		fin.close();
	}


	return 0;
}