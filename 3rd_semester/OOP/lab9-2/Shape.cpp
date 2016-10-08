#include "stdafx.h"
#include "Shape.h"


Shape::Shape()
{
	p1.x = 0;
	p1.y=0;
}

Shape::Shape(point pt)
{
	p1.x = pt.x ;
	p1.y = pt.y ;
}


Shape::~Shape(void)
{
}
