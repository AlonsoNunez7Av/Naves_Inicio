#include "Game.h"
void CGame::InicializandoStage(){

	niveles[0].nivel = 0;
	niveles[0].cantidadEnemigosAEliminar = 10;
	niveles[0].canitidadEnemigosEnPantalla = 1;
	niveles[0].efectividadEnemigo = 4;
	niveles[0].limiteBalasPropias = 500;
	niveles[0].velocidadBalasEnemigo = 5;
	niveles[0].velocidadBalasPropias = 5;
	niveles[0].velocidadEnemigo = 10;
	niveles[0].velocidadBalasPropias = 10;
	niveles[0].veocidadPropia = 10;

	niveles[1].nivel = 1;
	niveles[1].cantidadEnemigosAEliminar = 20;
	niveles[1].canitidadEnemigosEnPantalla = 2;
	niveles[1].efectividadEnemigo = 5;
	niveles[1].limiteBalasPropias = 400;
	niveles[1].velocidadBalasEnemigo = 7;
	niveles[1].velocidadBalasPropias = 6;
	niveles[1].velocidadEnemigo = 15;
	niveles[1].velocidadBalasPropias = 12;
	niveles[0].veocidadPropia = 10;
	
}