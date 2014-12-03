#include "Nave.h"
#include "Config.h"
void Nave::Pintar(){
	nave->Pintar();

}

Nave ::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
nave = new Objeto (screen, rutaImagen, x, y, module);
bala = new Objeto*[MAXIMO_BALAS];
for(int i=0; i<MAXIMO_BALAS; i++){
bala [i]= new Objeto(screen, "../Data/balas.bmp", 0,0, MODULO_BALAS_BALA1);
bala[i]-> SetVisible(false);

}
balasVisibles = 0;
}

void Nave:: MoverIzquierda(int valor){
	nave->MoverIzquierda(valor);

}
	void Nave:: MoverDerecha(int valor){
		nave->MoverDerecha(valor);

}

	void Nave:: MoverArriba(int valor){
		nave->MoverArriba(valor);
}
	void Nave::MoverAbajo(int valor){
		nave->MoverAbajo(valor);

}

	Objeto * Nave::GetNaveObjeto(){
		return nave;
	}

	void Nave:: Disparar(int tipo, int valor){
		
		bala[balasVisibles]-> SetVisible(true);
		switch(tipo){
			case NAVE_PROPIA:
		bala[balasVisibles]->ponerEn(nave->obtenerX()+nave->obtenerW()/2,nave->obtenerY());
		break;
			case NAVE_ENEMIGO:
				bala[balasVisibles]->ponerEn(nave->obtenerX()+nave->obtenerW()/2,nave->obtenerY()+nave->obtenerH());
				break;
		}
		balasVisibles++;
		if (balasVisibles>=MAXIMO_BALAS)//maximo de balas por nivel
			balasVisibles = 0;
	}
	

	void Nave:: Actualizar(int tipo, int valor){
		for(int i=0; i<MAXIMO_BALAS; i++){
		bala[i]->Pintar();
		switch(tipo){
		case NAVE_PROPIA:
		bala[i]->MoverArriba(valor); ///CODIGO PARA MOVER ARRIBA
		break;
		case NAVE_ENEMIGO:
			bala[i]->MoverArriba(-valor); ///CODIGO PARA MOVER ABAJO
			break;
		}
	}
	}

	void Nave::AutoDisparar(int efectividad, int valor){
		if (rand() % 100<efectividad)
		Disparar(NAVE_ENEMIGO,valor);
	}