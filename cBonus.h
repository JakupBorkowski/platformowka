#pragma once

#include <GL/freeglut.h>
#include "cFigura.h"


class cBonus :public cFigura {
	float radius_;
	

public:
	cBonus(float radius, float x, float y) :cFigura(x, y), radius_(radius){
		ustaw_geometria(x, y, -radius, -radius, radius, radius);
		green_ = 0.7;
	}

	void rysuj();
	


};