#include "Connect4Game.h"
#include<iostream>
#include<cstdlib> //for srand function for random numbers.
#include<ctime> //for time function

using namespace std;


Connect4Game::Connect4Game()
{
	table=new int*[7];
	for(int i=0;i<7;i++)
	{
		table[i]=new int[7];
	}

	for(int r=0;r<7;r++)
	{
		for(int c=0;c<7;c++)
		{
			table[r][c]=0;
		}
	}

	unsigned seed=time(0);

	srand(seed);

	turn=rand()%2+1;

}


void Connect4Game::showBoard()
{
	for(int r=0;r<7;r++)
	{
		for(int c=0;c<7;c++)
		{
			cout<<table[r][c]<<"  ";
		}

		cout<<endl<<endl;

	}

}

void Connect4Game::switchTurn()
{
	turn=3-turn;
}

void Connect4Game::setSlot(int&r, int c)
{
	
	while(table[r][c]!=0)
	{
		if(r>0)
		{
			r--;
		}
		else
		{
			r--;
			break;
		}
					
	}
	
	if(r>=0)
	{
		table[r][c]=turn;
	}	
	
}

bool Connect4Game::isWon(int r, int c)
{
	int count=0,count4=0;
	int rowChk=r, colChk=c;

	//Horizontal
	while(colChk<=6)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			colChk++;
			count4++;
		}
		else
		{
			break;
		}
	}
	colChk=c;
	while(colChk>=0)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			colChk--;
			count4++;
		}
		else
		{
			break;
		}
	}
	
	count4--;

	if(count4==4)
	{
		return 1;
	}

	//Vertical downward
	colChk=c, count4=0;
	for(count=0;count<4;count++)
	{
		if(rowChk<=6)
		{
			if(table[r][c]==table[rowChk][colChk])
			{
				rowChk++;
				count4++;
			}
			else
			{
				break;
			}

		}
		else 
			break;
		
	}
	if(count4==4)
	{
		return 1;
	}
	

	//Diogonal right downward & left upward
	rowChk=r, count4=0;

	while(rowChk<=6 && colChk<=6)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk++;
			colChk++;
			count4++;
		}
		else
		{
			break;
		}

	}
	rowChk=r, colChk=c;
	while(rowChk>=0 && colChk>=0)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk--;
			colChk--;
			count4++;
		}
		else
		{
			break;
		}

	}
	
	count4--;

	if(count4==4)
	{
		return 1;
	}

	//Diogonal left downward and right upward 
	rowChk=r, colChk=c, count4=0;
	
	while(rowChk<=6 && colChk>=0)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk++;
			colChk--;
			count4++;
		}
		else
		{
			break;
		}

	}
	rowChk=r, colChk=c;
	while(rowChk>=0 && colChk<=6)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk--;
			colChk++;
			count4++;
		}
		else
		{
			break;
		}
	
	}

	count4--;

	//Final return
	if(count4==4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	

}

bool Connect4Game::isBoardFull()
{
	for(int r=0;r<7;r++)
	{
		for(int c=0;c<7;c++)
		{
			if(table[r][c]==0)
			{
				return 0;
			}
		}
	}

	return 1;

}

void Connect4Game::startGame()
{
	while(1)
	{
		int row=6,col=0,colChk=0;
		cout<<"Player "<<turn<<"'s turn: ";
		cin>>col;
		while(col<0 || col>6)
		{
			cout<<"Invalid entry. Player "<<turn<<"'s turn: ";
			cin>>col;
		}

		setSlot(row,col);

		if(row<0)
		{
			row=6, colChk=col;
			cout<<"Invalid entry. "<<"Player "<<turn<<"'s turn: ";
			cin>>col;
			while(col<0 || col>6 || col==colChk)
			{
				cout<<"Invalid entry. Player "<<turn<<"'s turn: ";
				cin>>col;
			}

			setSlot(row,col);

		}

		cout<<endl;
		showBoard();
		
		if(isWon(row,col))
		{
			cout<<"Player "<<turn<<" Won. CONGRATULATIONS!!! :)"<<endl<<endl;
			break;
		}
		if(isBoardFull())
		{
			cout<<"Its a DRAW!!!"<<endl;
			break;
		}

		switchTurn();

	}


}

Connect4Game::~Connect4Game()
{
	for(int i=0;i<7;i++)
	{
		delete [] table[i];
		table[i]=0;
	}

	delete [] table;
	table=0;

}
