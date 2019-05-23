#pragma once

#include "cFigura.h"
#include <GL/freeglut.h>

class cPrzeszkoda : public cFigura {
	double a_, b_;
public:
	cPrzeszkoda(double a, double b,double x, double y);
	void rysuj();
	void rysujTrzy();

	
};