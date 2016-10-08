#include "Tictactoe.h"
#include<iostream>
#include<cstdlib> //for srand function for random numbers.
#include<ctime>//for time function
#include<iomanip>
#include <windows.h>

using namespace std;


Tictactoe::Tictactoe()
{
	table=new int*[3];
	for(int i=0;i<3;i++)
	{
		table[i]=new int[3];
	}

	for(int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			table[r][c]=0;
		}
	}

	Win w1;
	w1.p1.x=0; w1.p1.y=0;
	w1.p2.x=0; w1.p2.y=1;
	w1.p3.x=0; w1.p3.y=2;

	Win w2;
	w2.p1.x=1; w2.p1.y=0;
	w2.p2.x=1; w2.p2.y=1;
	w2.p3.x=1; w2.p3.y=2;

	Win w3;
	w3.p1.x=2; w3.p1.y=0;
	w3.p2.x=2; w3.p2.y=1;
	w3.p3.x=2; w3.p3.y=2;

	Win w4;
	w4.p1.x=0; w4.p1.y=0;
	w4.p2.x=1; w4.p2.y=0;
	w4.p3.x=2; w4.p3.y=0;

	Win w5;
	w5.p1.x=0; w5.p1.y=1;
	w5.p2.x=1; w5.p2.y=1;
	w5.p3.x=2; w5.p3.y=1;

	Win w6;
	w6.p1.x=0; w6.p1.y=2;
	w6.p2.x=1; w6.p2.y=2;
	w6.p3.x=2; w6.p3.y=2;

	Win w7;
	w7.p1.x=0; w7.p1.y=0;
	w7.p2.x=1; w7.p2.y=1;
	w7.p3.x=2; w7.p3.y=2;

	Win w8;
	w8.p1.x=0; w8.p1.y=2;
	w8.p2.x=1; w8.p2.y=1;
	w8.p3.x=2; w8.p3.y=0;


	winArray=new Win [8];
	winArray[0]=w1; winArray[1]=w2; winArray[2]=w3; winArray[3]=w4; winArray[4]=w5;
	winArray[5]=w6; winArray[6]=w7; winArray[7]=w8;

	unsigned seed=time(0);
	srand(seed);
	turn=rand()%2+1;

}


void Tictactoe::showBoard()
{
	int i=1;
	for(int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			if(table[r][c]==0)
			{
				cout<<setw(13)<<"Box"<<i<<"  ";
			}
			else if(table[r][c]==1)
			{
				cout<<setw(12)<<"C"<<"    ";
			}
			else if(table[r][c]==2)
			{
				cout<<setw(12)<<"Y"<<"    ";
			}
			i++;

		}

		cout<<endl<<endl;

	}

}

bool Tictactoe::freeSlotCheck(int box)
{
	if(box==1)
	{
		if(table[0][0]!=0)
			return true;
	}
	else if(box==2)
	{
		if(table[0][1]!=0)
			return true;
	}
	else if(box==3)
	{
		if(table[0][2]!=0)
			return true;
	}
	else if(box==4)
	{
		if(table[1][0]!=0)
			return true;
	}
	else if(box==5)
	{
		if(table[1][1]!=0)
			return true;
	}
	else if(box==6)
	{
		if(table[1][2]!=0)
			return true;
	}
	else if(box==7)
	{
		if(table[2][0]!=0)
			return true;
	}
	else if(box==8)
	{
		if(table[2][1]!=0)
			return true;
	}
	else if(box==9)
	{
		if(table[2][2]!=0)
			return true;
	}

	return false;

}

void Tictactoe::switchTurn()
{
	turn=3-turn;
}

void Tictactoe::setSlot(int r, int c)
{
	
	table[r][c]=turn;		
	
}

