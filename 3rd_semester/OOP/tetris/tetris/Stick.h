#ifndef STICK_H
#define STICK_H

#include "TetrisPiece.h"
#include "FourBlocks.h"

class Stick:public TetrisPiece
{
	FourBlocks* state;
public:
	Stick();
	void rotateAntiClock();
	int getstate();
	~Stick();
};

#endif