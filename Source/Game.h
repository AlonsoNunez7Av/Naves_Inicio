#include <SDL.h>
#include <SDL_image.h>
#include "Nave.h"




class CGame
{
public:

	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO,
	};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();


private:
	void Iniciando();
	void MoverEnemigo();
	bool esLimitePantalla(Nave*objeto, int bandera);
	
Uint8*keys;
SDL_Event event;
SDL_Surface *screen;
Nave  *nave;
Nave**enemigoArreglo;
Nave *menu;
Nave *titulo;
Nave *inicio;
Nave *salir;
Nave *fondo;
Nave *nombre;

	Estado estado;
	float  enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;

};