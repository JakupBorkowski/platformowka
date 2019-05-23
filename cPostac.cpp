#include"cPostac.h"




cPostac::cPostac(float radius, float x, float y) :cFigura(x, y), radius_(radius) {
	ustaw_geometria(x, y, -radius, -radius, radius, radius);
}
void cPostac::rysuj() {
	double angle, vectorX, vectorY, vectorX1, vectorY1;
	glPushMatrix();
	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);
	glColor3d(red_, green_, blue_);
	glBegin(GL_LINE_LOOP);
	vectorX1 = radius_;
	vectorY1 = radius_;
	int seg = 360;
	for (int i = 0; i <= seg; i++)
	{
		angle = (M_PI / (180.0))*((float)i);
		vectorX = radius_ + (radius_*sin(angle));
		vectorY = radius_ + (radius_*cos(angle));
		glVertex2f(radius_, radius_);
		glVertex2f(vectorX1, vectorY1);
		glVertex2f(vectorX, vectorY);
		vectorY1 = vectorY;
		vectorX1 = vectorX;
	}
	glEnd();
	glPopMatrix();
}