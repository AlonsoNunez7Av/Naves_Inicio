#include "Objeto.h"
#include "Config.h"

Objeto::Objeto(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
	moduleUsing = module;
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w=sprite->WidthModule(moduleUsing);
	h=sprite->HeightModule(moduleUsing);

	this->x=x; 
	this->y=y; 
	stepsActual=0;
	posicionBrinco=0;
	posicionActual=0;
	isVisible = true;
}
Objeto::~Objeto(){
	delete sprite;
}
void Objeto::Pintar(){
	if(isVisible)
	sprite->PintarModulo(moduleUsing,x,y);
}

void Objeto::Pintar(int module, int x, int y){
	if (isVisible)
	sprite->PintarModulo(module,x,y);
}

void Objeto::MoverDerecha(int posicion){
	x += posicion;
}
void Objeto:: MoverIzquierda(int posicion){
	x -= posicion;
}
void Objeto::MoverArriba(int posicion){
	y -= posicion;
}
void Objeto:: MoverAbajo(int posicion){
	y += posicion;
}
int Objeto::obtenerX(){
	return x;
}
int Objeto::obtenerY(){
	return y;
}
int Objeto::obtenerW(){
	return w;
}
int Objeto::obtenerH(){
	return h;
}

void Objeto::ponerEn(int x, int y){
	this->x=x;
	this->y=y;

}

void Objeto::Mover(int brinco, int puntoFinal){
	if (posicionBrinco<=0){
	posicionBrinco=brinco;
	posicionFinal=puntoFinal;
	}
}

void Objeto::Actualizar(){
	if(posicionBrinco!=0){
		if(posicionActual <=posicionFinal){
		MoverDerecha(posicionBrinco);
		posicionActual++;
	}else{
			TerminarAnimacion();
	}
	}

}


void Objeto::SetStep(int stepsFinal){
	this->stepsFinal = stepsFinal;
}

void Objeto::IncrementarStep(){
	stepsActual++;
	if(stepsActual >= stepsFinal)
		stepsActual=0;
}

int Objeto:: ObtenerStepActual(){
	return stepsActual;
}
	bool Objeto::IsRunningAnimacion(){
		if(posicionBrinco==0)
			return false;
		else
			return true;
	}

	void Objeto:: TerminarAnimacion(){
		posicionBrinco = 0;
		posicionActual = 0;
		posicionFinal = 0;
		IncrementarStep();
	}

	void Objeto::SetVisible(bool isVisible){
		this->isVisible = isVisible;

	}