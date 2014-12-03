#ifndef __OBJETO_H__
#define __OBJETO_H__
#include "Sprite.h"

class Objeto{

int x;
int y;
int w;
int h;
int posicionActual;
int posicionFinal;
int posicionBrinco;
int stepsActual;
int stepsFinal;
int moduleUsing; //Modulo en uso

Sprite * sprite;
bool isVisible;
public:

	void SetVisible(bool isVisible);
	Objeto(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	~Objeto();

	void Pintar();
	void Pintar(int module, int x, int y);
	void MoverDerecha(int posicion);
	void MoverArriba(int posicion);
	void MoverAbajo(int posicion);
	void Mover(int brinco, int puntoFinal);
	void SetStep(int stepsFinal);
	void IncrementarStep();
	int ObtenerStepActual();
	void Actualizar();
	bool IsRunningAnimacion();
	void TerminarAnimacion(); // Fuerza para terminar la STEP actual de la nave
	void MoverIzquierda(int posicion);

	int obtenerX();
	int obtenerY();
	int obtenerW();
	int obtenerH();
	void ponerEn(int x , int y);
};

#endif