#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle:public Shape
{
	point p2 ;
public:

	static int count;
	Triangle();
	point getinitial();
	point getfinal();
	void rotateRight();
	~Triangle(void);
};

#endif

