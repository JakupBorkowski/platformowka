#pragma once

#include <GL/freeglut.h>
#include "cFigura.h"


class cOkrag :public cFigura {
	float radius_;

public:
	cOkrag(float radius, float x, float y) :cFigura(x, y), radius_(radius) {
		//ustaw_geometria(x, y, -radius, -radius, radius, radius);
	}
	void rysuj();



};