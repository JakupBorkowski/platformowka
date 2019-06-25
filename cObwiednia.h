#pragma once
#include <GL/freeglut.h>
#include "cFigura.h"


class cObwiednia : public cFigura {
	double a_, b_;

public:
	cObwiednia(double a, double b, double x, double y);
	void rysuj();


};

