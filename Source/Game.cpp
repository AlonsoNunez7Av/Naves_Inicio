#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Objeto.h"

CGame::CGame(){
	frames = 0;
	tiempoFrameInicio = 0;
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}
void CGame::Iniciando(){

	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %S ", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode ( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if (screen == NULL){
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip (screen); // este codigo estara provicionalmente aqui.
	SDL_WM_SetCaption( "Destruir!!..Eliminar!!", NULL);


	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/,MODULO_MINAVE_NAVE);
	menu = new Objeto (screen, "../Data/fondomenu.bmp",0,0,MODULO_MENU_FONDO);
	texto = new Objeto(screen, "../Data/Texto.bmp",0,0,-1);
	menu = new Objeto(screen, "../Data/fondo4.bmp", 0, 0, MODULO_MENU_FONDO);
	enemigoArreglo = new Nave*[20];
	for (int i =0; i < 10; i++)
	enemigoArreglo[i]= new Nave(screen, "../Data/enemigo.bmp",i*65,0,MODULO_ENEMIGO_NAVE);
	

	//enemigoParabola=-10.0f;
	
	for(int i = 0; i<10; i++)
		enemigoArreglo[i] -> GetNaveObjeto()->SetStep(4);

	menuSeleccion = MODULO_TEXTO_OPCION1;
	///
	//nave->CargarImagen("../Data/MiNave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
////void CGame::Finalize(){
////	SDL_Quit();
////}
void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
			case Estado::ESTADO_INICIANDO: //INICIALIZAR
				//switch(estado){
				InicializandoStage();
				Iniciando();
				//estado=ESTADO_MENU;
				estado= ESTADO_PRE_JUGANDO;
				break;
			/*	nave = SDL_LoadBMP("../Data/MiNave.bmp");
				SDL_Rect Fuente;
				Fuente.x =90;
				Fuente.y =152;
				Fuente.w =242;
				Fuente.h =76;
				SDL_Rect destino;
				destino.x =100;
				destino.y =100;
				destino.w =100;
				destino.h =100;
				SDL_BlitSurface(nave, &Fuente, screen, &destino);
				SDL_BlitSurface(nave, NULL, screen, NULL);
				SDL_FreeSurface(nave);
*/
				
			case Estado::ESTADO_MENU:
				menu->Pintar();
				texto->Pintar(MODULO_TEXTO_TITULO,150,30);
				texto->Pintar(MODULO_TEXTO_NOMBRE,200,400);
				Menu();
				estado = ESTADO_INICIANDO;
			break;
			case Estado::ESTADO_PRE_JUGANDO:
				nivelActual = 0;

			case Estado::ESTADO_JUGANDO://JUGAR	
				//MENU
				//nave->PintarModulo (0,0,0,64,64);
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);
			menu->Pintar();

			for (int i =0; i < 10; i++)
			enemigoArreglo[i]->GetNaveObjeto() -> Actualizar();
			MoverEnemigo();

			if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_DERECHO)){
			//nave->PintarModulo(0,100,100);
				nave->MoverDerecha(niveles[nivelActual].veocidadPropia);
			
			///Iniciando();
				///estado=ESTADO_MENU;
			}
			
			if(keys[SDLK_z]){
				nave->Disparar(NAVE_PROPIA, niveles[nivelActual].limiteBalasPropias);
				//nave->Actualizar();
			}
			
			if(keys[SDLK_LEFT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_IZQUIERDO)){
				nave->MoverIzquierda(niveles[nivelActual].veocidadPropia);
			}
			if(keys[SDLK_UP]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_SUPERIOR)){
				nave->MoverArriba(niveles[nivelActual].veocidadPropia);
			}
			if(keys[SDLK_DOWN]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_INFERIOR)){
				nave->MoverAbajo(niveles[nivelActual].veocidadPropia);
			}
			nave->Pintar();
			nave->Actualizar(NAVE_PROPIA, niveles[nivelActual].velocidadBalasPropias);
			
			for (int i =0; i < 10; i++){
			enemigoArreglo[i] -> Pintar();
			enemigoArreglo[i]->AutoDisparar(NAVE_ENEMIGO,niveles[nivelActual].velocidadBalasEnemigo);
			enemigoArreglo[i]->Actualizar(NAVE_ENEMIGO, niveles[nivelActual].velocidadBalasEnemigo);
		}
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR
			break;
			case Estado::ESTADO_FINALIZADO: //SALIR
				salirJuego = true;
			break;
		};
				while (SDL_PollEvent(&event))//aqui SDL creara una lista de eventos ocurr
				{
					if (event.type == SDL_QUIT){salirJuego =true;}//si se detecta una
						if (event.type == SDL_KEYDOWN){}
				}
		SDL_Flip(screen); //imprime en pantalla variable screen

		frames++;
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal < (tiempoFrameInicio + FPS_DELAY)){
			tiempoFrameFinal = SDL_GetTicks();
		SDL_Delay(1);
	}

		printf("Frame:%d Tiempo:%d TiempoPorFrame:%d FPS:%f\n", frames,tiempoFrameInicio,tiempoFrameFinal-tiempoFrameInicio,1000.0f / (float)(tiempoFrameFinal-tiempoFrameInicio));
		tiempoFrameInicio = tiempoFrameFinal;
    }
	return true;
}

bool CGame::esLimitePantalla(Objeto *objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO)
		if (objeto->obtenerX() <=0)
			return true;
	if(bandera & BORDE_SUPERIOR)
		if (objeto->obtenerY() <=0)
			return true;
	if(bandera & BORDE_DERECHO)
		if (objeto->obtenerX() >=(WIDTH_SCREEN-objeto->obtenerW()))
			return true;
	if(bandera & BORDE_INFERIOR)
		if (objeto->obtenerY() >=(HEIGHT_SCREEN-objeto->obtenerH()))
			return true;
	return false;
}


void CGame::MoverEnemigo(){
	//if(!esLimitePantalla(enemigo, BORDE_DERECHO))
	//enemigo->MoverDerecha(1);
	
					
				
	//enemigo->ponerEn(enemigoParabola*enemigoParabola,enemigoParabola);
	//enemigoParabola+=0.1f;
	for (int i= 0; i<10; i++)
	switch(enemigoArreglo[i]->GetNaveObjeto()-> ObtenerStepActual()){
				case 0:
					
					if(!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
						enemigoArreglo[i]->GetNaveObjeto()->Mover(niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());
					
					if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_DERECHO))
						enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();

						//enemigo->IncrementarStep();
					//enemigo->Mover(1,50);

					break;
				case 1:
					enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
					break;
				case 2:
					if(!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
						enemigoArreglo[i]->GetNaveObjeto()->Mover(-niveles[nivelActual].velocidadEnemigo, WIDTH_SCREEN - enemigoArreglo[i]->GetNaveObjeto()->obtenerW());

					if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_IZQUIERDO))
						enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();
					
					break;
				case 3:
					enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
					break;
				}

}

void CGame::Menu(){
	for(int i = MODULO_TEXTO_OPCION1, j=0; i<= MODULO_TEXTO_OPCION2; i++,j++){
		if(i==menuSeleccion)
		texto->Pintar(i+MENU_NUMERO_ELEMENTOS,150,130+(j*50));
		else
			texto->Pintar(i,150,130+(j*50));

}
}