#pragma once
#include "Mundo.h"

class CoordinadorPang
{
public:
	CoordinadorPang();
	virtual ~CoordinadorPang();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	Mundo Mundo;

protected:
	enum Estado {INICIO, JUEGO, BOSS, GAMEOVER, FIN, PAUSA};
	Estado estado;
};