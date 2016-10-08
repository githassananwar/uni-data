#include "StdAfx.h"
#include "Tshape.h"

#include "TetrisPiece.h"
#include "FourBlocks.h"

Tshape::Tshape()
{
	rotations=4;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,1,0,2,0,1,1,1);
	state[1]=FourBlocks(1,-1,1,0,2,0,1,1,1);
	state[2]=FourBlocks(1,-1,0,0,1,0,2,0,0);
	state[3]=FourBlocks(1,-1,0,0,1,0,1,1,1);
	
	fptr=&state[currentState];
}

void Tshape :: rotateAntiClock()
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

int Tshape:: getstate()
{
	return currentState;
}

Tshape::~Tshape()
{
	delete [] state;
	state=0;
}
