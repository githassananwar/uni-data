#ifndef LEFTSTAIR_H
#define LEFTSTAIR_H

#include "Stair.h"
#include "FourBlocks.h"

class LeftStair:public Stair
{
	FourBlocks* state;
public:
	LeftStair();
	void rotateAntiClock();
	int getstate();
	~LeftStair();
};

#endif