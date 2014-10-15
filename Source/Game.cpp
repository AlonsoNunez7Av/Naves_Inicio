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

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi primer Juego", NULL);
	nave = new Nave(screen, "../Data/minave.bmp");
	//nave->CargarImagen("../Data/minave.bmp");
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
			printf("\n1.Estado_Iniciado");
			break;

		case Estado::ESTADO_MENU:
			printf("\n2.Estado_Menu");			
			SDL_FillRect(screen, NULL, 0xFF0000);
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT]){
				nave->Mover(1);
			}
			if (keys[SDLK_LEFT]){
				nave->Mover(1);
			}
			nave->Pintar();
			estado = ESTADO_JUGANDO;
			break;

		case Estado::ESTADO_JUGANDO:
			printf("\n3.Estado_Jugando");
			estado = ESTADO_FINALIZADO;
			break;

		case Estado::ESTADO_FINALIZADO:
			printf("\n4.Estado_Finalizado");
			estado = ESTADO_TERMINANDO;
			break;
		case Estado::ESTADO_TERMINANDO:
			printf("\n5.Estado_Terminado");
			salirJuego = true;
			getchar();
			break;
		};
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT){ salirJuego = true; }
			if (event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen);// imprimir en pantalla la variable screen
	}
	return true;
}
