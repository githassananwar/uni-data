#include "StdAfx.h"
#include "Game.h"
#include "TetrisPiece.h"
#include "Tshape.h"
#include "Stick.h"
#include "Square.h"
#include "LeftLShape.h"
#include "LeftStair.h"
#include "RightLShape.h"
#include "RightStair.h"


Game::Game()
{
	rows=20;
	cols=15;
	board=new int * [rows];
	for(int i=0;i<rows;i++)
	{
		board[i]=new int [cols];
	}

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			board[i][j]=0;
		}
		
	}
	currentRow = 0 ;
	currentCol = 6 ;

	piecePtr=new Tshape;
	pieceCount=2;
	
}

int Game :: getrow()
{
	return rows;
}

int Game :: getcol()
{
	return cols;
}

int Game::getCurrentRow()
{
	return currentRow ;
}

int Game::getCurrentCol()
{
	return currentCol;
}

COLORREF Game :: getCellColor(int col, int row) //returns color of cell(c,r)
{
	if(row<0 || row>19 || col<0 || col>14)
	{
		return colorArray[4]; //in case of memory error
	}
	else
	{
		return colorArray[board[row][col]] ;
	}
}

void Game :: setCellColor(int c, int r, int val)
{
	board[r][c]=val;
}

TetrisPiece* Game :: getPtr()
{
	return piecePtr;
}

void Game :: selectNextPiece()
{
	delete piecePtr;

	if(pieceCount==1)
	{
		piecePtr=new Tshape;
		pieceCount++;
	}
	else if(pieceCount==2)
	{
		piecePtr=new Stick;
		pieceCount++;
	}
	else if(pieceCount==3)
	{
		piecePtr=new LeftLShape;
		pieceCount++;
	}
	else if(pieceCount==4)
	{
		piecePtr=new RightLShape;
		pieceCount++;
	}
	else if(pieceCount==5)
	{
		piecePtr=new LeftStair;
		pieceCount++;
	}
	else if(pieceCount==6)
	{
		piecePtr=new RightStair;
		pieceCount++;
	}
	else if(pieceCount==7)
	{
		piecePtr=new Square;
		pieceCount=1;
	}
}
	
void Game :: rotatePiece()
{
	piecePtr->rotateAntiClock();
}

void Game :: clearCompleteRows()
{
	int count=0, col=0;
	for(int i=0;i<rows;i++)
	{
		count=0;
		for(int j=0;j<cols;j++)
		{
			if(board[i][j]==1)
			{
				count++;
			}
			else if(board[i][j]==2)
			{
				count++;
			}
			else if(board[i][j]==3)
			{
				count++;
			}
			else if(board[i][j]==4 )
			{
				count++;
			}
		
		}
		if(count==15)
		{
			for(int r=i;r>0;r--)
			{
				for(int c=0;c<cols;c++)
				{
					board[r][c]=board[r-1][c];
					board[r-1][c]=0;
				}
			}
			
		}
		
	}
}

int Game:: getstate()
{
	return piecePtr->getstate();
}

int Game :: getcolor()
{
	return piecePtr->getcolor();
}

void Game :: updateCrow(int n)
{
	currentRow=currentRow+n;
	
}

void Game :: updateCcol(int n)
{
	currentCol=currentCol+n;
}

void Game :: setCurrentCol(int n)
{
	currentCol=n;
}
	
void Game :: setCurrentRow(int n)
{
	currentRow=n;
}

bool Game :: isGameOver()
{
	int count=0;
	for(int c=0;c<cols;c++)
	{
		if(board[0][c]!=0)
		{
			count++;
		}
	}
	if(count==15 || board[0][6]!=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

Game::~Game()
{
	for(int i=0;i<rows;i++)
	{
		delete [] board[i];
		board[i] = 0 ;
	}
	delete [] board;
	board = 0;
	delete piecePtr;

}
