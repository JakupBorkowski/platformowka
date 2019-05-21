#pragma once

#include "cFigura.h"
#include <GL/freeglut.h>

class cPrzeszkoda: public cFigura {


public:
	void rysuj();
/*glBegin(GL_TRIANGLES);
glColor3f(0.1, 0.2, 0.3);
glVertex3f(0, 0, 0);
glVertex3f(1, 0, 0);
glVertex3f(0, 1, 0);
glEnd();*/
};