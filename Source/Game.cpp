
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Config.h"
#include "Sprite.h"

CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}
void CGame::Iniciando(){




	if (SDL_Init(SDL_INIT_AUDIO)){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);

	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGTH_SCREEN, 24, SDL_HWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi primer Juego", NULL);
	nave = new Nave (screen);
	//nave -> CargarImagen("../Data/minave.bmp");
}


void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	while (salirJuego == false)
	{

		//Maquina de estados
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO:

			Iniciando();
			estado = ESTADO_MENU;



			break;

			//{		
			//

			//								/*nave = SDL_LoadBMP("../Data/Eddie.bmp");

			//								 SDL_Rect Fuente;
			//								 Fuente.x = 90;
			//								 Fuente.y = 152;
			//								 Fuente.w = 242;
			//								 Fuente.h = 76;
			//								 SDL_Rect destino;
			//								 destino.x = 100;
			//								 destino.y = 100;
			//								 destino.w = 100;
			//								 destino.h = 100;

			//								 SDL_BlitSurface(nave, &Fuente, screen, &destino);

			//								 SDL_BlitSurface(nave, NULL, screen, NULL);

			//								 SDL_FreeSurface(nave);*/
			//}

		case Estado::ESTADO_MENU:

			SDL_FillRect(screen, NULL , 0x000000); //manda pintar la pantalla de color negro
		    
			keys = SDL_GetKeyState(NULL); // para obtener la lectura de las tecas
			if (keys[SDLK_DOWN]){ // tecla hacia abajo para que paraesca la imagen
				nave->Mover(1);

			}
				nave-> Pintar(); // posocion en la que se pintara la imagen

			
			break;
			

		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_FINALIZADO:
			break;
		case Estado::ESTADO_TERMINANDO:
			salirJuego = true;
			break;
		};
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT){ salirJuego = true; }
			if (event.type == SDL_KEYUP){}
		
			
		}
		SDL_Flip(screen);// imprimir en pantalla la variable screen
	}
	return true;
}

