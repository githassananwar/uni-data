#include "StdAfx.h"
#include "Square.h"
#include "TetrisPiece.h"


Square::Square()
{
	rotations=1;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,0,1,1,0,1,1,1);
	
	fptr=&state[currentState];

}

void Square :: rotateAntiClock()
{
	if(currentState + 1 == rotations)
	{
		currentState = 0 ;
	}
	else
	{
		currentState++ ;
	}
	fptr=&state[currentState];
}

int Square:: getstate()
{
	return currentState;
}

Square::~Square()
{
	delete [] state;
	state=0;
}
