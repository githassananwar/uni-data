#ifndef PILEOFCARDS_H
#define PILEOFCARDS_H

#include "PlayingCard.h"
#include "ConsoleFunctions.h"


class PileofCards
{
	PlayingCard *pile;
	int top;
	int size;
	point startPt; 
	point endPt;
public:
	PileofCards (int size=0);
	PlayingCard peek();
	PlayingCard remove();
	void add(PlayingCard, bool=0);
	bool isEmpty();
	bool isFull();
	
	int getTop(); //returns value of top 
	void setStartPt(int=0 , int=0 ); //sets startPt 
	point getStartPt(); //returs startPt 
	void setEndPt(int , int); //sets endPt 
	point getEndPt(); //returs endPt 
	PileofCards& operator=(const PileofCards& poc);
	PlayingCard viewCard(int i);
	void simpleDisplay();
	void cascadingDisplay();

	void setPile(int);
	void setpeekFd();

	~PileofCards();
};

#endif

