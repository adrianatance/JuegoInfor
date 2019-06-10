#pragma once
#include "Mundo.h"
#include "Boss.h"

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
	Boss Boss;

protected:
	enum Estado {INICIO, JUEGO, BOSS, GAMEOVER, FIN, PAUSA};
	Estado estado;
	bool flag_final_pasillo;
	int vida;
};