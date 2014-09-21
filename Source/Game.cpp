#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	int estado = 0; ///ACT2: Aqui debes de iniciar tu estado, con el nuevo estado inicial. Esto que tienes no es correcto.
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
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
    }
	return true;
}
