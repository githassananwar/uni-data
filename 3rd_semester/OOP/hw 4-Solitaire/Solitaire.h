#ifndef SOLITAIRE_H
#define SOLITAIRE_H

#include "Deck.h"
#include "PileofCards.h"
#include "ConsoleFunctions.h"

class Solitaire
{
	Deck deckofCards;
	PileofCards stock;
	PileofCards waste;
	PileofCards home[4];
	PileofCards playingPile[7];
	ConsoleFunctions cf;

public:
	Solitaire();
	void shuffle();
	void dealToPlayingPiles();
	void displayGame();

	point getClickedPoint();
	PileofCards* getClickedPile(point p, int& a, int& c);
	void moveFromStock();
	void moveFromWasteToHome(int);
	void moveFromWasteToPlayingPile(int, int);
	void moveFromPlayingPileToHome(int, int, int);
	void moveFromPlayingPileToPlayingPile(int, int, int, int);
	void moveFromHomeToPlayingPile(int, int, int);
	void play();

	~Solitaire();
	
};


#endif