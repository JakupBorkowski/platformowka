#include <GL/freeglut.h>
#include "cPrzeszkoda.h"

cPrzeszkoda::cPrzeszkoda(double a, double b, double x, double y) : cFigura(x, y){
	ustaw_geometria(x, y, -a / 2, -b / 2, a / 2, b / 2);
}

void cPrzeszkoda::rysuj() {
	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(red_, green_, blue_);

	glBegin(GL_POLYGON);
	{
		glColor3d(1.0, 0, 0);
		glVertex3d(-a_ / 2, b_ / 2, 0);
		glVertex3d(a_ / 2, b_ / 2, 0);
		glVertex3d(a_ / 2, -b_ / 2, 0);
		glVertex3d(-a_ / 2, -b_ / 2, 0);
	}
	glEnd();
	glPopMatrix();
}
