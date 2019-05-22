#pragma once

#include "cFizyka.h"

class cFigura : public cFizyka {
protected:
	double red_, green_, blue_;

public:
	cFigura(double x = 0.0, double y = 0.0);
	virtual void rysuj() = 0;
	void turnRight();
	void turnLeft();
	double Y()
	{
		return y_;
	}
	void skok();
};


