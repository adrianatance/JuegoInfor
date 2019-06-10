#pragma once
#include"ObjetoAtaca.h"
#include"Caja.h"
#include"Hombre.h"
class ListaObjetoAtaca:public ObjetoAtaca
{
public:
	ListaObjetoAtaca();
	~ListaObjetoAtaca();
	bool agregar(ObjetoAtaca * ob);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
    void colision(Pared p);
	void colision(Caja c);
	ObjetoAtaca *colision(Hombre h);
	ObjetoAtaca* operator[] (int index);
	int getNumero() { return numero; }
	void eliminar(ObjetoAtaca* ob);
	void eliminar(int index);
private:
	ObjetoAtaca *ob[3];
	int numero;
};

