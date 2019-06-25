#pragma once
#include <GL/freeglut.h>
#include "cFigura.h"


class cWall2 : public cFigura {
	double a_, b_;

public:
	cWall2(double a, double b, double x, double y);
	void rysuj();


};
