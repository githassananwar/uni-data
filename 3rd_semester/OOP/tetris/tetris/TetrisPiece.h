#ifndef TETRISPIECE_H
#define TETRISPIECE_H

#include "FourBlocks.h"


class TetrisPiece
{
protected:
	COLORREF color; //color of the TetrisPiece
	int colorIndex; //index to select value for ‘color’ from global const colorArray[5]
	FourBlocks* fptr; //fptr is a pointer that will be inherited in derived classes of
	//TetrisPiece and will be made to point a fourBlocks structure
	//as will be discussed later.
	int rotations; //total distinct rotations possible for a peice
	int currentState; //current state of the TetrisPiece. It will be used in setting fptr
public:
	TetrisPiece(void);
	virtual void rotateAntiClock()=0;
	FourBlocks* getfptr();
	virtual int getstate()=0;
	int getcolor();
	~TetrisPiece(void);
};

#endif