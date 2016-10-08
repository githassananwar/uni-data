#include "stdafx.h"
#include "Rectangle.h"


Rect::Rect()
{
	p1.x=600;
	p1.y=300;
	p2.x=700;
	p2.y=350;
}
	
point Rect :: getinitial()
{
	return p1;
}

point Rect :: getfinal()
{
	return p2;
}


void Rect::rotateRight()
{
	
}

Rect::~Rect(void)
{
}
