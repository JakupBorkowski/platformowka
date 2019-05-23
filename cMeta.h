#pragma once
#include "cFigura.h" 
#include <GL/freeglut.h>

class cMeta :public cFigura {
	double a_, b_;

public:
	cMeta(double a, double b, double x, double y);
	void rysuj();


};