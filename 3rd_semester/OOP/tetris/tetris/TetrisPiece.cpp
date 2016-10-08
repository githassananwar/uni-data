#include "StdAfx.h"
#include "TetrisPiece.h"

#include "FourBlocks.h"

#include<cstdlib> //for srand function for random numbers.
#include<ctime>//for time function

TetrisPiece::TetrisPiece(void)
{
	unsigned seed=time(0);
	srand(seed);
	colorIndex=rand()%4+1;

	//colorIndex=2;

}

int TetrisPiece::getcolor()
{
	return colorIndex;
}

FourBlocks*  TetrisPiece::getfptr()
{
	return fptr;
}

TetrisPiece::~TetrisPiece(void)
{
}
