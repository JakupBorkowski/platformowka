#pragma once
#include <GL/freeglut.h>
#include "cFigura.h"

class cPostac :public cFigura {
	int hp_;
	float radius_;

public:
	cPostac(float radius, float x, float y);
	void rysuj();
	void turnRight();
	void turnLeft();
	void skok();

};