#include "StdAfx.h"
#include "RightLShape.h"

#include "Lshape.h"
#include "FourBlocks.h"


RightLShape::RightLShape()
{
	rotations=4;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,1,0,2,0,0,1,1);
	state[1]=FourBlocks(1,-1,1,0,1,1,2,1,1);
	state[2]=FourBlocks(2,-1,0,0,1,0,2,0,0);
	state[3]=FourBlocks(0,-1,1,-1,1,0,1,1,1);
	
	fptr=&state[currentState];
}

void RightLShape :: rotateAntiClock()
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

int RightLShape:: getstate()
{
	return currentState;
}

RightLShape::~RightLShape()
{
	delete [] state;
	state=0;
}
