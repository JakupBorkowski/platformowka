#pragma once
#include <GL/freeglut.h>
#include "cFigura.h"


class cProstokat : public cFigura {
	double a_, b_;

public:
	cProstokat(double a, double b, double x, double y);
	void rysuj();
	

};
