#pragma once
#include"glut.h"
#include"ObjetoMovil.h"
#include"ETSIDI.h"

using ETSIDI::SpriteSequence;

class Boss
{
private:
	float x_ojo, y_ojo, z_ojo;
	SpriteSequence prof;
	ObjetoMovil profesor;
public:
	Boss();
	~Boss();
	void inicializa();
	void dibuja();
	void mueve(float t, float Amp);
	void loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
};

