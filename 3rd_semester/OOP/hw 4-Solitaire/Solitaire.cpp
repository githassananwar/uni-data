#include "Solitaire.h"

#include "Deck.h"
#include "PileofCards.h"
#include "ConsoleFunctions.h"

#include <iostream>
using namespace std;


Solitaire::Solitaire()
{
	stock.setPile(52);
	stock.setStartPt(1,1);

	waste.setPile(52);
	waste.setStartPt(9,1);

	int x=23, y=1;

	for(int i=0;i<4;i++)
	{
		home[i].setPile(13);
		home[i].setStartPt(x,y);
		x=x+8;
	}

	x=1, y=16;
	for(int i=0;i<7;i++)
	{
		playingPile[i].setPile(13+(i+1));
		playingPile[i].setStartPt(x,y);
		x=x+8;
	}

}

void Solitaire::shuffle()
{ 
	int i; 
	while (!deckofCards.isEmpty()) 
	{
		i = rand()%deckofCards.getSize(); 
		PlayingCard c = deckofCards.remove(i);  
		stock.add(c);
	}

}

void Solitaire::dealToPlayingPiles()
{
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			playingPile[i].add(stock.remove()); 
			stock.setpeekFd();
		}
	}

}

void Solitaire :: displayGame()
{
	stock.simpleDisplay();
	waste.simpleDisplay();

	for(int i=0;i<4;i++) //4
	{
		home[i].simpleDisplay();
	}

	for(int i=0;i<7;i++) //7
	{
		playingPile[i].cascadingDisplay();
	}


}

point Solitaire :: getClickedPoint()
{
	point pr;
	pr.x=0;
	pr.y=0;

	while(1)
	{
		cf.DetectEvent();
		if(cf.IsMouseLeftClickEvent(pr))
		{
			return pr;
		}
	}

}


PileofCards* Solitaire :: getClickedPile(point p, int& a, int& c)
{
	PileofCards pdef(0);
	PileofCards* pr=&pdef;

	if( (p.x>=stock.getStartPt().x && p.y>=stock.getStartPt().y) && (p.x<stock.getEndPt().x && p.y<stock.getEndPt().y) )
	{
		pr=&stock;
		return pr;
	}

	else if( (p.x>=waste.getStartPt().x && p.y>=waste.getStartPt().y) && (p.x<waste.getEndPt().x && p.y<waste.getEndPt().y) )
	{
		pr=&waste;
		return pr;
	}

	else
	{
		for(int i=0;i<4;i++) //4
		{
			if( (p.x>=home[i].getStartPt().x && p.y>=home[i].getStartPt().y) && (p.x<home[i].getEndPt().x && p.y<home[i].getEndPt().y) )
			{
				pr=&home[i];
				a=i;
				return pr;
			}
		
		}

		for(int i=0;i<7;i++) //7
		{
			if( (p.x>=playingPile[i].getStartPt().x && p.y>=playingPile[i].getStartPt().y) && (p.x<playingPile[i].getEndPt().x && p.y<playingPile[i].getEndPt().y) )
			{
				pr=&playingPile[i];
				a=i;

				int count =1;
				bool flag=1;
				int pt_y=playingPile[i].getEndPt().y -1;
				c=playingPile[i].getTop();
				
				while(p.y!=pt_y)
				{
					pt_y--;

					if(count%8==0 && flag)
					{
						c=c-1;
						flag=0;
					}
					else if(count%2==0 && !flag)
					{
						c=c-1;
					}

					count++;
				}
				
				return pr;
			}

		}

	}

	return pr;

}


void Solitaire :: moveFromStock()
{
	PlayingCard p;
	if(stock.getTop()!=-1)
	{
		p=stock.remove(); 
		stock.setpeekFd();
		waste.add(p);
		cf.SetCursorAt(0,0);

	}	
	else
	{
		while(!waste.isEmpty())
		{
			p=waste.remove();
			stock.add(p);
		}
		stock.setpeekFd();
	}

}

