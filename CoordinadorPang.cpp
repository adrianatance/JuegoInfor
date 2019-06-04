#include "CoordinadorPang.h"
#include "Mundo.h"
#include "glut.h"



CoordinadorPang::CoordinadorPang()
{
		estado = INICIO;
}


CoordinadorPang::~CoordinadorPang()
{
}

void CoordinadorPang::dibuja()
{
	if (estado == INICIO) {
		Mundo.inicializa();
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang AAM", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("ADRIAN ATANCE", 2, 1);
	}
	else if (estado == JUEGO)
	{
		Mundo.dibuja();
	}
	else if (estado == GAMEOVER)
	{
		Mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == PAUSA)
	{
		Mundo.dibuja();
		
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSE", -5, 10);
		ETSIDI::printxy("Pulsa -C- para VOLVER", -5, 5);
	}
	else if (estado == FIN)
	{
		Mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void CoordinadorPang::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			Mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		Mundo.tecla(key);
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == JUEGO)
	{
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == PAUSA)
	{
		if (key == 'c')
			estado == JUEGO;
	}
}

void CoordinadorPang::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		Mundo.teclaEspecial(key);
}

void CoordinadorPang::mueve()
{
	if (estado == JUEGO)
	{
		Mundo.mueve();
		if (Mundo.getNumEsferas() == 0)
		{
			if (!Mundo.cargarNivel())
				estado = FIN;
		}
		if (Mundo.getImpacto())
		{
			estado = GAMEOVER;
		}
	}
}