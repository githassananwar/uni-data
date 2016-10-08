#ifndef CONNECT4GAME_H
#define CONNECT4GAME_H

class Connect4Game
{
	int **table;
	int turn;

public:
	Connect4Game();
	void showBoard();
	void switchTurn();
	void setSlot(int&,int);
	bool isWon(int,int);
	bool isBoardFull();
	void startGame();
	~Connect4Game();

};

#endif