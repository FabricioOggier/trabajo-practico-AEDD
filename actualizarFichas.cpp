#include <iostream>
#include "actualizarFichas.h"
using namespace std;

/****************************************************
* Función: escrutinio
* Parámetros:
* - Jugador jugadores[] : Arreglo de jugadores.
* - int cant : Cantidad de jugadores.
* - Numero resultado : Casilla resultante del giro.
* Retorna:
* - void : No retorna ningun valor.
* Descripción:
* Evalúa las apuestas contra el resultado obtenido y actualiza saldos aplicando las tasas de pago. Modifica las fichas, victorias y derrotas de los jugadores.
****************************************************/

void escrutinio(Jugador jugadores[], int cant, Numero resultado){
	int valor = obtenerValor(resultado);
	int color = obtenerColor(resultado);
	int paridad = obtenerParidad(resultado);
	
	for(int i=0; i < cant; i++){
		Jugador jugador = jugadores[i];
		Apuesta apuesta = jugador.apuestas[jugador.tlApuestas];
		int tipoApuesta = apuesta.tipoApuesta;
		
		switch(tipoApuesta){
		case 1:
			if(apuesta.numeroApostado == valor){
				jugador.fichas += apuesta.fichasJugadas * 36;
				jugador.victorias++;
			}else{
				jugador.fichas -= apuesta.fichasJugadas;
				jugador.derrotas++;
			}
			break;
			
		case 2:
			if(apuesta.colorApostado == color){
				jugador.fichas += apuesta.fichasJugadas;
				jugador.victorias++;
			}else{
				jugador.fichas -= apuesta.fichasJugadas;
				jugador.derrotas++;
			}
			break;
			
		case 3:
			if(paridad == 1){
				jugador.fichas += apuesta.fichasJugadas;
				jugador.victorias++;
			}else{
				jugador.fichas -= apuesta.fichasJugadas;
				jugador.derrotas++;
			}
			break;
			
		case 4:
			if(paridad == 2){
				jugador.fichas += apuesta.fichasJugadas;
				jugador.victorias++;
			}else{
				jugador.fichas -= apuesta.fichasJugadas;
				jugador.derrotas++;
			}
			break;
		}
	}
}
	
	
