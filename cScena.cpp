#include "cScena.h"
#include <GL/freeglut.h>
#include <iostream>
#include <chrono>

int score = 0;
bool jump=false;
cScena::cScena() : active_id_(0) {
	//postac
	figury_.push_back(new cPostac(0.15,2.8,2.0));
	figury_[0]->ustaw_fizyka(6 * 1E-7, -90);
	figury_[0]->ustaw_predkosc(3e-7, 0);
	//ruchome platformy
	figury_.push_back(new cProstokat(1, 0.1, -0.5, -0.5));
	figury_[1]->ustaw_predkosc(3e-4, 0);

	//plansza
	figury_.push_back(new cProstokat(6.8, 0.2, 0, -2.5));
	figury_.push_back(new cProstokat(0.2, 8, -3.4, 0));
	figury_.push_back(new cProstokat(0.2, 5, 3.4, 0));

	figury_.push_back(new cProstokat(4.8, 0.15, 1, 0.5 ));
	figury_.push_back(new cProstokat(4.8, 0.15, -1, 1.5));
	figury_.push_back(new cProstokat(4.8, 0.15, 1, -1.5));
	
	figury_.push_back(new cProstokat(2, 0.15, -2.3, -0.5));
	figury_.push_back(new cProstokat(1.2, 0.15, 1.2, -0.5));
	
	
	
	//pkt-y

	
	figury_.push_back(new cOkrag(0.2,-1.5,1.8,5));
	figury_.push_back(new cMeta(0.6,0.6,-2.8,1.8));

	//pu³apki(kolce)
	//figury_.push_back(new cPrzeszkoda(0.8,0.9,1,1));


	//figury_.push_back(new cProstokat(0.25, 0.25, -0.7, -0.7));
	


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

void cScena::timer() {
	//int current_time = getTickCount();
	//auto current_time = std::chrono::high_resolution_clock::now();
	//std::cout<<current_time<<std::endl;
	//std::cout.flush();
	//skakanie...
	/*if (jump)
	{
		figury_[0]->aktualizuj(GetTickCount());
		for (auto it = figury_.begin(); it != figury_.end(); it++)
		{
			if (figury_[0]->kolizja(**it))
			{
				figury_[0]->ustaw_fizyka(9 * 1E-7, 90);
				if (figury_[0]->kolizja(**it))
				{
					figury_[0]->ustaw_fizyka(0, -90);
					jump = false;
				}
				break;
			}
			
			
		}
		
	}*/






	figury_[0]->aktualizuj(GetTickCount());
	for (auto it = figury_.begin(); it != figury_.end(); it++)
	{
		figury_[0]->kolizja(**it);
	}


	for (auto it = figury_.begin(); it != figury_.end(); it++)
	{
		figury_[0]->kolizja(**it);
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
				char _score[10];
				_itoa_s(score, _score, 10);
				char text[60] = "Points : ";
				strcat_s(text, _score);
				MessageBox(NULL, text, "Koniec Poziomu", 0);
				exit(0);
				break;
			}
		}
	}


	//poruszanie platformy 	
	figury_[1]->aktualizuj(GetTickCount());
	for (auto it = figury_.begin(); it != figury_.end(); it++)
	{
		figury_[1]->kolizja(**it);
	}


	glutPostRedisplay();
	glutTimerFunc(40, timer_binding, 0);
}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{


		for (auto &el : figury_)
			el->rysuj();


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



void cScena::key(unsigned char key, int x, int y) {
	switch (key) {
	//tu brakuje kodu na klawisze 
	case  'w':
		jump = true;
		break;
	case  's':
		//figury_[0]->ustaw_fizyka(9.81*1E-8, 90);
		jump = false;
		break;
	case 'd':
		figury_[0]->turnRight();
		
		break;
	case 'a':
		figury_[0]->turnLeft();
		break;
	}


}

cScena::~cScena() {
	//destruktor 
}
