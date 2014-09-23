#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>

CGame::CGame(){
	
	estado = ESTADO_INICIANDO; 
	SDL_Surface * screen;
	atexit(SDL_Quit);

	if (SDL_Init(SDL_INIT_VIDEO)<0){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);	

		screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	}
	    	    
	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE); 
	}
	    SDL_Flip(screen);
	    SDL_WM_SetCaption("Mi primer Juego", NULL);
	
}
        

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){

		//Maquina de estados       
		switch (estado){
	case Estado::ESTADO_INICIANDO: //INICIALIZAR
		break;

	case Estado::ESTADO_MENU:	//JUGAR	
		break;

	case Estado::ESTADO_JUGANDO:	//JUGAR	
		break;

	case Estado::ESTADO_TERMINANDO:	//JUGAR	
		break;

	case Estado::ESTADO_FINALIZANDO: //SALIR
		break;

		salirJuego = true;
		break;

		};
		SDL_Flip(screen);
		
    }
	return true;
}
