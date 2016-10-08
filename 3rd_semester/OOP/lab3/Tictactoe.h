#ifndef TICTACTOE_H
#define TICTACTOE_H

class Tictactoe
{
	int **table;
	int turn;

public:
	Tictactoe();
	void showBoard();
	void switchTurn();
	void setSlot(int,int);
	bool isWon(int,int);
	bool isBoardFull();
	void startGame();
	~Tictactoe();

};

#endif