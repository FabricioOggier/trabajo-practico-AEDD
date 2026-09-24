#include <iostream>
#include <iomanip>
using namespace std;

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
	
	
