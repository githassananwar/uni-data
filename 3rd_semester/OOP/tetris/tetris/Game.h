#ifndef GAME_H
#define GAME_H

#include "TetrisPiece.h"

const int BLOCK_HEIGHT = 30;
const int BLOCK_WIDTH = 30;
const COLORREF colorArray[5]={RGB(255,255,255), RGB( 0,255,0), RGB(255,  0,  0), RGB(255,255, 64), RGB(  0,  0,255)};

class Game
{
private:
	int** board;
	int rows, cols;
	TetrisPiece* piecePtr;
	int currentRow;
	int currentCol;
	int pieceCount;

public:
	Game();
	void selectNextPiece();
	void rotatePiece();
	void clearCompleteRows();
	COLORREF getCellColor(int col, int row); //returns color of cell(c,r)
	void setCellColor(int c, int r, int val); //set index value of color at cell(c,r)
	int getrow();
	int getcol();
	int getCurrentCol();
	int getCurrentRow();

	void setCurrentCol(int);
	void setCurrentRow(int);

	int getcolor();
	TetrisPiece* getPtr();
	int getstate();
	bool isGameOver();

	void updateCrow(int);
	void updateCcol(int);

	~Game();
};

#endif