#ifndef __Nave_H__
#define __Nave_H__
#include "Sprite.h"
class nave{
	int x;
	int y;

	Sprite *sprite; // este es un apuntador, este sprite remplaza al que tenemos en Game.ccp

public:
	Nave(SDL_Surface * screen, char * rutaIMagen){
		~Nave();
		void Pintar();
		void Mover(int posicion);
};



#endif