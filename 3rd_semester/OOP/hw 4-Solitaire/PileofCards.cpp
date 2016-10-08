#include "PileofCards.h"
#include "PlayingCard.h"
#include "ConsoleFunctions.h"

#include <iostream>

using namespace std;


PileofCards::PileofCards(int s)
{
	if(s>0)
	{
		size=s;
		pile=new PlayingCard [size];
		top=-1; //No card placed
		setStartPt();
	}
	else
	{
		size=0;
		pile=0;
		top=-1;
		setStartPt();
	}
}

void PileofCards :: add(PlayingCard c, bool faceup)
{
	if(top<size-1  && pile!=0)
	{
		if(top==-1) //in case of addition of first card 
		{
			pile[++top]=c;
			pile[top].setTop(1);
			pile[top].setFaceUp(1);
		}
		else
		{
			if(faceup)
			{
				pile[top].setTop(0);
				pile[top].setFaceUp(1);
				pile[++top]=c;
				pile[top].setTop(1);
				pile[top].setFaceUp(1);

			}
			else
			{
				pile[top].setTop(0);
				pile[top].setFaceUp(0);
				pile[++top]=c;
				pile[top].setTop(1);
				pile[top].setFaceUp(1);

			}

		}

	}
	else
	{
		cout<<"Pile is already full!!!"<<endl;
	}
}

PlayingCard PileofCards :: remove()
{
	PlayingCard cr;
	if(top>=0 && pile!=0)
	{
		cr=pile[top];
		top=top-1;

		pile[top].setTop(1);
		pile[top].setFaceUp(1);
	
		return cr;
	}
	else
	{
		cout<<endl<<"No card in pile!!!"<<endl;
		return cr;
	}

}

PlayingCard PileofCards::peek()
{
	PlayingCard pr;
	if(top>=0)
	{
		return pile[top];
	}
	else
	{
		cout<<endl<<"No card in pile!!!"<<endl;
		return pr;
	}
}

bool PileofCards :: isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool PileofCards :: isFull()
{
	if(top==size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int PileofCards::getTop()
{
	return top;
}

void PileofCards::setStartPt(int xi, int yi)
{
	this->startPt.x=xi;
	this->startPt.y=yi;
}

point PileofCards::getStartPt()
{
	return this->startPt;
}

void PileofCards::setEndPt(int xi, int yi)
{
	this->endPt.x=xi;
	this->endPt.y=yi;
}

point PileofCards::getEndPt()
{
	return this->endPt;
}

PileofCards& PileofCards:: operator=(const PileofCards& poc)
{
	if(this!=&poc)
	{
		top=poc.top;
		size=poc.size;
	
		if(size>0)
		{
			delete [] pile;
			pile=new PlayingCard [size];
			top=-1; //No card placed

			for(int i=0; i<size && poc.pile[i].getRank()!=0  ;i++)
			{
				this->add(poc.pile[i]);
			}

		}

		
		startPt=poc.startPt; 
		endPt=poc.endPt;

	}
	
	return *this;

}

PlayingCard PileofCards::viewCard(int i)
{
	PlayingCard pr;
	if(top>=0)
	{
		return pile[i];
	}
	else
	{
		cout<<endl<<"No card found!!!"<<endl;
		return pr;
	}
}

void PileofCards::simpleDisplay()
{
	if(top>=0)
	{
		PlayingCard p;
		p=this->peek();
		p.display(startPt.x,startPt.y);
	}
	else
	{
		ConsoleFunctions c;
		c.SetColor(2,2); //2 for green
		int x=startPt.x;
		int y=startPt.y;

		int limR=8+y, limC=6+x;
		int g9=0;
		int row=0, col=0;

		for(row=0+y;row<limR;row++) //prints 8 newlines - along y-axis
		{
			for(col=0+x;col<limC;col++) //prints 6 spaces - along x-axis
			{
				c.SetCursorAt(col,row);
				cout<<" ";
			}

		}

		c.SetColor(7,0);

	}

	this->setEndPt(startPt.x+6,startPt.y+8);


	 /*cout<<"S.p: "<<startPt.x<<" "<<startPt.y<<endl;
	cout<<"E.p: "<<endPt.x<<" "<<endPt.y<<endl<<endl<<endl;*/

}

void PileofCards::cascadingDisplay()
{
	if(top>=0)
	{
		int x=startPt.x;
		int y=startPt.y;
		for(int i=0;i<size && pile[i].getRank()!=0 && i<=top ;i++) //pile[i].getRank()!=0 for cards placed 
		{
			pile[i].display(x,y);
			y=y+2;
		}

		y=y-2;

		this->setEndPt(startPt.x+6, (y+8) );

		 /*cout<<"S.p: "<<startPt.x<<" "<<startPt.y<<endl;
		cout<<"E.p: "<<endPt.x<<" "<<endPt.y<<endl<<endl<<endl;*/

	}

	else
	{
		ConsoleFunctions c;
		c.SetColor(2,2); //2 for green
		int x=startPt.x;
		int y=startPt.y;

		int limR=8+y, limC=6+x;
		int g9=0;
		int row=0, col=0;

		for(row=0+y;row<limR;row++) //prints 8 newlines - along y-axis
		{
			for(col=0+x;col<limC;col++) //prints 6 spaces - along x-axis
			{
				c.SetCursorAt(col,row);
				cout<<" ";
			}

		}

		c.SetColor(7,0);


		this->setEndPt(startPt.x+6,startPt.y+8);

	}

}


void PileofCards :: setPile(int pileSize)
{
	if(pile==0)
	{
		size=pileSize;
		pile=new PlayingCard [size];
	}

}

void PileofCards :: setpeekFd()
{
	pile[top].setFaceUp(0);

}

PileofCards::~PileofCards()
{
	delete [] pile;
	pile=0;
}
