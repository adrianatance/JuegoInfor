#pragma once
#include "Caja.h"	
#include "Hombre.h"	
#include "Esfera.h"	
#include "Bonus.h"	
#include "Disparo.h"
#include "ListaEsferas.h"	
#include "ListaDisparos.h"	
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"

class Mundo
{
	friend class CoordinadorPang;

	EsferaPulsante esfera_pulsante;
	DisparoEspecial disparo_especial;

	ListaEsferas esferas;
	ListaDisparos disparos;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;

	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto;
	int nivel;
public:  
	~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	bool getImpacto() { return impacto; }
	int getNumEsferas() { return esferas.getNumero(); }
	bool cargarNivel();

};
