#ifndef RECT_H
#define RECT_H
#include"Shape.h"

class Rect:public Shape
{
	point p2 ;
public:
	Rect();
	point getinitial();
	point getfinal();
	void rotateRight();
	~Rect(void);
};
#endif
