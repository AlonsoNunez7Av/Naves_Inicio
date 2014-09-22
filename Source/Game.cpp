#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame()

{
	int estado = 0; 
	
	///ACT2:Mal, Debes de poner que estado sera el inicial, no debiste mover el motor de estados, ese estaba bien en su lugar, dentro del While, para que siempre
	//Se este ejecutando. Pero es necesario que el juego le indiques que estado sera el primero en ejecutarse. 
	//El int estado = 0; No debe de llevar el int.
	//Dejalo como esta y solo compone lo de la parte de arriba "int estado = 0;"

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

		
	};
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
        
		salirJuego = true;
		break;
		
    }
	return true;
}
