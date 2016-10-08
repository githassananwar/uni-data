#ifndef SHAPE_H
#define SHAPE_H

#include <math.h>
struct point
{
	int x;
	int y;
};

class Shape
{

protected:
	point p1 ;

public:
	Shape();
	Shape(point pt);
	virtual void rotateRight() = 0 ;
	~Shape(void);
};
#endif
