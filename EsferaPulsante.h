#pragma once

#include "Esfera.h"

class EsferaPulsante :public Esfera 
{
public:
	EsferaPulsante(void);
	virtual ~EsferaPulsante(void);
	void mueve(float t);
	virtual EsferaPulsante* dividir();

private:
	float radio_max;
	float radio_min;
	float pulso;

};
