#pragma once
#include "cProstokat.h"
#include "cOkrag.h"
#include "cPostac.h"
#include "cMeta.h"
#include "cKolce.h"
#include "cWall.h"
#include "cWall2.h"
#include "cBonus.h"
#include"cPomoc.h"
#include "cObwiednia.h"
#include <vector>

//bindingi dla callbacków
void resize_binding(int width, int height);
void display_binding();
void key_binding(unsigned char key, int x, int y);
void timer_binding(int i);
void motion_binding(int x, int y);

class cScena {
	std::vector<cFigura*> figury_;
	std::vector<cFigura*> lvlOne;
	int active_id_;
public:
	cScena();
	~cScena();
	void resize(int width, int height);
	void timer();
	void display();
	void init(int argc, char *argv[], const char* window_name);
	void set_callbacks();
	void key(unsigned char key, int x, int y);
	void motion(int x, int y);
	void lvl_2();

};
