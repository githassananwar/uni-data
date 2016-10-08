#include "Tictactoe.h"
#include<iostream>
#include<cstdlib> //for srand function for random numbers.
#include<ctime>//for time function
#include<iomanip>

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
			else
			{
				cout<<setw(12)<<table[r][c]<<"    ";
			}
			i++;

		}

		cout<<endl<<endl;

	}

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
	int count=0,count3=0;
	int rowChk=r, colChk=c;

	//Horizontal
	while(colChk<=2)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			colChk++;
			count3++;
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
			count3++;
		}
		else
		{
			break;
		}
	}
	
	count3--;

	if(count3==3)
	{
		return 1;
	}

	//Vertical downward
	colChk=c, count3=0;
	for(count=0;count<2;count++)
	{
		if(rowChk<=2)
		{
			if(table[r][c]==table[rowChk][colChk])
			{
				rowChk++;
				count3++;
			}
			else
			{
				break;
			}

		}
		else 
			break;
		
	}
	if(count3==3)
	{
		return 1;
	}
	

	//Diogonal right downward & left upward
	rowChk=r, count3=0;

	while(rowChk<=2 && colChk<=2)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk++;
			colChk++;
			count3++;
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
			count3++;
		}
		else
		{
			break;
		}

	}
	
	count3--;

	if(count3==3)
	{
		return 1;
	}

	//Diogonal left downward and right upward 
	rowChk=r, colChk=c, count3=0;
	
	while(rowChk<=2 && colChk>=0)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk++;
			colChk--;
			count3++;
		}
		else
		{
			break;
		}

	}
	rowChk=r, colChk=c;
	while(rowChk>=0 && colChk<=2)
	{
		if(table[r][c]==table[rowChk][colChk])
		{
			rowChk--;
			colChk++;
			count3++;
		}
		else
		{
			break;
		}
	
	}

	count3--;

	//Final return
	if(count3==3)
	{
		return 1;
	}
	else
	{
		return 0;
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

void Tictactoe::startGame()
{
	showBoard();
	while(1)
	{
		int box=0, row=0, col=0;

		cout<<"Player "<<turn<<"'s turn: ";
		cin>>box;
		while(box<1 || box>9)
		{
			cout<<"Invalid entry. Player "<<turn<<"'s turn: ";
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

Tictactoe::~Tictactoe()
{
	for(int i=0;i<3;i++)
	{
		delete [] table[i];
		table[i]=0;
	}

	delete [] table;
	table=0;

}
