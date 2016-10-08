#include "StdAfx.h"
#include "Stick.h"

#include "TetrisPiece.h"
#include "FourBlocks.h"

Stick::Stick()
{
	rotations=2;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,1,0,2,0,3,0,0);
	state[1]=FourBlocks(1,-1,1,0,1,1,1,2,2);
	
	fptr=&state[currentState];
}

void Stick :: rotateAntiClock()
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

int Stick:: getstate()
{
	return currentState;
}

Stick::~Stick()
{
	delete [] state;
	state=0;
}
