#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(int x, int y)
{
	this->x=x;
	this->y=y;
}

void Point::setPoint(int x, int y)
{
	this->x=x;
	this->y=y;
}

int Point :: getX()
{
	return x;
}

int Point :: getY()
{
	return y;
}

istream& operator>>(istream& input, Point& pt)
{
	//Input
	cout<<"Enter point (r,c): ";
	input>>pt.x>>pt.y;

	//Input validation
	while(pt.x<1 || pt.x>10 || pt.y<1 || pt.y>10)
	{
		cout<<"Invalid point! Enter again (r,c):  ";
		input>>pt.x>>pt.y;
	}

	//decrementing point(x,y) to use them as indexes
	pt.x--;
	pt.y--;

	return input;
}

Point::~Point()
{
}
