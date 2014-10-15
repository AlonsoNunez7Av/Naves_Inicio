#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char * rutaIMagen){

	Sprite = new Sprite(screen);
	sprite->CargarImagen(rutaIMagen);
	x = (WIDTH_SCREEN / 2) - (sprite->WidthImage() / 2);
	y = (HEIGTH_SCREEN - 80) - (sprite->HeghtImage());
}

Nave::~nave(){
	delete Sprite;
}

void Nave::Pintar(){
	Sprite - PintarModulo(0, x, y);
}

void Nave::Mover(int posicion){
	x + = posicion;
}
