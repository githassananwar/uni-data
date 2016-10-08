#ifndef DECK_H
#define DECK_H

#include "PlayingCard.h"

class Deck
{
	PlayingCard *deck[52];
	int size;
public:
	Deck();
	int getSize();
	bool isEmpty();
	void display();
	PlayingCard remove(int i);
	~Deck();
};


#endif
