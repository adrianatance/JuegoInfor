#include "Boss.h"
#include "ETSIDI.h"

Boss::Boss():prof("imagenes/prof.png",4)
{
	prof.setCenter(4, 8);
	prof.setSize(4, 7);
	
}



Boss::~Boss()
{
}

void Boss::inicializa() {
	////Destrucción del viejo mundo

	//impacto = false;
	//hombre.setPos(0, 0);
	//esferas.destruirContenido();
	//disparos.destruirContenido();

	////Creación del nuevo mundo

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	profesor.setPos(6, 12);
	//nivel = 0;
	//cargarNivel();

	//bonus.setPos(5.0f, 5.0f);
	//plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);

	//Esfera *e1 = new Esfera(1.5f, 56, 4, 5, 15);
	//e1->setColor(0, 0, 255);
	//esferas.agregar(e1); //esfera

	//Esfera *e2 = new Esfera(2, -2, 58, -5, 15);
	//e2->setColor(255, 255, 255);
	//esferas.agregar(e2); //esfera2

	//EsferaPulsante* e3 = new EsferaPulsante;
	//e3->setColor(0, 255, 0);
	//esferas.agregar(e3);
}

void Boss::dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	glEnable(GL_TEXTURE_2D);
	loadTextura("imagenes/aula.png", -12, 0, 10, 12, 0, 10, 12, 15, 10, -12, 15, 10);
	loadTextura("imagenes/hoja_examen.png", -7, 0, 14, 5, 0, 14, 5, 6,14, -7, 6,14);
	//loadTextura("imagenes/prof.png", 3, 5, 13, 5, 5, 13, 5, 13, 13, 3, 13, 13);
	glEnable(GL_LIGHTING);	//IMPORTANTE NO BORRAR ESTO PARA QUE FUNCIONE LA FORMA DE CARGAR TEXTURAS
	glDisable(GL_TEXTURE_2D); //IMPORTANTE NO BORRAR ESTO PARA QUE FUNCIONE LA FORMA DE CARGAR TEXTURAS

	glPushMatrix();
	glTranslatef(6, 12, 13);
	glColor3f(1.0f, 1.0f, 1.0f);

	prof.setState(3, false);
	prof.draw();

	glPopMatrix();

}

void Boss::mueve(float t, float Amp){
	profesor.mueve_armonico(t, Amp);
	prof.loop();
}

void Boss::loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4) {
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
