#include "stdafx.h"
#include "Triangle.h"

int Triangle ::count=1;
Triangle::Triangle()
{
	p1.x=300;
	p1.y=150;
	p2.x=400;
	p2.y=250;
}

point Triangle :: getinitial()
{
	return p1;
}

point Triangle :: getfinal()
{
	return p2;
}

void Triangle :: rotateRight()
{
	int resx=0, resy=0;
	double cal;
	if(count==1)
	{
		resx=abs(p2.x-p1.x)+abs(p2.y-p1.y);
		cal=abs(p2.y-p1.y)*(1.0/5.0);

		resy=(int)cal;

		p2.x=p2.x-resx;
		p2.y=p1.y+ abs(p2.y-p1.y)-resy;

		count++;
	}
	else if(count==2)
	{
		cal=abs(p2.x-p1.x)*(1.0/5.0);
		resy=(int)cal;

		resx=abs(p2.y-p1.y)+abs(p2.x-p1.x);

		p2.x=p2.x+resy;
		p2.y=p1.y - abs(p2.x-p1.x)-resy;

		count++;

	}
	else if(count==3)
	{
		resx=abs(p1.x-p2.x)+abs(p2.y-p1.y);

		p2.x=p2.x+resx;
		p2.y=p1.y- abs(p1.y-p2.y);

		count=1;

	}
	

}


Triangle::~Triangle(void)
{
}
