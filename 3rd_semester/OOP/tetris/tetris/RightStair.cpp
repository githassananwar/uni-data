#include "StdAfx.h"
#include "RightStair.h"

#include "Stair.h"
#include "FourBlocks.h"

RightStair::RightStair()
{
	rotations=2;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,1,0,-1,1,0,1,1);
	state[1]=FourBlocks(-1,-1,-1,0,0,0,0,1,1);
	
	fptr=&state[currentState];
}

void RightStair :: rotateAntiClock()
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

int RightStair:: getstate()
{
	return currentState;
}

RightStair::~RightStair()
{
	delete [] state ;
	state=0;
}
