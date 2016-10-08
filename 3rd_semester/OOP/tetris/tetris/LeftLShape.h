#ifndef LEFTLSHAPE_H
#define LEFTLSHAPE_H

#include "Lshape.h"
#include "FourBlocks.h"

class LeftLShape:public Lshape
{
	FourBlocks* state;
public:
	LeftLShape();
	void rotateAntiClock();
	int getstate();
	~LeftLShape();
};

#endif