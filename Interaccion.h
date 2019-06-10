#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"
#include "ObjetoAtaca.h"
#include"ListaPlataformas.h"

class Interaccion  
{
public:
	
	Interaccion();
	virtual ~Interaccion();	

	//funciones que modifican (paso por referencia) los objetos que se les pasa como parametro	
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);
	static void rebote(Hombre& h, Pared plataforma);
	static void rebote(Hombre&h, Pared*p);
	//static void rebote(ObjetoAtaca *o, Pared *p);

	//funciones de informacion, no cambian los objetos, solo devuelven true si hay colision
	static bool colision(Esfera e, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
	static bool colision(Disparo d, Esfera e);
	static bool colision(ObjetoAtaca o, Hombre h);
	static bool colision(ObjetoAtaca* o, Pared p);
	static bool colision(ObjetoAtaca* o, Caja c);



};

