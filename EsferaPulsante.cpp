#include "EsferaPulsante.h"


EsferaPulsante::EsferaPulsante(void)
{
	radio_max=2.0f;
	radio_min=0.5f;
	pulso=0.5f;
	aceleracion.y=0.0f;
	posicion.y=5.0f;
}


EsferaPulsante::~EsferaPulsante(void)
{
}


void EsferaPulsante::mueve(float t)
{
	Esfera::mueve(t);

	if(radio>radio_max)
		pulso=-pulso;
	if(radio<radio_min)
		pulso=-pulso;
	radio+=pulso*t;

	color.r=radio*255;
	color.g=255-radio*100;
	color.b=100+radio*50;
}

EsferaPulsante* EsferaPulsante::dividir()
{
	if (radio < 1.0f)
		return 0; //no dividimos
	radio /= 2.0f;//Dividimos el radio por 2
	//Creamos una esfera nueva, copiando la actual
	EsferaPulsante *aux = new EsferaPulsante(*this);
	//Les damos nuevas velocidades
	aux->pulso+=(+0.1);
	aux->setVel(5, 8);//a la nueva mitad
	setVel(-5, 8);//a la mitad original
	return aux;
}
