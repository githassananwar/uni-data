#ifndef RIGHTSTAIR_H
#define RIGHTSTAIR_H

#include "Stair.h"
#include "FourBlocks.h"

class RightStair:public Stair
{
	FourBlocks* state;
public:
	RightStair();
	void rotateAntiClock();
	int getstate();
	~RightStair();
};


#endif