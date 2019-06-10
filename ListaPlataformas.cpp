#include "ListaPlataformas.h"
#include "Interaccion.h"


ListaPlataformas::ListaPlataformas()
{
	numero = 0;
	for (int i = 0; i < MAX; i++)Lista[i] = 0;
}


ListaPlataformas::~ListaPlataformas()
{
}
bool ListaPlataformas::Agregar(Pared *P){
	for (int i = 0; i < numero; i++)//para evitar que se añada una ya existente
		if (Lista[i] == P)
			return false;
	if (numero < MAX)
		Lista[numero++] = P;
	else
		return false;
	return true;
}
void ListaPlataformas::dibuja()
{
	for (int i = 0; i < numero; i++)
		Lista[i]->dibuja();
}
Pared *ListaPlataformas::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return Lista[i];
}
void ListaPlataformas::rebote(Hombre &h, Pared *Lista)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(h, *Lista);
}