#ifndef _NAVE_H
#define _NAVE_H
#include "Objeto.h"

class Nave{

	Objeto *nave;
	Objeto **bala;
	int balasVisibles;
public:

	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	void Pintar();
	void Disparar(int tipo, int valor);
	void AutoDisparar(int efectividad, int valor);
	void Actualizar(int tipo, int valor);
	void MoverIzquierda(int valor);
	void MoverDerecha(int valor);
	void MoverArriba(int valor);
	void MoverAbajo(int valor);
	Objeto * GetNaveObjeto();
};

#endif
