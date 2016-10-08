#ifndef RIGHTLSHAPE_H
#define RIGHTLSHAPE_H

#include "Lshape.h"
#include "FourBlocks.h"

class RightLShape:public Lshape
{
	FourBlocks* state;
public:
	RightLShape();
	void rotateAntiClock();
	int getstate();
	~RightLShape();
};

#endif