bool Tictactoe::isWon(int r, int c)
{
	int slotValue=table[r][c];

	//Horizontal Rows Check
	if(slotValue==table[0][0] && slotValue==table[0][1] && slotValue==table[0][2])
	{
		return true;
	}
	else if(slotValue==table[1][0] && slotValue==table[1][1] && slotValue==table[1][2])
	{
		return true;
	}
	else if(slotValue==table[2][0] && slotValue==table[2][1] && slotValue==table[2][2])
	{
		return true;
	}

	//Vertical Columns Check
	else if(slotValue==table[0][0] && slotValue==table[1][0] && slotValue==table[2][0])
	{
		return true;
	}
	else if(slotValue==table[0][1] && slotValue==table[1][1] && slotValue==table[2][1])
	{
		return true;
	}
	else if(slotValue==table[0][2] && slotValue==table[1][2] && slotValue==table[2][2])
	{
		return true;
	}

	//Diagonals Check
	else if(slotValue==table[0][0] && slotValue==table[1][1] && slotValue==table[2][2])
	{
		return true;
	}
	else if(slotValue==table[0][2] && slotValue==table[1][1] && slotValue==table[2][0])
	{
		return true;
	}


	else
	{
		return false;
	}


}

bool Tictactoe::isBoardFull()
{
	for(int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			if(table[r][c]==0)
			{
				return 0;
			}
		}
	}

	return 1;

}

int Tictactoe::checkUserWin()
{
	int countUser=0, countComp=0;
	for(int i=0;i<8;i++)
	{
		if(table[winArray[i].p1.x][winArray[i].p1.y]==2)
		{
			countUser++;
		}
		else if(table[winArray[i].p1.x][winArray[i].p1.y]==1)
		{
			countComp++;
		}

		if(table[winArray[i].p2.x][winArray[i].p2.y]==2)
		{
			countUser++;
		}
		else if(table[winArray[i].p2.x][winArray[i].p2.y]==1)
		{
			countComp++;
		}

		if(table[winArray[i].p3.x][winArray[i].p3.y]==2)
		{
			countUser++;
		}
		else if(table[winArray[i].p3.x][winArray[i].p3.y]==1)
		{
			countComp++;
		}

		if(countUser==2 && countComp==0)
		{
			return i;
		}

		countUser=0; countComp=0;
	}

	return -1;

}

int Tictactoe::computerMove()
{
	int count=0, countMax=0, countFree=0, maxIndex=-1;
	for(int i=0;i<8;i++)
	{
		if(table[winArray[i].p1.x][winArray[i].p1.y]==1)
		{
			count++;
		}
		else if(table[winArray[i].p1.x][winArray[i].p1.y]==0)
		{
			countFree++;
		}

		if(table[winArray[i].p2.x][winArray[i].p2.y]==1)
		{
			count++;
		}
		else if(table[winArray[i].p2.x][winArray[i].p2.y]==0)
		{
			countFree++;
		}

		if(table[winArray[i].p3.x][winArray[i].p3.y]==1)
		{
			count++;
		}
		else if(table[winArray[i].p3.x][winArray[i].p3.y]==0)
		{
			countFree++;
		}


		if(count>countMax && countFree>0)
		{
			countMax=count;
			maxIndex=i;
		}

		count=0;
		countFree=0;
	}

	return maxIndex;

}

int Tictactoe::checkComputerWin()
{
	int countUser=0, countComp=0;
	for(int i=0;i<8;i++)
	{
		if(table[winArray[i].p1.x][winArray[i].p1.y]==2)
		{
			countUser++;
		}
		else if(table[winArray[i].p1.x][winArray[i].p1.y]==1)
		{
			countComp++;
		}

		if(table[winArray[i].p2.x][winArray[i].p2.y]==2)
		{
			countUser++;
		}
		else if(table[winArray[i].p2.x][winArray[i].p2.y]==1)
		{
			countComp++;
		}

		if(table[winArray[i].p3.x][winArray[i].p3.y]==2)
		{
			countUser++;
		}
		else if(table[winArray[i].p3.x][winArray[i].p3.y]==1)
		{
			countComp++;
		}

		if(countUser==0 && countComp==2)
		{
			return i;
		}

		countUser=0; countComp=0;
	}

	return -1;

}


