#pragma once
#include <GL/freeglut.h>
#include "cFigura.h"


class cPomoc : public cFigura {
	double a_, b_;

public:
	cPomoc(double a, double b, double x, double y);
	void rysuj();


};
