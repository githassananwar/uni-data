#ifndef SQUARE_H
#define SQUARE_H

#include "TetrisPiece.h"
#include "FourBlocks.h"

class Square:public TetrisPiece
{
	FourBlocks* state;
public:
	Square();
	void rotateAntiClock();
	int getstate();
	~Square();
};

#endif