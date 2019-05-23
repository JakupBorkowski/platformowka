#include "cFigura.h"

cFigura::cFigura(double x, double y) {
	cFizyka(x, y);
	red_ = 1.0;
	green_ = 0.0;
	blue_ = 0.0;
}
void cFigura::turnLeft()
{
	x_ -= 0.1;
}
void cFigura::turnRight()
{
	x_ += 0.1;
}
void cFigura::skok()  {
	if (y_ <y_+1)
	{
		y_ += 0.1;
	}
	else if (y_ > y_-1  )
	{
		y_ -= 0.1;
	}
}