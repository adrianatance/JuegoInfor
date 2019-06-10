

#include "Hombre.h"
#include "glut.h"
#include <stdlib.h>


Hombre::Hombre():sprite("imagenes/Personaje.png",40)
{
	sprite.setCenter(1,0);
	sprite.setSize(3,5);
	altura=1.8f;
	aceleracion.y = -9.8f; //hay que aplicarle la gravedad para que se termine de caer siempre y no se quede colgado a una cota superior.
}

Hombre::~Hombre()
{

}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0.5);
   	glColor3f(1.0f,1.0f,1.0f);
    //glutSolidSphere(altura, 20, 20); //esfera antigua de diseño

	//gestion de direccion y animacion
	if(velocidad.x>0.01)sprite.flip(false,false);
	if(velocidad.x<-0.01)sprite.flip(true,false);
	if((velocidad.x<0.01)&&(velocidad.x>-0.01))
		sprite.setState(0);
	else if (sprite.getState()==0)
		sprite.setState(1,false);
	sprite.draw();

	glPopMatrix();

}

void Hombre::mueve(float t)
{
	ObjetoMovil::mueve(t);
	sprite.loop();
}

