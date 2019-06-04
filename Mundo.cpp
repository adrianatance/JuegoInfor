#include "Mundo.h"
#include "glut.h"
#include <cmath>
#include "Interaccion.h"

Mundo::~Mundo()
{
	esferas.destruirContenido();
	disparos.destruirContenido();
}

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	caja.dibuja();
	hombre.dibuja();
	disparos.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	esferas.dibuja();

	ETSIDI::setTextColor(1,1,0);
	ETSIDI::setFont("fuentes/Bitwise.ttf",16);
	ETSIDI::printxy("Pang AAM", -10,17);
	
	ETSIDI::setTextColor(1,1,1);
	ETSIDI::setFont("fuentes/Bitwise.ttf",12);
	ETSIDI::printxy("ADRIAN ATANCE",-10,16.4);
}

void Mundo::mueve()
{

	hombre.mueve(0.025f);
	bonus.mueve(0.025f);

	disparos.mueve(0.025f);
	disparos.colision(caja);
	disparos.colision(plataforma);

	esferas.mueve(0.025f);
	esferas.rebote();
	esferas.rebote(plataforma);
	esferas.rebote(caja);

	Interaccion::rebote(hombre,caja);

	for (int i = 0; i < esferas.getNumero(); i++)
	{
		for (int j = 0; j < disparos.getNumero(); j++)
		{
			if (Interaccion::colision(*disparos[j], *esferas[i]))
			{
				disparos.eliminar(disparos[j]);
				Esfera* e = esferas[i]->dividir();
				if (e == 0) //no division
					esferas.eliminar(esferas[i]);
				else
					esferas.agregar(e);
				ETSIDI::play("sonidos/impacto.wav");
				break;
			}
		}
	}
	Esfera *aux1 = esferas.colision(hombre);
	if (aux1 != 0) impacto = true;
}


void Mundo::inicializa()
{
	//Destrucción del viejo mundo

	impacto = false;
	hombre.setPos(0, 0);
	esferas.destruirContenido();
	disparos.destruirContenido();

	//Creación del nuevo mundo

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	nivel = 0;
	cargarNivel();

	bonus.setPos(5.0f,5.0f);
	plataforma.setPos(-5.0f,9.0f,5.0f,9.0f);

	Esfera *e1=new Esfera(1.5f,2,4,5,15);
	e1->setColor(0,0,255);
	esferas.agregar(e1); //esfera

	Esfera *e2=new Esfera(2,-2,4,-5,15);
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
		case ' ':
			{
 				Disparo* d=new Disparo();
				Vector2D pos=hombre.getPos();
				d->setPos(pos.x,pos.y);
				disparos.agregar(d);
				hombre.setVel(0,0);
				ETSIDI::play("sonidos/disparo.wav");
				break;
			}
		case 'z':
			{
				DisparoEspecial* d = new DisparoEspecial();
				Vector2D pos = hombre.getPos();
				d->setPos(pos.x, pos.y);
				disparos.agregar(d);
				hombre.setVel(0, 0);
				ETSIDI::play("sonidos/disparo.wav");
				break;
			}
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
	}
}

bool Mundo::cargarNivel()
{
	nivel++;
	hombre.setPos(0, 0);
	esferas.destruirContenido();
	disparos.destruirContenido();
	if (nivel == 1)
	{
		plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
		Esfera *e1 = new Esfera(1.5f, 2, 4, 5, 15);
		e1->setColor(0, 0, 255);
		esferas.agregar(e1); //esfera
	}
	if (nivel == 2)
	{
		plataforma.setPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.setColor(255, 0, 0);
		EsferaPulsante* e3 = new EsferaPulsante;
		e3->setPos(0, 12);
		e3->setVel(5, 3);
		esferas.agregar(e3);
	}
	if (nivel == 3)
	{
		plataforma.setPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.setColor(255, 0, 255);
		for (int i = 0; i < 5; i++)
		{
			Esfera* aux = new Esfera(1.5, -5 + i, 12, i, 5);
			aux->setColor(i * 40, 0, 255 - i * 40);
			esferas.agregar(aux);
		}
	}
	if (nivel <= 3)
		return true;
	return false;
}