#include "condicion.h"

/************************************************************
* Función: condicionfinal
* Parámetros:
* - Jugador jugadores[] : Arreglo de jugadores.
* - int cant : Cantidad de jugadores.
* Retorna:
* - bool : Retorna true si se cumple alguna condición de
*          finalización y false en caso contrario.
* Descripción:
* Verifica si la partida debe finalizar. Recorre todos los
* jugadores comprobando si alguno se quedó sin fichas.
* También verifica si se alcanzó el límite de 1200 giros
* y el estado de la variable seguirjugando.
* Si alguna de estas condiciones se cumple, retorna true;
* de lo contrario, retorna false.
*************************************************************/

bool condicionfinal(Jugador jugadores[], int cant, bool seguirjugando, int totalGiros){
	bool fin = false;
	for(int i=0;i<cant;i++) { 
		if(jugadores[i].fichas == 0){
			fin = true;
		}
	}
	if(totalGiros == 1200){
		fin = true;
	}
	if(!seguirjugando){
		fin = true;
	}
	return fin;
}
