#include "cScena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <chrono>

int score = 0;
bool jump=false;
cPostac *p2;
int zdrowie;
int lvl = 0;
cScena::cScena() : active_id_(0) {
	//lvl 1
	lvlOne.push_back(new cPostac(0.05, 1.9, 2));
	lvlOne[0]->ustaw_fizyka(9 * 1E-7, -90);
	lvlOne.push_back(new cProstokat(0.7, 0.15, 0.0, 0.3));
	lvlOne[1]->ustaw_predkosc(3e-4, 0);
	lvlOne.push_back(new cMeta(0.3, 0.3, 0.2, 1.6));

	lvlOne.push_back(new cProstokat(0.7, 0.15, 2.6, 0.3));
	lvlOne.push_back(new cPomoc(0.8, 0.15, 2.6,0.2));
	lvlOne.push_back(new cProstokat(0.7, 0.15, 1.8, 0.9));
	lvlOne.push_back(new cPomoc(0.8, 0.15, 1.8,0.8));

	lvlOne.push_back(new cProstokat(0.7, 0.15, 1.2, 1.5));
	lvlOne.push_back(new cPomoc(0.8, 0.15, 1.2, 1.4));
	

	lvlOne.push_back(new cProstokat(6.8, 0.2, 0, -2.5));
	lvlOne.push_back(new cWall(0.2, 8, -3.4, 0));
	lvlOne.push_back(new cWall2(0.2, 5, 3.4, 0));
	lvlOne.push_back(new cProstokat(0.7, 0.15, -.6, -1.9));
	lvlOne.push_back(new cPomoc(0.8, 0.15, -.6, -2.0));

	lvlOne.push_back(new cProstokat(0.7, 0.15, -1.8, -1.6));
	lvlOne.push_back(new cPomoc(0.8, 0.15, -1.8, -1.7));

	lvlOne.push_back(new cProstokat(0.7, 0.15, -2.6, -1.2));
	lvlOne.push_back(new cPomoc(0.8, 0.15, -2.6, -1.3));

	lvlOne.push_back(new cProstokat(0.7, 0.15, -2.2, -.1));
	lvlOne.push_back(new cPomoc(0.8, 0.15, -2.2, -0.2));

	lvlOne.push_back(new cProstokat(0.7, 0.15, -3.3, -0.6));
	lvlOne.push_back(new cPomoc(0.8, 0.15, -3.3, -0.7));

	lvlOne.push_back(new cProstokat(0.7, 0.15, -1, 0.3));
	lvlOne.push_back(new cPomoc(0.8, 0.15, -1, 0.2));

	lvlOne.push_back(new cOkrag(0.1, -1.8, -1.2, 5));
	lvlOne.push_back(new cOkrag(0.1, 1.2, 1.8, 5));
	lvlOne.push_back(new cOkrag(0.1, -1, 0.6, 5));
	//level 0
	//postac
	figury_.push_back(new cPostac(0.05,1.9,-2.5));
	figury_[0]->ustaw_fizyka(9 * 1E-7, -90);
	
	//figury_[0]->ustaw_fizyka(9*1E-7, -90);
	
	
	//figury_[0]->ustaw_fizyka(4 * 1E-7, -90);
	figury_[0]->ustaw_predkosc(0, 0);
	//ruchome platformy
	figury_.push_back(new cProstokat(1, 0.1, -0.5, -0.5));
	figury_.push_back(new cProstokat(0.7, 0.15, 2.6, -0.5));
	figury_[1]->ustaw_predkosc(3e-4, 0);
	figury_[2]->ustaw_predkosc(3e-4, -90);


	//plansza
	figury_.push_back(new cProstokat(4.8, 0.15, 1, 0.5));
	figury_.push_back(new cObwiednia(0.7, 0.05, 2.6, 0.4));
	figury_.push_back(new cProstokat(6.8, 0.2, 0, -2.5));
	figury_.push_back(new cWall(0.2, 8, -3.4, 0));
	figury_.push_back(new cWall2(0.2, 5, 3.4, 0));


	
	figury_.push_back(new cPomoc(4.9, 0.18, 1, 0.4));
	figury_.push_back(new cProstokat(4.8, 0.15, -1, 1.5));
	figury_.push_back(new cPomoc(4.9, 0.18, -1, 1.4));
	figury_.push_back(new cProstokat(4.8, 0.15, 1, -1.5));
	figury_.push_back(new cPomoc(4.9, 0.18, 1, -1.6));



	
	figury_.push_back(new cProstokat(2, 0.15, -2.3, -0.5));
	figury_.push_back(new cPomoc(2.1, 0.18, -2.3, -0.6));
	figury_.push_back(new cProstokat(1.2, 0.15, 1.2, -0.5));
	figury_.push_back(new cPomoc(1.3, 0.18, 1.2, -0.6));

	figury_.push_back(new cProstokat(1,0.15,-2.5,0.05));


	figury_.push_back(new cProstokat(1, 0.15, -2, -2));
	figury_.push_back(new cProstokat(0.9, 0.15, 2.3, 1));
	figury_.push_back(new cProstokat(0.9, 0.15, 3.4, 1.5));
	figury_.push_back(new cPomoc(1, 0.18, 3.4, 1.4));
	

	//kolce 
	figury_.push_back(new cKolce(0, -2.5));
	figury_.push_back(new cKolce(0, 1.5));
	//figury_.push_back(new cKolce(1, -2.5));
	figury_.push_back(new cKolce(-2, -2.5));

	figury_.push_back(new cKolce(1, 0.5));

	figury_.push_back(new cKolce(-3, -0.5));
	figury_.push_back(new cKolce(-2, -2.5));
	
	//pkt-y

	
	figury_.push_back(new cOkrag(0.1,0.5,-2.1,5));
	figury_.push_back(new cOkrag(0.1, -2.8, 0.6, 5));
	figury_.push_back(new cOkrag(0.1, 3, 1.7, 5));

	figury_.push_back(new cOkrag(0.1, -3, -2, 5));
	figury_.push_back(new cOkrag(0.1, 0, 0, 5));

	figury_.push_back(new cMeta(0.3,0.3,-2.8,1.8));

	


	
	p2 = dynamic_cast<cPostac*>(figury_[0]);
	zdrowie = p2->zwrocHP();
}

