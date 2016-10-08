#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
	//Co-ordinates
	int x;
	int y;

public:
	Point(int=0, int=0); //default constructor
	void setPoint(int, int);
	int getX();
	int getY();
	friend istream& operator>>(istream&, Point&); //friend means to globalize the function i.e to use class data members

	~Point();
};

#endif