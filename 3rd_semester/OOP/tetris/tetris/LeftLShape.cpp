#include "StdAfx.h"
#include "LeftLShape.h"

#include "Lshape.h"
#include "FourBlocks.h"


LeftLShape::LeftLShape()
{
	rotations=4;
	currentState=0;
	state=new FourBlocks[rotations];
	
	state[0]=FourBlocks(0,0,0,1,1,1,2,1,1);
	state[1]=FourBlocks(1,0,1,1,0,2,1,2,2);
	state[2]=FourBlocks(0,1,1,1,2,1,2,2,2);
	state[3]=FourBlocks(1,0,2,0,1,1,1,2,2);
	
	fptr=&state[currentState];
}

void LeftLShape :: rotateAntiClock()
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

int LeftLShape:: getstate()
{
	return 0;
}

LeftLShape::~LeftLShape()
{
	delete [] state;
	state=0;
}
