#pragma once
#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class ObjetoAtaca:public ObjetoMovil
{
	friend class Interaccion;
public:
	virtual void dibuja();
	ObjetoAtaca();
	~ObjetoAtaca();

	float getLado() { return lado; }
	void setPos(float ix, float iy);
	float getPosX() { return posicion.x; };
	float getPosY() { return posicion.y; };
protected:
	SpriteSequence moodle;
	float lado;
	Vector2D origen;
	int numero;
	int v[3];
};

