#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);

	
	

	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);	

	}

	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	    	    
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
		case Estado::ESTADO_INICIANDO: //INICIALIZAR......Estamos arrancando con el juego 
		{
										   nave = SDL_LoadBMP("../Data/MiNave.bmp");//Busca la imagen en las carpetas del programa
										 //nave = IMG_LoadBMP_RW(SDL_RWFromFile("../Data/Tools.jpg", "rb")); //jala otra imagen
										   

										   SDL_Rect Fuente;  // esta sera la posicion de la imagen que queremos imprimir en pantalla
										   Fuente.x = 90;
										   Fuente.y = 152;
										   Fuente.w = 242;
										   Fuente.h = 76;

										   SDL_Rect destino; // aqui le desimos en que posicion queremos que imprima en pantalla
										   destino.x = 100;
										   destino.y = 100;
										   destino.w = 100;
										   destino.h = 100;

										   SDL_BlitSurface(nave, &Fuente, screen, &destino);//Pasar la imagen a la pantalla principal

										   SDL_BlitSurface(nave, NULL, screen, NULL);//Pasar la imagen a la pantalla principal

										   SDL_FreeSurface(nave); // Limpia la imagen si no la ocupamos
		}

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
		
		SDL_Flip(screen);// imprimir en pantalla la variable screen
		
    }
	return true;
}
