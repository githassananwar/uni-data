#ifndef TICTACTOE_H
#define TICTACTOE_H

class Point
{
public:
	int x;
	int y;
};

class Win
{
public:
	Point p1;
	Point p2;
	Point p3;
};

class Tictactoe
{
	int **table;
	int turn;
	Win* winArray;

public:
	Tictactoe();
	void showBoard();
	void switchTurn();
	bool freeSlotCheck(int);
	int checkUserWin();
	int checkComputerWin();
	int computerMove();
	void setSlot(int,int);
	void computersTurn(int&, int&); //returns box number
	bool isWon(int,int);
	bool isBoardFull();
	void startGame();
	~Tictactoe();

};

#endif