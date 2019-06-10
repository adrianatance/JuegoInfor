#include "Mundo.h"
#include "glut.h"
#include <cmath>
#include "Interaccion.h"

Mundo::~Mundo()
{
	esferas.destruirContenido();
}

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

float Mundo::Ojo(Hombre h) {
	float ojoX; //la posicion x del ojo;
	if (h.getPosX() < (0.0f)) return 0.0f;
	if (h.getPosX() > 90.0f) return 90.0f;
	return h.getPosX();
}

void Mundo::dibuja()
{
	gluLookAt(Ojo(hombre), y_ojo, z_ojo,  // posicion del ojo
			Ojo(hombre), y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	caja.dibuja();
	hombre.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	esferas.dibuja();

	ETSIDI::setTextColor(1,1,0);
	ETSIDI::setFont("fuentes/Bitwise.ttf",16);
	ETSIDI::printxy("Pang AAM",-10,17);
	
	ETSIDI::setTextColor(1,1,1);
	ETSIDI::setFont("fuentes/Bitwise.ttf",12);
	ETSIDI::printxy("ATANCE, BAREA, DERKACH",-10,16.4);
}

void Mundo::mueve()
{

	hombre.mueve(0.025f);
	bonus.mueve(0.025f);

	esferas.mueve(0.025f);
	esferas.rebote();
	esferas.rebote(plataforma);
	esferas.rebote(caja);

	Interaccion::rebote(hombre,caja);
	Interaccion::rebote(hombre, plataforma);

	
	Esfera *aux1 = esferas.colision(hombre);
	if (aux1 != 0) impacto = true;
}


void Mundo::inicializa()
{
	//Destrucción del viejo mundo

	impacto = false;
	hombre.setPos(0, 0);
	esferas.destruirContenido();

	//Creación del nuevo mundo

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	nivel = 0;
	cargarNivel();

	bonus.setPos(5.0f,5.0f);
	plataforma.setPos(-5.0f,9.0f,5.0f,9.0f);

	Esfera *e1=new Esfera(1.5f,56,4,5,15);
	e1->setColor(0,0,255);
	esferas.agregar(e1); //esfera

	Esfera *e2=new Esfera(2,-2,58,-5,15);
	e2->setColor(255,255,255);
	esferas.agregar(e2); //esfera2

	EsferaPulsante* e3 = new EsferaPulsante;
	e3->setColor(0, 255, 0);
	esferas.agregar(e3);

}

void Mundo::tecla(unsigned char key)
{
		switch(key)
	{
		case '1':	
 			esferas.agregar (new Esfera(0.5f,0,10));
			break;
		case '2':	
 			esferas.agregar (new Esfera(1.0f,0,10));
			break;
		case '3':	
 			esferas.agregar (new Esfera(1.5f,0,10));
			break;
		case '4':	
 			esferas.agregar (new Esfera(2.0f,0,10));
			break;
	}

}
void Mundo::teclaEspecial(unsigned char key)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel (-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel (5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		hombre.setVelY(10.0f);
		break;
	}
	
}

bool Mundo::cargarNivel()
{
	nivel++;
	hombre.setPos(0, 0);
	esferas.destruirContenido();
	if (nivel == 1)
	{
		plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
		Esfera *e1 = new Esfera(1.5f, 54, 4, 5, 15);
		e1->setColor(0, 0, 255);
		esferas.agregar(e1); //esfera
	}
	if (nivel == 2)
	{
		plataforma.setPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.setColor(255, 0, 0);
		EsferaPulsante* e3 = new EsferaPulsante;
		e3->setPos(50, 2);
		e3->setVel(-5, 3);
		esferas.agregar(e3);
	}
	if (nivel == 3)
	{
		plataforma.setPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.setColor(255, 0, 255);
		for (int i = 0; i < 5; i++)
		{
			Esfera* aux = new Esfera(1.5, 50 + i, 12, -i, 5);
			aux->setColor(i * 40, 0, 255 - i * 40);
			esferas.agregar(aux);
		}
	}
	if (nivel <= 3)
		return true;
	return false;
}