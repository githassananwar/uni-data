#include "PlayingCard.h"
#include "ConsoleFunctions.h"

#include <iostream>

using namespace std;

const int PlayingCard :: diamond=0;
const int PlayingCard :: heart=1;
const int PlayingCard :: spade=2;
const int PlayingCard :: club=3;


PlayingCard::PlayingCard(int r, int s, bool face, bool t)
{
	if (r>=1 && r<=13)
	{
		rank=r;
	}
	else
	{
		rank=0;
	}

	if(s>=0 && s<=3)
	{
		if(s==0)
		{
			suit=s;
			color='r';
		}
		else if(s==1)
		{
			suit=s;
			color='r';
		}
		else if(s==2)
		{
			suit=s;
			color='b';
		}
		else if(s==3)
		{
			suit=s;
			color='b';
		}
	}
	else
	{
		suit=-1;
	}

	faceUp=face;
	top=t;

}


void PlayingCard :: display(int x , int y)
{
	if(rank==0 || suit==-1)
	{
		cout<<"Not a valid card!!!"<<endl;
	}
	else
	{
		int clr=0;
		char* symbol=0;
		if(color=='r')
		{
			clr=12;
		}
		else if(color=='b')
		{
			clr=0;
		}

		if(suit==0)
		{
			symbol="\x04"; //diomand
		}
		else if(suit==1)
		{
			symbol="\x03"; //heart
		}
		else if(suit==2)
		{
			symbol="\x06"; //spade
		}
		else if(suit==3)
		{
			symbol="\x05"; //club
		}

		ConsoleFunctions c;
		c.SetCursorAt(x,y);

		//1st condition starts
		if(faceUp == 1 && top == 1)
		{
			c.SetColor(clr,15);
			int limR=8+y, limC=6+x;
			int g9=0;

			for(int row=0+y;row<limR;row++) //prints 8 newlines - along y-axis
			{
				for(int col=0+x;col<limC;col++) //prints 6 spaces - along x-axis
				{
					c.SetCursorAt(col,row);
					if(row==0+y && (col==0+x || col==1+x+g9) )
					{
						if(col==0+x)
						{
							if(rank==1)
							{
								cout<<"A";
							}
							else if(rank==10)
							{
								cout<<rank;
								col++;
								g9=1;
							}
							else if(rank==11)
							{
								cout<<"J";
							}
							else if(rank==12)
							{
								cout<<"Q";
							}
							else if(rank==13)
							{
								cout<<"K";
							}
							else
							{
								cout<<rank;
							}

						}
						else if(col==1+x+g9)
						{
							cout<<symbol;
						}
						else
						{
							cout<<" ";
						}
			
					}	
					else if(row==7+y && (col==4+x-g9 || col==5+x-g9) )
					{
			
						if(col==4+x-g9)
						{
							cout<<symbol;
						}
						else if(col==5+x-g9)
						{
							if(rank==1)
							{
								cout<<"A";
							}
							else if(rank==10)
							{
								cout<<rank;
								col++;
							}
							else if(rank==11)
							{
								cout<<"J";
							}
							else if(rank==12)
							{
								cout<<"Q";
							}
							else if(rank==13)
							{
								cout<<"K";
							}
							else
							{
								cout<<rank;
							}
						}
						else
						{
							cout<<" ";
						}
					
					}
					else
					{
						cout<<" "<<endl;
					}
				
				}

			}

			c.SetColor(7,0);
		} //1st condition ends

		else if(faceUp == 0 && top == 1)
		{
			c.SetColor(clr,12); //12 for red
			int limR=8+y, limC=6+x;
			int g9=0;

			for(int row=0+y;row<limR;row++) //prints 8 newlines - along y-axis
			{
				for(int col=0+x;col<limC;col++) //prints 6 spaces - along x-axis
				{
					c.SetCursorAt(col,row);
					cout<<" ";
				}

			}

			c.SetColor(7,0);
		}

		else if(faceUp == 1 && top == 0)
		{
			c.SetColor(clr,15); //12 for red
			int limR=2+y, limC=6+x;
			int g9=0;

			for(int row=0+y;row<limR;row++) //prints 8 newlines - along y-axis
			{
				for(int col=0+x;col<limC;col++) //prints 6 spaces - along x-axis
				{
					c.SetCursorAt(col,row);
					if(row==0+y && (col==0+x || col==1+x+g9) )
					{
						if(col==0+x)
						{
							if(rank==1)
							{
								cout<<"A";
							}
							else if(rank==10)
							{
								cout<<rank;
								col++;
								g9=1;
							}
							else if(rank==11)
							{
								cout<<"J";
							}
							else if(rank==12)
							{
								cout<<"Q";
							}
							else if(rank==13)
							{
								cout<<"K";
							}
							else
							{
								cout<<rank;
							}

						}
						else if(col==1+x+g9)
						{
							cout<<symbol;
						}
						else
						{
							cout<<" ";
						}
		
					}	
					else if(row==1+y)
					{
						c.SetColor(8,15); // 8 for grey
						cout<<"_"<<endl;
					}
					else
					{
						cout<<" ";
					}

				}

			}

			c.SetColor(7,0);
		}

		else if(faceUp == 0 && top == 0)
		{
			c.SetColor(clr,12); //12 for red
			int limR=2+y, limC=6+x;
			int g9=0;

			for(int row=0+y;row<limR;row++) //prints 8 newlines - along y-axis
			{
				for(int col=0+x;col<limC;col++) //prints 6 spaces - along x-axis
				{
					c.SetCursorAt(col,row);
					if(row==1+y)
					{
						c.SetColor(8,12); // 8 for grey
						cout<<"_"<<endl;
					}
					else
					{
						cout<<" ";
					}
				}

			}

			c.SetColor(7,0);
		}



	}

		

}

bool PlayingCard::isFaceUp()
{
	if(faceUp)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void PlayingCard::setFaceUp(bool check)
{
	if(check)
	{
		faceUp=1;
	}
	else
	{
		faceUp=0;
	}

}
bool PlayingCard::isTop()
{
	if(top)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

void PlayingCard::setTop(bool check)
{
	if(check)
	{
		top=1;
	}
	else
	{
		top=0;
	}


}

int PlayingCard :: getSuit()
{
	return suit;
}

int PlayingCard::getRank()
{
	return rank;
}

char PlayingCard::getColor()
{
	return color;
}




PlayingCard::~PlayingCard(void)
{
}
