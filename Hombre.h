
#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;
class Hombre : public ObjetoMovil
{
	friend class Interaccion;
	friend class Mundo;
public:
	void mueve(float t);
	void dibuja();

	Hombre();
	virtual ~Hombre();

	float getAltura() { return altura; }
	float getPosX(void) { return posicion.x; };
	float getPosY(void) { return posicion.y; };
	float getVelY(void) { return velocidad.y; };
	void setVelY(float vy) { velocidad.y = vy; };
	void setPosY(float y) { posicion.y = y; };
	void setGravedad(float g) { aceleracion.y = g; };
private:
	SpriteSequence sprite;
	float altura;


};

