
#include <cstdlib>
#include <ctime>
#include "ruleta.h"

/**
* ****************************************************************************************
* Función: inicializarRuleta
*
* Parámetros:
* - Numero ruleta[37] : Arreglo de 37 elementos de tipo Numero que representa las casillas de la ruleta.
*
* Retorna:
* - void : No retorna ningún valor.
*
* Descripción:
* Configura cada casilla de la ruleta asignándole su número (0 al 36) y su color correspondiente
* ('V' para verde, 'R' para rojo, 'N' para negro) mediante inicializarNumero. Además, inicializa
* el generador de números aleatorios (srand).
* ****************************************************************************************
*/

void inicializarRuleta(Numero ruleta[37]){
    char colores[37] = {'V','R','N','R','N','R','N','R','N','R','N','N','R','N','R','N','R','N','R','R','N','R','N','R','N','R','N','R','N','N','R','N','R','N','R','N','R'};

    for(int i=0;i<37;i++){
        inicializarNumero(ruleta[i], i, colores[i]);
    }

    srand(time(NULL));
}


/**
* ****************************************************************************************
* Función: girarRuleta
*
* Parámetros:
* - Numero ruleta[37] : Arreglo de 37 elementos de tipo Numero que contiene las casillas de la ruleta.
*
* Retorna:
* - Numero : El objeto Numero correspondiente a la casilla seleccionada de forma aleatoria.
*
* Descripción:
* Genera un índice aleatorio en el rango de 0 a 36 y retorna la casilla de la ruleta
* ubicada en dicha posición para simular el giro y resultado de la ruleta.
* ****************************************************************************************
*/

Numero girarRuleta(Numero ruleta[37]){
    int r = rand() % 37;
    return ruleta[r];
}
	
/****************************************************
* Función: escrutinio
*
* Parámetros:
* - Jugador jugadores[] : Arreglo de jugadores.
* - int cant : Cantidad de jugadores.
* - Numero resultado : Resultado del giro de la ruleta.
*
* Retorna:
* - void : No retorna ningún valor.
*
* Descripción:
* Evalúa la última apuesta de cada jugador según el resultado
* obtenido y actualiza sus fichas, victorias y derrotas.
*****************************************************/

void escrutinio(Jugador jugadores[], int cant, Numero resultado){
	int valor = obtenerValor(resultado);
	char color = obtenerColor(resultado);
	int paridad = obtenerParidad(resultado);
	
	for(int i=0; i < cant; i++){
		Apuesta apuesta = jugadores[i].apuestas[jugadores[i].tlApuestas - 1];
		int tipoApuesta = apuesta.tipoApuesta;
		
		switch(tipoApuesta){
		case 1:
			if(apuesta.numeroApostado == valor){
				jugadores[i].fichas += apuesta.fichasJugadas * 36;
				jugadores[i].victorias++;
			}else{
				jugadores[i].fichas -= apuesta.fichasJugadas;
				jugadores[i].derrotas++;
			}
			break;
			
		case 2:
			if(apuesta.colorApostado == color){
				jugadores[i].fichas += apuesta.fichasJugadas;
				jugadores[i].victorias++;
			}else{
				jugadores[i].fichas -= apuesta.fichasJugadas;
				jugadores[i].derrotas++;
			}
			break;
			
		case 3:
			if(paridad == 1){
				jugadores[i].fichas += apuesta.fichasJugadas;
				jugadores[i].victorias++;
			}else{
				jugadores[i].fichas -= apuesta.fichasJugadas;
				jugadores[i].derrotas++;
			}
			break;
			
		case 4:
			if(paridad == 2){
				jugadores[i].fichas += apuesta.fichasJugadas;
				jugadores[i].victorias++;
			}else{
				jugadores[i].fichas -= apuesta.fichasJugadas;
				jugadores[i].derrotas++;
			}
			break;
		}
	}
}
