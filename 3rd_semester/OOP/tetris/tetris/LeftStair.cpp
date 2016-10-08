#include "StdAfx.h"
#include "LeftStair.h"

#include "Stair.h"
#include "FourBlocks.h"

LeftStair::LeftStair(void)
{
	rotations=2;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,1,0,1,1,2,1,1);
	state[1]=FourBlocks(1,-1,0,0,1,0,0,1,1);
	
	fptr=&state[currentState];
}

void LeftStair :: rotateAntiClock()
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

int LeftStair:: getstate()
{
	return currentState;
}


LeftStair::~LeftStair()
{
	delete [] state;
	state=0;
}
