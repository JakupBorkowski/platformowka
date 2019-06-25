#include "cFigura.h"
int predkosc = 0;
cFigura::cFigura(double x, double y) {
	cFizyka(x, y);
	red_ = 1.0;
	green_ = 0.0;
	blue_ = 0.0;
}
int katSkoku=1;
void cFigura::turnRight()
{
	if (katSkoku == 2)
	{
		ustaw_predkosc(1.1e-3, 0);

		katSkoku = 0;
	}
	else if (katSkoku == 1)
	{
		ustaw_predkosc(1.1e-3, 0);

		katSkoku = 0;
	}
	
}
void cFigura::turnLeft()
{
	if (katSkoku == 2)
	{
		ustaw_predkosc(1.1e-3, -180);
		katSkoku = 1;
	}
	else if (katSkoku == 0)
	{
		ustaw_predkosc(1.1e-3, -180);

		katSkoku = 1;
	}
	
}
void cFigura::stop()
{
	v_ = 0;
	katSkoku = 2;
}

void cFigura::skok()  {
	ustaw_fizyka(9*1E-7, -90);
	if (katSkoku ==0)
	{
		ustaw_predkosc(1.1e-3, 60);
	}
	else if(katSkoku==1)
	{
		ustaw_predkosc(1.1e-3, -240);
	}
	else if (katSkoku == 2)
	{
		ustaw_predkosc(1.1e-3, 90);
	}
}