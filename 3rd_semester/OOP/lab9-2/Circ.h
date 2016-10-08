#ifndef CIRC_H
#define CIRC_H

#include "Shape.h"

class Circ:public Shape
{
	int radius ;

public:
	Circ();
	Circ(point, int);
	void rotateRight(){};
	~Circ(void);
};

#endif