void cScena::motion(int x, int y)
{
	//double openglX = ((double)x - 400) / 800 * 6.68;
	//tu potrzerba jakiegos kodu, jezeli mam zamiar uzywac myszki w gierce 
}


void cScena::resize(int width, int height) {
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int acc = 1;
int accumulator = 0;
void cScena::key(unsigned char key, int x, int y) {
	switch (key) {
		//tu brakuje kodu na klawisze 
	case  'w':
		if (acc == 0)
		{
			acc = 1;
			if(lvl==0)
			figury_[0]->skok();
			if (lvl == 1)
			lvlOne[0]->skok();

			//figury_[0]->ustaw_fizyka(9 * 1E-7, -90);
			
			
		}
		break;
	case  's':
		if(lvl==0)
		figury_[0]->stop();
		if(lvl==1)
		lvlOne[0]->stop();
		break;
	case 'a':
		if(lvl==0)
		figury_[0]->turnLeft();
		if(lvl==1)
		lvlOne[0]->turnLeft();
		accumulator = 1;

		break;
	case 'd':
		if(lvl==0)
		figury_[0]->turnRight();
		if(lvl==1)
		lvlOne[0]->turnRight();
		accumulator = 2;
		break;
	}


}
int iterator = 0;
int licznik = 0;
void cScena::timer() {
	
	


		
	if (lvl == 0)
	{
		figury_[0]->aktualizuj(GetTickCount());
		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{

			cWall *p1;
			p1 = dynamic_cast<cWall*>(*it);
			cWall2 *p2;
			p2 = dynamic_cast<cWall2*>(*it);
			cProstokat *p3;
			p3 = dynamic_cast<cProstokat*>(*it);
			if (p1)
			{
				figury_[0]->kolizjaSkok2(**it);


			}
			else if (p2)
			{
				figury_[0]->kolizjaSkok3(**it);
			}
			else if (p3)
			{
				figury_[0]->kolizjaSkok(**it);
			}


		}





		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[0]->kolizjaJeden(**it))
			{
				cPomoc *p1;
				p1 = dynamic_cast<cPomoc*>(*it);
				if (p1)
				{
					figury_[0]->kolizja(**it);
				}
			}
			if (figury_[0]->kolizjaJeden(**it))
			{
				cObwiednia *p1;
				p1 = dynamic_cast<cObwiednia*>(*it);
				if (p1)
				{
					figury_[0]->powrotNaStart();
				}
			}

		}


		//wejscie na kolec i utrata zdrowia, (POBUGOWANE)
		//po wejsciu w przeszkode powrot na start

		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[0]->kolizjaJeden(**it))
			{
				cKolce *p1;
				p1 = dynamic_cast<cKolce*>(*it);
				if (p1)
				{
					figury_[0]->powrotNaStart();
				}
			}
		}

		//zbieranie i zliczanie monet
		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[0]->kolizjaJeden(**it))
			{
				cOkrag *p1;
				p1 = dynamic_cast<cOkrag*>(*it);
				if (p1)
				{
					score += p1->zwrocPunkty();
					figury_.erase(it);
					break;
				}
			}
		}
		//ukonczenie poziomu i wyswietlenie zdobytych punktów
		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[0]->kolizjaJeden(**it))
			{
				cMeta *p1;
				p1 = dynamic_cast<cMeta*>(*it);
				if (p1)
				{	
					licznik++;
					lvl++;
					break;
				}
			}
		}


		//poruszanie platformy 	
		figury_[1]->aktualizuj(GetTickCount());
		figury_[2]->aktualizuj(GetTickCount());
		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			figury_[1]->kolizja(**it);

		}

		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[2]->kolizjaJeden(**it))
			{
				cProstokat *p1;
				p1 = dynamic_cast<cProstokat*>(*it);
				if (p1)
				{
					figury_[2]->kolizja(**it);
				}
			}
		}
	}
	if (lvl == 1)
	{
		figury_.clear();
		lvlOne[0]->aktualizuj(GetTickCount());
		for (auto it = lvlOne.begin(); it != lvlOne.end(); it++)
		{

			cWall *p1;
			p1 = dynamic_cast<cWall*>(*it);
			cWall2 *p2;
			p2 = dynamic_cast<cWall2*>(*it);
			cProstokat *p3;
			p3 = dynamic_cast<cProstokat*>(*it);
			if (p1)
			{
				lvlOne[0]->kolizjaSkok2(**it);


			}
			else if (p2)
			{
				lvlOne[0]->kolizjaSkok3(**it);
			}
			else if (p3)
			{
				lvlOne[0]->kolizjaSkok(**it);
			}


		}
		//nie przeskakwianie przez platformy od spodu
		for (auto it = lvlOne.begin(); it != lvlOne.end(); it++)
		{
			if (lvlOne[0]->kolizjaJeden(**it))
			{
				cPomoc *p1;
				p1 = dynamic_cast<cPomoc*>(*it);
				if (p1)
				{
					lvlOne[0]->kolizja(**it);
				}
			}

		}
		lvlOne[1]->aktualizuj(GetTickCount());
		for (auto it = lvlOne.begin(); it != lvlOne.end(); it++)
		{
			if (lvlOne[1]->kolizjaJeden(**it))
			{
				cPomoc *p1;
				p1 = dynamic_cast<cPomoc*>(*it);
				if (p1)
				{
					lvlOne[1]->kolizja(**it);
				}
			}
		}
		//monetki
		for (auto it =lvlOne.begin(); it != lvlOne.end(); it++)
		{
			if (lvlOne[0]->kolizjaJeden(**it))
			{
				cOkrag *p1;
				p1 = dynamic_cast<cOkrag*>(*it);
				if (p1)
				{
					score += p1->zwrocPunkty();
					lvlOne.erase(it);
					break;
				}
			}
		}
		//koniec
		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[0]->kolizjaJeden(**it))
			{
				cMeta *p1;
				p1 = dynamic_cast<cMeta*>(*it);
				if (p1)
				{
					char _score[10];
					_itoa_s(score, _score, 10);
					char text[60] = "Points : ";
					strcat_s(text, _score);
					MessageBox(NULL, text, "Koniec Poziomu", 0);
					exit(0);
					licznik++;
					break;
				}
			}
		}
		if (lvlOne[0]->kolizja(*lvlOne[2]))
		{
			char _score[10];
			_itoa_s(score, _score, 10);
			char text[60] = "Points : ";
			strcat_s(text, _score);
			MessageBox(NULL, text, "Koniec Poziomu", 0);
			exit(0);
		}
		}
	
	

	glutPostRedisplay();
	glutTimerFunc(40, timer_binding, 0);
}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{

		if (lvl == 0)
		{
			for (auto &el : figury_)
				el->rysuj();
		}
		if(lvl==1)
		{
			for (auto &el : lvlOne)
				el->rysuj();
		}


	}
	glPopMatrix();

	glutSwapBuffers();
}


void cScena::set_callbacks() {
	glutReshapeFunc(resize_binding);
	glutDisplayFunc(display_binding);
	//glutIdleFunc(idle_binding);
	glutTimerFunc(40, timer_binding, 0);
	glutKeyboardFunc(key_binding);
	glutPassiveMotionFunc(motion_binding);

}

void cScena::init(int argc, char **argv, const char *window_name) {

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	set_callbacks();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();
}



cScena::~cScena() {
	//destruktor 
}
