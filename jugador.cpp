
#include <iostream>
#include "jugador.h"
#include "ruleta.h"
using namespace std;

/**
* ****************************************************************************************
* Función: cargarJugadores
*
* Parámetros:
* - Jugador jugadores[] : Arreglo de estructuras Jugador donde se almacenarán los participantes.
* - int &cant           : Referencia a entero donde se guarda la cantidad total de jugadores ingresada.
*
* Retorna:
* - void : No retorna ningún valor.
*
* Descripción:
* Solicita por consola la cantidad de jugadores y valida que se encuentre
* entre 2 y 6 participantes. Luego pide el nombre de cada jugador e
* inicializa sus fichas en 2000, la cantidad de apuestas, victorias y
* derrotas en cero.
* ****************************************************************************************
*/

void cargarJugadores(Jugador jugadores[], int &cant){
    do{
		cout << "Cantidad de jugadores: ";
		cin >> cant;
		if(cant < 2 || cant > 6){
			cout << "La cantidad de jugadores debe estar entre 2 y 6" << endl;
		}
	} while(cant < 2 || cant >6);
	
    for(int i=0;i<cant;i++){
        cout << "Nombre jugador " << i+1 << ": ";
        cin >> jugadores[i].nombre;
        jugadores[i].fichas = 2000;
		jugadores[i].tlApuestas = 0;
		jugadores[i].victorias = 0;
		jugadores[i].derrotas = 0;
    }
}

/****************************************************
* Función: mostrarEstadoJugadores
* Parámetros:
* - Jugador jugadores[] : Arreglo con la información de los jugadores.
* - int cant : Cantidad de jugadores.
* Retorna:
* - void : No retorna ningun valor.
* Descripción:
* Muestra el saldo actual de fichas, victorias y derrotas de cada participante.
****************************************************/

void mostrarEstadoJugadores(Jugador jugadores[], int cant){
	cout << "==ESTADO DE JUGADORES==" << endl;
	
	for(int i=0; i < cant; i++){
		Jugador j = jugadores[i];
		cout << "Nombre: " << j.nombre << endl;
		cout << "Fichas: " << j.fichas << endl;
		cout << "Victorias: " << j.victorias << endl;
		cout << "Derrotas: " << j.derrotas << endl;
	}
}

/****************************************************
* Función: jugadorSinFichas
* Parámetros:
* - const Jugador jugadores[] : Arreglo de participantes.
* - int cant : Cantidad total de participantes.
* Retorna:
* - bool : true si algún jugador tiene 0 fichas, false si todos tienen saldo.
* Descripción:
* Evalúa si algún jugador agotó su pozo de fichas.
****************************************************/
bool jugadorSinFichas(Jugador jugadores[], int cant) {
	for (int i = 0; i < cant; i++) {
		if (jugadores[i].fichas <= 0) {
			cout << "El participante " << jugadores[i].nombre << " se quedo sin fichas" << endl;
			return true;
		}
	}
	return false;
}
	

/****************************************************
* Función: inicioSesion
* Parámetros:
* - Jugador jugadores[] : Arreglo de jugadores.
* - int &cant : Cantidad de jugadores.
* - Numero ruleta[37] : Arreglo que representa la ruleta.
* Retorna:
* - void : No retorna ningún valor.
* Descripción:
* Inicializa la ruleta y carga los jugadores de la sesión.
*****************************************************/	
void inicioSesion(Jugador jugadores[], int &cant, Numero ruleta[37]){
	inicializarRuleta(ruleta);
	cargarJugadores(jugadores, cant);
}
