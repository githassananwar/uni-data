#include "Deck.h"
#include "PlayingCard.h"

#include <iostream>
using namespace std;


Deck::Deck()
{
	int count=0;
	size=52;
	for (int i = 1; i<= 13; i++)
	{
		deck[count]= new PlayingCard(i,PlayingCard::spade);
		count++;
	}

	for (int i = 1; i<= 13; i++)
	{
		deck[count]= new PlayingCard(i,PlayingCard::heart);
		count++;
	}

	for (int i = 1; i<= 13; i++)
	{
		deck[count]= new PlayingCard(i,PlayingCard::diamond);
		count++;
	}

	for (int i = 1; i<= 13; i++)
	{
		deck[count]= new PlayingCard(i,PlayingCard::club);
		count++;
	}

}

void Deck ::display()
{
	if(size>0)
	{
		int x=0, y=0;
		for(int i=0;i<size;i++)
		{
			deck[i]->display(x,y);
			y=y+10;
		}

	}
	else
	{
		cout<<"Deck is Empty!!!"<<endl;
	}
	
}

PlayingCard Deck :: remove(int ind)
{
	PlayingCard cr;
	if(size>0)
	{
		if(deck[ind]!=0)
		{
			cr=*deck[ind];
			delete deck[ind];
			deck[ind]=0;
			//shifting;
			for(int i=ind;i<size-1;i++)
			{	
				deck[i]=deck[i+1];
			}	
			
			size--;
			return cr;
		}
		else
		{
			cout<<"Card not found!!!"<<endl;
			return cr;
		}
		
		
	}
	else
	{
		cout<<"Deck is Empty!!!"<<endl;
		return cr;
	}
		
}

bool Deck :: isEmpty()
{
	if(size==0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}

}

int Deck :: getSize()
{
	return size;
}

Deck::~Deck()
{
	for(int i=0;i<size;i++)
	{
		delete deck[i];
		deck[i]=0;
	}
}
