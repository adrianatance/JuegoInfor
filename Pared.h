
#pragma once


#include "Vector2D.h"
#include "ColorRGB.h"

class Pared  
{
	friend class ObjetoAtaca;
	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();
	void dibuja();
	void setColor(Byte r,Byte v, Byte a);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D *direccion=0);
	float getLimiteX2() { return limite2.x; };
	float getLimiteY2() { return limite2.y; };
protected:
	Vector2D limite1;
	Vector2D limite2;
	ColorRGB color;
};
