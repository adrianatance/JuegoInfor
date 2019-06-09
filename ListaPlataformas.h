#pragma once
#include"glut.h"
#include"Pared.h"
#define MAX 100
class ListaPlataformas
{
private:
	Pared *Lista[MAX];
	int numero;
public:
	ListaPlataformas();
	~ListaPlataformas();
	bool Agregar(Pared *p);
	void dibuja();
	Pared * operator [] (int i);
};

