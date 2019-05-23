#pragma once

#include <GL/freeglut.h>
#include "cFigura.h"


class cOkrag :public cFigura {
	float radius_;
	int pkt_;

public:
	cOkrag(float radius, float x, float y, int lp) :cFigura(x, y), radius_(radius), pkt_(lp) {
		ustaw_geometria(x, y, -radius, -radius, radius, radius);
		green_ = 0.7;
	}

	void rysuj();
	int zwrocPunkty();


};