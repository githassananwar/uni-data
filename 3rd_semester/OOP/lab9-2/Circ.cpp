#include "stdafx.h"
#include "Circ.h"

Circ::Circ()
{
	radius=0;
}

Circ::Circ(point pt, int r):Shape(pt)
{
	radius=r ;
}


Circ::~Circ(void)
{
}
