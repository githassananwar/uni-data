#ifndef POPSTAR_H
#define POPSTAR_H

#include "Point.h"
#include "Stack.h"

class PopStar
{
	char** board;
	int size; //board size
	int score;
	int bonusBlocks; //bonusBlocks to calculate score
	int target; //target on which win or loose criteria is decided
	Stack<Point> posStack; //Stack to store explored blocks' location points in board matrix

public:
	PopStar();
	void display();
	void explore(Point);
	void shiftDown();
	void shiftLeft();
	void calculateScore();
	void calculateBonus();
	bool isGameOver();
	bool isSameColor(int, int);
	int getScore();
	bool isWon();

	~PopStar();
};


#endif
