#include "ObjetoAtaca.h"
#include<stdlib.h>
#include"glut.h"
#include"Pared.h"


ObjetoAtaca::ObjetoAtaca():moodle("imagenes/moodle.png",1)
{
	moodle.setCenter(getPosX(),getPosY());
	moodle.setSize(2,2);
	lado=1;
	velocidad.x = -5.0f;
}


ObjetoAtaca::~ObjetoAtaca()
{
}

void ObjetoAtaca::dibuja() {

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	//glPushMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
	//glRotatef(30, 1, 1, 1);
	//glColor3f(rand() / (float)RAND_MAX,
	//	rand() / (float)RAND_MAX,
	//	rand() / (float)RAND_MAX);//color aleatorio
	//glutSolidCube(lado);
	//glPopMatrix();
	moodle.setState(1, false);
	moodle.draw();

	glPopMatrix();

	}
void ObjetoAtaca:: setPos(float ix, float iy)
{
	//ix = 1 + rand() % (101 - 1);
	//iy = 1 + rand() % (11 - 1);
		ObjetoMovil::setPos(ix, iy);
		origen =posicion;//cambiar
	}