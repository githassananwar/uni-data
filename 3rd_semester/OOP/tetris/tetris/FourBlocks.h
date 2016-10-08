#ifndef FOURBLOCKS_H
#define FOURBLOCKS_H

#include "Pt.h"

struct FourBlocks
{
	Pt blockPts[4];
	int maxima;

	FourBlocks(int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0);
	~FourBlocks(void);
};

#endif