#include "ListaObjetoAtaca.h"
#include"Interaccion.h"



ListaObjetoAtaca::ListaObjetoAtaca()
{
}


ListaObjetoAtaca::~ListaObjetoAtaca()
{
}
void ListaObjetoAtaca::dibuja()
{
	if (numero>0) {
		for (int i = 0; i < numero; i++)
			ob[i]->dibuja();
	}
}
void ListaObjetoAtaca::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		ob[i]->mueve(t);
}
bool ListaObjetoAtaca::agregar(ObjetoAtaca *o)
{
	if (numero < 3) {
		for (int i = 0; i < numero; i++) {
			if (ob[i] == o) return false;
		}
		ob[numero++] = o;
		return true;
	}
	return false;
	
}
ObjetoAtaca * ListaObjetoAtaca::colision(Hombre h)
{
	
		for (int i = 0; i < numero; i++)
		{
			if (Interaccion::colision(*(ob[i]), h))
				return ob[i];
		}
		return 0; //no hay colisión

}
void ListaObjetoAtaca::colision(Caja c)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision((ob[i]), c))
		{
			delete ob[i];

		}
	}
}
void ListaObjetoAtaca::colision(Pared p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision((ob[i]), p))
		{
			ob[i]->setVel(0, 0);
		}
	}
}
void ListaObjetoAtaca::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete ob[i];

	numero = 0;
}
void ListaObjetoAtaca::eliminar(int index)
{
	if ((index >= 0) || (index < numero)) {
		delete ob[index];
		numero--;
		for (int i = index; i < numero; i++)
			ob[i] = ob[i + 1];
	}
}

void ListaObjetoAtaca::eliminar(ObjetoAtaca *o)
{
	for (int i = 0; i < numero; i++) {
		if (ob[i] == o)
		{
			eliminar(i);
			return;
		}
	}

}
ObjetoAtaca  *ListaObjetoAtaca::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return ob[i];
}
