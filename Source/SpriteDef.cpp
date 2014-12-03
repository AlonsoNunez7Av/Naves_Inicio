#include "SpriteDef.h"
#include "Config.h"
SpriteDef::SpriteDef(){
	modulo[0].id =MODULO_MINAVE_NAVE;
	modulo[0].x=0;
	modulo[0].y=0;
	modulo[0].w=64;
	modulo[0].h=64;

	modulo[1].id =MODULO_MENU_FONDO;
	modulo[1].x =0;
	modulo[1].y =0;
	modulo[1].w = WIDTH_SCREEN;
	modulo[1].h = HEIGHT_SCREEN;

	modulo[2].id =MODULO_ENEMIGO_NAVE;
	modulo[2].x =0;
	modulo[2].y =0;
	modulo[2].w = 54;
	modulo[2].h = 61;

	modulo[3].id =MODULO_TEXTO_TITULO;
	modulo[3].x = 129;
	modulo[3].y = 20;
	modulo[3].w = 325;
	modulo[3].h = 51;

	modulo[4].id =MODULO_TEXTO_NOMBRE;
	modulo[4].x = 6;
	modulo[4].y = 137;
	modulo[4].w = 239;
	modulo[4].h = 27;

	modulo[5].id =MODULO_TEXTO_OPCION1;
	modulo[5].x = 324;
	modulo[5].y = 241;
	modulo[5].w = 109;
	modulo[5].h = 26;

	modulo[6].id =MODULO_TEXTO_OPCION2;
	modulo[6].x = 515;
	modulo[6].y = 239;
	modulo[6].w = 75;
	modulo[6].h = 27;

	modulo[7].id =MODULO_TEXTO_OPCION1_SELECCION;
	modulo[7].x = 325;
	modulo[7].y = 350;
	modulo[7].w = 108;
	modulo[7].h = 30;

	modulo[8].id =MODULO_TEXTO_OPCION2_SELECCION;
	modulo[8].x = 516;
	modulo[8].y = 349;
	modulo[8].w = 77;
	modulo[8].h = 31;

	modulo[9].id =MODULO_BALAS_BALA1;
	modulo[9].x = 0;
	modulo[9].y = 0;
	modulo[9].w = 5;
	modulo[9].h = 5;
}