void Solitaire :: moveFromWasteToHome(int a)
{
	if(waste.peek().getRank()==1)
	{
		PlayingCard p;
		p=waste.remove();
		home[a].add(p);
	}
	else if(!home[a].isFull() && waste.peek().getSuit() == home[a].peek().getSuit() && home[a].peek().getRank() == waste.peek().getRank()-1)
	{
		if(!waste.isEmpty())
		{
			PlayingCard p;
			p=waste.remove();
			home[a].add(p);
		}	
		
	}
	else
	{
		cf.SetCursorAt(0,0);
		cout<<"Invalid move !!!";
		Sleep(400);
	}


}
void Solitaire :: moveFromWasteToPlayingPile(int a, int c)
{
	if(!waste.isEmpty())
	{
		if(!playingPile[a].isEmpty())
		{
			if( waste.peek().getColor() != playingPile[a].peek().getColor() && waste.peek().getRank() == playingPile[a].peek().getRank()-1 )
			{

				if(c==playingPile[a].getTop())
				{
					PlayingCard p;
					p=waste.remove();
					playingPile[a].add(p,1);
				}
			
			}
			else if(c==playingPile[a].getTop())
			{
				cf.SetCursorAt(0,0);
				cout<<"Invalid move !!!";
				Sleep(400);
			}
		}
		else
		{
			if( waste.peek().getRank() == 13 )
			{
				if(c==playingPile[a].getTop())
				{
					PlayingCard p;
					p=waste.remove();
					playingPile[a].add(p,1);
				}

			}
			else
			{
				cf.SetCursorAt(0,0);
				cout<<"Invalid move !!!";
				Sleep(400);
			}

		}

	}
	

}

void Solitaire :: moveFromPlayingPileToHome(int a, int a2, int c)
{
	if(!playingPile[a].isEmpty())
	{
		if(home[a2].isEmpty() && playingPile[a].peek().getRank()==1)
	    {
			if(c==playingPile[a].getTop())
			{
				PlayingCard p;
				p=playingPile[a].remove();
				home[a2].add(p);
			}
		}

		else if(!home[a2].isFull() && home[a2].peek().getSuit() == playingPile[a].peek().getSuit() && home[a2].peek().getRank() == playingPile[a].peek().getRank()-1 )
		{
			if(c==playingPile[a].getTop())
			{
				PlayingCard p;
				p=playingPile[a].remove();
				home[a2].add(p);
			}
		}

		else
		{
			cf.SetCursorAt(0,0);
			cout<<"Invalid move !!!";
			Sleep(400);
		}

	}
}

void Solitaire :: moveFromPlayingPileToPlayingPile(int a, int a2, int c, int c2)
{
	if(!playingPile[a].isEmpty())
	{
		if(!playingPile[a2].isEmpty())
		{
			if(c2==playingPile[a2].getTop() &&  playingPile[a].viewCard(c).getColor() != playingPile[a2].viewCard(c2).getColor() && playingPile[a].viewCard(c).getRank() == playingPile[a2].viewCard(c2).getRank()-1 )
			{
				if(playingPile[a].viewCard(c).isFaceUp())
				{
					int count=1, ind=c;
					while(ind!=playingPile[a].getTop()) //Stack handling
					{
						count++;
						ind++;
					}
					
					if(count>1)
					{
						PlayingCard* p=new PlayingCard [count];
						for(int i=0;i<count;i++)
						{
							p[i]=playingPile[a].remove();
						}
						
						for(int i=count-1;i>=0;i--)
						{
							playingPile[a2].add(p[i],1);
						}
				
						delete [] p;
						p=0;
						
					}
					else
					{
						PlayingCard pc;
						pc=playingPile[a].remove();
						playingPile[a2].add(pc,1);
					}
					
				}	
			}
			else
			{
				cf.SetCursorAt(0,0);
				cout<<"Invalid move !!!";
				Sleep(400);
			}
		}
		else
		{
			if( playingPile[a].viewCard(c).getRank() == 13 )
			{
				if(playingPile[a].viewCard(c).isFaceUp())
				{
					int count=1, ind=c;
					while(ind!=playingPile[a].getTop())
					{
						count++;
						ind++;
					}
					
					if(count>1)
					{
						PlayingCard* p=new PlayingCard [count];
						for(int i=0;i<count;i++)
						{
							p[i]=playingPile[a].remove();
						}
						
						for(int i=count-1;i>=0;i--)
						{
							playingPile[a2].add(p[i],1);
						}
				
						delete [] p;
						p=0;
						
					}
					else
					{
						PlayingCard pc;
						pc=playingPile[a].remove();
						playingPile[a2].add(pc,1);
					}
					
				}

			}
			else
			{
				cf.SetCursorAt(0,0);
				cout<<"Invalid move !!!";
				Sleep(400);
			}

		}

	}


}

