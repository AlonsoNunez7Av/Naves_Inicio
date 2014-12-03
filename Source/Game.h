
#include <SDL.h>
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"
#include "Stage.h"
class CGame 
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();  
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_PRE_JUGANDO,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO,
		};

private:

	void InicializandoStage();
	void Iniciando();
	void MoverEnemigo();
	bool esLimitePantalla(Objeto *objeto, int bandera);
	
	
	void Menu();
	int nivelActual;
	int enemigosEliminados;
	int menuSeleccion;

	Uint8 *keys;
	SDL_Event event;

	SDL_Surface *screen;
	Nave *nave;
	Nave **enemigoArreglo;

	Stage niveles[4];


	Objeto *titulo; // Titulo del juego
	Objeto *menu; // Menu del juego
	Objeto *texto; // Textos del juego
	Objeto *fondo; // Fondos del juego


	Estado estado;

	float enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;
};