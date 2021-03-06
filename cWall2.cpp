#include <GL/freeglut.h>
#include "cWall2.h"

cWall2::cWall2(double a, double b, double x, double y) : cFigura(x, y), a_(a), b_(b) {
	ustaw_geometria(x, y, -a / 2, -b / 2, a / 2, b / 2);
}

void cWall2::rysuj() {
	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(red_, green_, blue_);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-a_ / 2, b_ / 2, 0);
		glVertex3d(a_ / 2, b_ / 2, 0);
		glVertex3d(a_ / 2, -b_ / 2, 0);
		glVertex3d(-a_ / 2, -b_ / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

