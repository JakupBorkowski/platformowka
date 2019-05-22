#pragma once

#include "cFigura.h"
#include <GL/freeglut.h>

class cPrzeszkoda : public cFigura {
	double a_, b_;

public:
	cPrzeszkoda(double a, double b, double x, double y);
	void rysuj();
	void turnRight();
	void turnLeft();
	void skok();
	/*glBegin(GL_TRIANGLES);
	glColor3f(0.1, 0.2, 0.3);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();*/
};