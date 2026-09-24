
#include <iostream>
#include "jugador.h"
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
* Solicita por consola la cantidad de jugadores a participar y, mediante un ciclo, pide el
* nombre de cada uno, asignándole a su vez un saldo inicial por defecto de 2000 fichas.
* ****************************************************************************************
*/

void cargarJugadores(Jugador jugadores[], int &cant){
    cout << "Cantidad de jugadores: ";
    cin >> cant;

    for(int i=0;i<cant;i++){
        cout << "Nombre jugador " << i+1 << ": ";
        cin >> jugadores[i].nombre;
        jugadores[i].fichas = 2000;
    }
}

/****************************************************
* Función: mostrarEstadoJugadores
* Parámetros:
* - const Jugador jugadores[] : Arreglo con la información de los jugadores.
* - int cant : Cantidad de jugadores.
* Retorna:
* - void : No retorna ningun valor.
* Descripción:
* Muestra el saldo actual de fichas, victorias y derrotas de cada participante.
****************************************************/

void mostrarEstadoJugadores(Jugador jugadores[], int cant){
	cout << "==ESTADO DE JUGADRES==" << endl;
	
	for(int i=0; i < cant; i++){
		Jugador j = jugadores[i];
		cout << "Nombre: " << j.nombre << endl;
		cout << "Fichas: " << j.fichas << endl;
		cout << "Victorias: " << j.victorias << endl;
		cout << "Derrotas: " << j.derrotas << endl;
	}
}
