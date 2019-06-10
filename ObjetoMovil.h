#pragma once

#include "Vector2D.h"

class ObjetoMovil  
{
public:
	ObjetoMovil(void);
	virtual ~ObjetoMovil(void);
	virtual void mueve(float t);
	void mueve_armonico(float t, float Amp);
	Vector2D getPos();
	float getPosX() { return posicion.x; };
	float getPosY() { return posicion.y; };
	void setVel(float vx, float vy);
	void setVel(Vector2D vel);
	void setPos(float x,float y);
	void setPos(Vector2D pos);


protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};