void Solitaire :: moveFromHomeToPlayingPile(int a, int a2, int c)
{
	if(!home[a].isEmpty())
	{
		if(!playingPile[a2].isEmpty())
		{
			if( home[a].peek().getColor() != playingPile[a2].peek().getColor() && home[a].peek().getRank() == playingPile[a2].peek().getRank()-1 )
			{

				if(c==playingPile[a2].getTop())
				{
					PlayingCard p;
					p=home[a].remove();
					playingPile[a2].add(p,1);
				}
			
			}
			else if(c==playingPile[a2].getTop())
			{
				cf.SetCursorAt(0,0);
				cout<<"Invalid move !!!";
				Sleep(400);
			}

		}
		//if PlayingPile is empty, there is no need of checking king as home is complete if it has a king at top

	}


}


void Solitaire :: play()
{
	while(1)
	{
		int a=-1, c=-1;
		point pi;
		pi.x=0, pi.y=0;

		pi=getClickedPoint();

		PileofCards* pilePtr=0;
		pilePtr=getClickedPile(pi,a,c);
	
		if(pilePtr==&stock)
		{
			moveFromStock();
		}

		else if(pilePtr==&waste)
		{
		
			pi=getClickedPoint();

			pilePtr=getClickedPile(pi,a,c);

			for(int i=0;i<4;i++)
			{
				if(pilePtr==&home[i])
				{
					moveFromWasteToHome(a);
					break;
				}
			}

			for(int i=0;i<7;i++)
			{
				if(pilePtr==&playingPile[i])
				{
					moveFromWasteToPlayingPile(a,c);
					break;
				}
			}

		}

		else
		{
			//Home to
			bool brk=0;
			for(int i=0;i<4;i++)
			{
				if(pilePtr==&home[i])
				{
					int a2=-1;
					pi=getClickedPoint();	
					pilePtr=getClickedPile(pi,a2,c);

					//2nd click PlayingPile
					for(int j=0;j<7;j++)
					{
						if(pilePtr==&playingPile[j])
						{
							moveFromHomeToPlayingPile(a, a2, c);
							brk=1;
							break;
						}
					}
					if(brk)
					{
						break;
					}

				}

			}
			
			//else Playing Pile to
			if(brk==0) //to avoid inputing a click after execution of home to playingPile loop
			{
				for(int i=0;i<7;i++)
				{
					if(pilePtr==&playingPile[i])
					{
						int a2=-1, c2=-1;
						pi=getClickedPoint();	
						pilePtr=getClickedPile(pi,a2,c2);
					
						//2nd click Home
						for(int j=0;j<4;j++)
						{
							if(pilePtr==&home[j])
							{
								moveFromPlayingPileToHome(a, a2, c);
								brk=1;
								break;
							}
						}

						//2nd click Playing pile
						for(int j=0;j<7;j++)
						{
							if(pilePtr==&playingPile[j])
							{
								moveFromPlayingPileToPlayingPile(a,a2,c,c2);
								brk=1;
								break;
							}
						}
						if(brk)
						{
							break;
						}
			
					}
				
				} //loop end

			} //my else if end

		} //else end

		cf.clearConsole();

		//Won condition
		int wonCount=0;
		for(int i=0;i<4;i++)
		{
			if(home[i].getTop()==12)
			{
				wonCount++;
			}

		
		}
		if(wonCount==4)
		{
			cf.SetColor(15,0);
			cf.SetCursorAt(25,10);
			cout<<"CONGRATULATIONS !!! YOU WON :)"<<endl<<endl<<endl<<endl;
			break;
		}
		else
		{
			displayGame(); 
		}

	}
	
}

Solitaire::~Solitaire(void)
{

}

