#include "PopStar.h"
#include "Point.h"
#include "Stack.h"
#include <time.h>
#include <iostream>

using namespace std;

//Data member initialization on creation
PopStar::PopStar():size(10),posStack(size*size) //O(N^2)
{ 
	//Random number generation
	unsigned seed=time(0);
	srand(seed);

	//Initializing data members
	score=0;
	target=5000;
	bonusBlocks=0;

	//Allocation of board
	board=new char* [size];
	for(int i=0;i<size;i++)
	{
		board[i]=new char [size];
	}

	int colorCode=0; //representation of color

	//Random assignment of colors to board indexes
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			colorCode=rand()%5+1;
			if(colorCode==1)
			{
				board[i][j]='P';
			}
			else if(colorCode==2)
			{
				board[i][j]='R';
			}
			else if(colorCode==3)
			{
				board[i][j]='G';
			}
			else if(colorCode==4)
			{
				board[i][j]='B';
			}
			else if(colorCode==5)
			{
				board[i][j]='Y';
			}

		}

	}

}

void PopStar :: display() //O(N^2)
{
	bool flag=1;
	cout<<"SCORE: "<<score<<endl;
	cout<<"TARGET: "<<target<<endl<<endl;

	//to diplay column numbers
	for(int i=0;i<size;i++)
	{
		if(flag)
		{
			cout<<"       "<<i+1<<"   ";
			flag=0;
		}
		else
		{
			cout<<i+1<<"   ";
		}
	}

	cout<<endl<<endl;

	//to display Matrix with row number
	for(int i=0;i<size;i++)
	{
		cout<<i+1<<"-";

		//to manage spaces for 10 digit display (2-digit)
		if(i==9)
		{
			cout<<"    ";
		}
		else
		{
			cout<<"     ";
		}

		for(int j=0;j<size;j++)
		{
			//x means empty box
			if(board[i][j]!='x')
			{
				cout<<board[i][j]<<"   ";
			}
			else
			{
				cout<<"    ";
			}
		}
		cout<<endl<<endl;
		flag=0;
	}
	cout<<endl;
}

void PopStar :: explore(Point pt) //O(N^2)
{
	int xi=pt.getX(), yi=pt.getY();
	int x, y;

	//Color of box selected
	char color=board[xi][yi];

	//In case of x. Empty case.
	if(color=='x')
	{
		return; //terminate function
	}

	//Initial block marking
	board[xi][yi]='x';

	//In case of no exploration, unmark initial block
	bool unMark=1;

	Stack<Point> s (size*size);
	s.push(pt);
	posStack.push(pt); //Stores initial position in Position Stack

	while(!s.isEmpty())
	{
		pt=s.stackTop();

		//Getting point at stack top
		x=pt.getX();
		y=pt.getY();

		//Exploration checks
		if(x-1 >=0 && board[x-1][y]==color)
		{
			pt.setPoint(x-1,y);
			board[x-1][y]='x';
			s.push(pt);
			posStack.push(pt);
			unMark=0;
		}
		
		else if(x+1 <size && board[x+1][y]==color)
		{
			pt.setPoint(x+1,y);
			board[x+1][y]='x';
			s.push(pt);
			posStack.push(pt);
			unMark=0;
		}
		
		else if(y-1>=0  && board[x][y-1]==color)
		{
			pt.setPoint(x,y-1);
			board[x][y-1]='x';
			s.push(pt);
			posStack.push(pt);
			unMark=0;
		}
		
		else if(y+1<size && board[x][y+1]==color)
		{
			pt.setPoint(x,y+1);
			board[x][y+1]='x';
			s.push(pt);
			posStack.push(pt);
			unMark=0;
		}
		else
		{
			s.pop(); //In case of no move, pop the location
		}

	}

	//If unMark is still true. No exploration case
	if(unMark)
	{
		board[xi][yi]=color; //restore block color
		posStack.pop(); //Pop location from position stack
	}
	
}

void PopStar :: shiftDown() //O(N^2)
{
	Point p;
	int x, y;

	while(!posStack.isEmpty())
	{
		p=posStack.pop();
		x=p.getX();
		y=p.getY();
		bool flag=0;

		//Block shifting from bottom
		for(int i=size-1 ;i>0 ;i--)
		{
			//If block is empty flag=1
			if(board[i][y]=='x')
			{
				flag=1;
			}

			//Shift locations from that point(from bottom)
			if(flag)
			{
				board[i][y]=board[i-1][y];
				board[i-1][y]='x';
			}
		}

	}

}

void PopStar :: shiftLeft() //O(N^2)
{
	bool flag=0;
	int col=-1, shiftCount=1;

	for(int index=0;index<size;index++)
	{
		//to find first column having x(no element) in last row .i.e zero column
		if(board[size-1][index]=='x')
		{
			col=index;

			//Next column
			shiftCount=col+1;

			//to find next non-zero column to be shifted
			while(shiftCount<size && board[size-1][shiftCount]=='x')
			{
				shiftCount++;
			}

			//In case it is not last column then shift
			if(!(shiftCount==size))
			{
				for(int i=0;i<size;i++)
				{
					board[i][col]=board[i][shiftCount];
					board[i][shiftCount]='x';
				}
			}

		}

	}
	
}

void PopStar :: calculateScore()
{
	int numOfBlocks= posStack.getNumOfElements(); //Get number of blocks explored
	score = score + (numOfBlocks * numOfBlocks * 5); //score formula
}

void PopStar :: calculateBonus()
{
	//Bonus calculation
	int bonus = 2000 - (bonusBlocks *  bonusBlocks * 20);
	if(bonus>=0)
	{
		score = score + bonus;
	}
}

bool PopStar :: isGameOver()
{
	bonusBlocks=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			//Any non-empty block which have same adjacent color block
			if(board[i][j]!='x' && isSameColor(i,j))
			{
				return 0;
			}
			else if(board[i][j]!='x')
			{
				bonusBlocks++; //sum bonusBlocks which don't have same adjacent color block
			}
		}

	}

	//In case of all blocks don't have same adjacent color block, return TRUE
	return 1;

}

bool PopStar :: isSameColor(int r, int c) //if adjacent blocks have same color or not 
{
	//Adjacent same blocks checking
	if(r+1<size && board[r+1][c]==board[r][c])
	{
		return 1;
	}
	else if(r-1>=0 && board[r-1][c]==board[r][c])
	{
		return 1;
	}
	else if(c+1<size && board[r][c+1]==board[r][c])
	{
		return 1;
	}
	else if(c-1>=0 && board[r][c-1]==board[r][c])
	{
		return 1;
	}

	return 0;
	
}


int PopStar :: getScore()
{
	return score;
}


bool PopStar :: isWon()
{
	return (score>=target);
}

PopStar::~PopStar()
{
	for(int i=0;i<size;i++)
	{
		delete [] board[i];
		board[i]=0;
	}
	delete [] board;
	board=0;
}

