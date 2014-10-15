#include <SDL.h>
#include "SpriteDef.h"


#ifndef _SPRITE_H_//evitar la redundancia
#define _SPRITE_H_


class Sprite{
	SDL_Surface *image;
	SDL_Surface *screen;
	SpriteDef spriteDef;
public:
	void CargarImagen(char *ruta);
	//void PintarModulo(int id, int x, int y, int w, int h);
	void PintarModulo(int id, int x, int y);
	Sprite(SDL_Surface * screen);
	~Sprite();
	int widthModule(int id);
	int HeighModule(int id);
};
#endif