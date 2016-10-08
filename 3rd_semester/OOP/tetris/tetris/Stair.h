#ifndef STAIR_H
#define STAIR_H

#include "TetrisPiece.h"
#include "FourBlocks.h"

class Stair:public TetrisPiece
{

public:
	Stair();
	void rotateAntiClock();
	~Stair();
};

#endif