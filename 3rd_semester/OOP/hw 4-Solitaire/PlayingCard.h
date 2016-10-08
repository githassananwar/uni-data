#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

class PlayingCard
{
	int rank; //integer 1 – 13
	int suit; //integer 0 – 3
	char color; // red or black - b for black , r for red
	bool faceUp; //tells if a card is face up or not
	bool top; //tells if a card is on top of a pile
public:
	static const int diamond;
	static const int heart;
	static const int spade;
	static const int club;

	PlayingCard(int rank=0, int suit=-1, bool=1, bool=1);
	void display(int , int );

	bool isFaceUp(); //retunrs value of faceUp
	void setFaceUp(bool); //sets value of faceUp
	bool isTop(); //retunrs value of top
	void setTop(bool); //sets value of top
	int getSuit(); //getter for suit value
	int getRank(); //getter for rank value
	char getColor(); //getter for color value

	~PlayingCard(void);
};

#endif