#pragma once
#include <GL/freeglut.h>
#include "cFigura.h"


class cWall : public cFigura {
	double a_, b_;

public:
	cWall(double a, double b, double x, double y);
	void rysuj();


};
