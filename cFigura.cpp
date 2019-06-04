#include "cFigura.h"

cFigura::cFigura(double x, double y) {
	cFizyka(x, y);
	red_ = 1.0;
	green_ = 0.0;
	blue_ = 0.0;
}
void cFigura::turnLeft()
{
	ustaw_predkosc(3e-3, 0);
}
void cFigura::turnRight()
{
	ustaw_predkosc(3e-3, -180);
}




void cFigura::skok()  {
	
}