#include "StdAfx.h"
#include "FourBlocks.h"

#include "Pt.h"

FourBlocks::FourBlocks(int x0,int y0, int x1, int y1, int x2, int y2, int x3, int y3, int maxima)
{
	blockPts[0].set(x0,y0);
	blockPts[1].set(x1,y1);
	blockPts[2].set(x2,y2);
	blockPts[3].set(x3,y3);
	
	this->maxima=maxima;
}


FourBlocks::~FourBlocks(void)
{
}
