#pragma once

#include "cFizyka.h"

class cFigura : public cFizyka {
protected:
	double red_, green_, blue_;

public:
	cFigura(double x = 0.0, double y = 0.0);
	virtual void rysuj() = 0;

};


