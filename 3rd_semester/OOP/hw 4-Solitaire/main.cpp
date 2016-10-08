#include "ConsoleFunctions.h"
#include "PlayingCard.h"
#include "PileofCards.h"
#include "Deck.h"
#include "Solitaire.h"

#include <iostream>

using namespace std;

int main()
{

	ConsoleFunctions cc;
	cc.setConsoleTitle("Solitaire by Hassan");

	Solitaire S;
	S.shuffle();
	S.dealToPlayingPiles();
	S.displayGame();
	S.play();
	
	cin.get();

	//------------------------------------------------------------------------------------------------

	cout<<endl;
	return 0;
}