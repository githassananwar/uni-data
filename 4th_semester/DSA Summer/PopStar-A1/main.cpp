#include "Stack.h"
#include "Point.h"
#include "PopStar.h"
#include <iostream>
using namespace std;

int main()
{
	//Declaration of Point and PopStar objects
	Point pt;
	PopStar ps;

	//Display bpard
	ps.display();

	//Start game
	while(!ps.isGameOver())
	{
		cin>>pt; //Input point in (row, column) format

		//Game functions 
		ps.explore(pt);
		ps.calculateScore();
		ps.shiftDown();
		ps.shiftLeft();

		//Clear screen
		system("cls");

		//Display again with changes
		ps.display();

	}

	//On Game over
	system("cls");
	ps.calculateBonus();

	if(ps.isWon())
	{
		cout<<"You Won!!!"<<endl;
		cout<<"Your score: "<<ps.getScore()<<endl;
	}
	else
	{
		cout<<"You Loose!!!"<<endl;
		cout<<"Your score: "<<ps.getScore()<<endl;
	}

	cout<<"Game Over"<<endl<<endl;

	

	return 0;
}