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
#include"ListaPlataformas.h"
//#include"ObjetoAtaca.h"
#include"ListaObjetoAtaca.h"

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
	ListaPlataformas plataformas;
	//ObjetoAtaca obj;
	ListaObjetoAtaca ataque;

	float x_ojo;
	float y_ojo;
	float z_ojo;
	bool impacto;
	int nivel,i,num=3;
	float a = 0, b = 0;
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
	float Ojo(Hombre h);
	float getOjoX() { return hombre.getPosX(); };

};
