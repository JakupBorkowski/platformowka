#include "cKolce.h"


cKolce::cKolce(double x, double y)
{
	x_ = x;
	y_ = y;
	ustaw_geometria(x, y, -0.3 / 2, -0.3 / 2, 0.3 / 2, .3 / 2);
}


void cKolce::rysuj()
{
	glPushMatrix();
	glTranslated(x_, y_, 0.0);
	glBegin(GL_TRIANGLES);



	double h = sqrt(0.1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity;

	glColor3f(0.3, 0, .3);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(.3, 0.0, 0.0);
	glVertex3f(0.25, h, 0.0);

	glEnd();

	glPopMatrix();
}