void Tictactoe::computersTurn(int& row, int& col)
{
	bool canPlay=true;
	if(table[1][1]==0)
	{
		table[1][1]=1;
		canPlay=false;
		row=1; col=1;
	}
	else if(table[0][2]==0)
	{
		table[0][2]=1;
		canPlay=false;
		row=0; col=2;
	}

	int play=checkComputerWin();
	if(play!=-1 && canPlay)
	{
		if(table[winArray[play].p1.x][winArray[play].p1.y]==0)
		{
			table[winArray[play].p1.x][winArray[play].p1.y]=1;
			row=winArray[play].p1.x; col=winArray[play].p1.y;
		}
		else if(table[winArray[play].p2.x][winArray[play].p2.y]==0)
		{
			table[winArray[play].p2.x][winArray[play].p2.y]=1;
			row=winArray[play].p2.x; col=winArray[play].p2.y;
		}
		else if(table[winArray[play].p3.x][winArray[play].p3.y]==0)
		{
			table[winArray[play].p3.x][winArray[play].p3.y]=1;
			row=winArray[play].p3.x; col=winArray[play].p3.y;
		}
		canPlay=false;
		

	}

	play=checkUserWin();
	if(play!=-1 && canPlay)
	{
		if(table[winArray[play].p1.x][winArray[play].p1.y]==0)
		{
			table[winArray[play].p1.x][winArray[play].p1.y]=1;
			row=winArray[play].p1.x; col=winArray[play].p1.y;
		}
		else if(table[winArray[play].p2.x][winArray[play].p2.y]==0)
		{
			table[winArray[play].p2.x][winArray[play].p2.y]=1;
			row=winArray[play].p2.x; col=winArray[play].p2.y;
		}
		else if(table[winArray[play].p3.x][winArray[play].p3.y]==0)
		{
			table[winArray[play].p3.x][winArray[play].p3.y]=1;
			row=winArray[play].p3.x; col=winArray[play].p3.y;
		}
		canPlay=false;

	}
	else if(canPlay)
	{
		play=computerMove();

		if(table[winArray[play].p1.x][winArray[play].p1.y]==0)
		{
			table[winArray[play].p1.x][winArray[play].p1.y]=1;
			row=winArray[play].p1.x; col=winArray[play].p1.y;
		}
		else if(table[winArray[play].p2.x][winArray[play].p2.y]==0)
		{
			table[winArray[play].p2.x][winArray[play].p2.y]=1;
			row=winArray[play].p2.x; col=winArray[play].p2.y;
		}
		else if(table[winArray[play].p3.x][winArray[play].p3.y]==0)
		{
			table[winArray[play].p3.x][winArray[play].p3.y]=1;
			row=winArray[play].p3.x; col=winArray[play].p3.y;
		}

	}

	
}

void Tictactoe::startGame()
{
	showBoard();
	while(1)
	{
		int box=0, row=0, col=0;

		if(turn==1)
		{
			computersTurn(row, col);
			cout<<"Computers Turn ...";
			Sleep(1500);
		}
		else
		{
			cout<<"Yours Turn: ";
			cin>>box;
			while(box<1 || box>9 || freeSlotCheck(box))
			{
				cout<<"Invalid Turn. Turn Again: ";
				cin>>box;
			}
			switch(box)
			{
				case 1:
					row=0, col=0;
					setSlot(row,col);
					break;

				case 2:
					row=0, col=1;
					setSlot(row,col);
					break;

				case 3:
					row=0, col=2;
					setSlot(row,col);
					break;

				case 4:
					row=1, col=0;
					setSlot(row,col);
					break;

				case 5:
					row=1, col=1;
					setSlot(row,col);
					break;

				case 6:
					row=1, col=2;
					setSlot(row,col);
					break;

				case 7:
					row=2, col=0;
					setSlot(row,col);
					break;

				case 8:
					row=2, col=1;
					setSlot(row,col);
					break;
				case 9:
					row=2, col=2;
					setSlot(row,col);
					break;
			}

			
		}
		
		system("CLS");
		showBoard();

		if(isWon(row,col))
		{
			if(turn==2)
			{
				cout<<"You Won. CONGRATULATIONS!!! :)"<<endl<<endl;
				break;
			}
			else
			{
				char smiley=1;
				cout<<"Computer Won. Better Luck Next Time!!!"<<smiley<<endl<<endl;
				break;
			}
		}
		if(isBoardFull())
		{
			cout<<"Its a DRAW!!!"<<endl;
			break;
		}

		switchTurn();

	}


}

Tictactoe::~Tictactoe()
{
	for(int i=0;i<3;i++)
	{
		delete [] table[i];
		table[i]=0;
	}

	delete [] table;
	table=0;

	delete [] winArray;
	winArray=0;

}
