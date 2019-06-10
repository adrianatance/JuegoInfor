

#include "Caja.h"
#include "ETSIDI.h"

Caja::Caja()
{
	suelo.setColor(100,100,70);
	suelo.setPos(-10.0f, 0, 100.0f, 0);

	techo.setColor(100,100,70);
	techo.setPos(-10.0f, 15.0f, 100.0f, 15.0f);
	
	pared_dcha.setColor(100,100,70);
	pared_dcha.setPos(-10.0f,0,-10.0f,15.0f);

	pared_izq.setColor(100,100,70);
	pared_izq.setPos(100.0f, 0, 100.0f, 15.0f);
}

Caja::~Caja()
{

}

void Caja::loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4) {
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(ruta).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(x1, y1, z1);
	glTexCoord2d(1, 1);		glVertex3f(x2, y2, z2);
	glTexCoord2d(1, 0);		glVertex3f(x3, y3, z3);
	glTexCoord2d(0, 0);		glVertex3f(x4, y4, z4);
	glEnd();
}

void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D); //IMPORTANTE NO BORRAR ESTO PARA QUE FUNCIONE LA FORMA DE CARGAR TEXTURAS
  
	loadTextura("imagenes/entrada.png", -9.9, 0, -10, -9.9, 0, 10, -9.9, 15, 10, -9.9, 15, -10);

	loadTextura("imagenes/pared.png", -10, 0, -10, 10, 0, -10, 10, 15, -10, -10, 15, -10);
	loadTextura("imagenes/pared.png", 10, 0, -10, 30, 0, -10, 30, 15, -10, 10, 15, -10);
	loadTextura("imagenes/pared.png", 30, 0, -10, 50, 0, -10, 50, 15, -10, 30, 15, -10);
	loadTextura("imagenes/pared.png", 50, 0, -10, 70, 0, -10, 70, 15, -10, 50, 15, -10);
	loadTextura("imagenes/pared.png", 70, 0, -10, 90, 0, -10, 90, 15, -10, 70, 15, -10);
	loadTextura("imagenes/pared.png", 90, 0, -10, 110, 0, -10, 110, 15, -10, 90, 15, -10);

	loadTextura("imagenes/techo.png", -10, 14.9, -10, 10, 14.9, -10, 10, 14.9, 10, -10, 14.9, 10);
	loadTextura("imagenes/techo.png", 10, 14.9, -10, 30, 14.9, -10, 30, 14.9, 10, 10, 14.9, 10);
	loadTextura("imagenes/techo.png", 30, 14.9, -10, 50, 14.9, -10, 50, 14.9, 10, 30, 14.9, 10);
	loadTextura("imagenes/techo.png", 50, 14.9, -10, 70, 14.9, -10, 70, 14.9, 10, 50, 14.9, 10);
	loadTextura("imagenes/techo.png", 70, 14.9, -10, 90, 14.9, -10, 90, 14.9, 10, 70, 14.9, 10);
	loadTextura("imagenes/techo_sin_luz.png", 90, 14.9, -10, 110, 14.9, -10, 110, 14.9, 10, 90, 14.9, 10); //se mete punto1(x,y,z) punto2(x,y,z) punto3(x,y,z) y punto4(x,y,z)

	loadTextura("imagenes/salida_A35.png", 99.9, 0, -10, 99.9, 0, 10, 99.9, 15, 10, 99.9, 15, -10);


	glEnable(GL_LIGHTING);	//IMPORTANTE NO BORRAR ESTO PARA QUE FUNCIONE LA FORMA DE CARGAR TEXTURAS
	glDisable(GL_TEXTURE_2D); //IMPORTANTE NO BORRAR ESTO PARA QUE FUNCIONE LA FORMA DE CARGAR TEXTURAS
}
