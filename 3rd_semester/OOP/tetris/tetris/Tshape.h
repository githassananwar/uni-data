#ifndef TSHAPE_H
#define TSHAPE_H

#include "TetrisPiece.h"
#include "FourBlocks.h"

class Tshape:public TetrisPiece
{
	FourBlocks* state;
public:
	Tshape();
	void rotateAntiClock();
	int getstate();
	~Tshape();
};

#endif