#include "apuesta.h"
#include "jugador.h"
#include <iostream>
using namespace std;




void cargarApuestas(Jugador jugadores[], int cant){
	
	for(int i = 0; i < cant; i++) { 
		cout << "El apostador: " << jugadores[i].nombre << endl;
		cout << "Tiene " << jugadores[i].fichas << "fichas." << endl;
		int apuesta = 0;
		do{ 
			cout << "¿Cuantas fichas desea apostar?" << endl;
			cin >> apuesta;
		} while( apuesta <= 0 || apuesta > jugadores[i].fichas );
		
		jugadores[i].apuestas[jugadores[i].tlApuestas].fichasJugadas = apuesta;
		
		do {
		cout << "¿Que tipo de apuesta desea realizar?" << endl;
		cout << "1 - Numero" << endl;
		cout << "2 - Color" << endl;
		cout << "3 - Par" << endl;
		cout << "4 - Impar" << endl;
		
		cin >> jugadores[i].apuestas[jugadores[i].tlApuestas].tipoApuesta;
		
		switch(jugadores[i].apuestas[jugadores[i].tlApuestas].tipoApuesta) {
			
		case 1:
			cout << "Elegiste apostar a un numero" << endl;
			cout << "Selecciona un numero" << endl;
			cin >> jugadores[i].apuestas[jugadores[i].tlApuestas].numeroApostado;
			break;
			
		case 2:
			cout << "Elegiste apostar a un color" << endl;
			cout << "Selecciona un color" << endl;
			cin >> jugadores[i].apuestas[jugadores[i].tlApuestas].colorApostado;
			break;
			
		case 3:
			cout << "Elegiste apostar a par" << endl;
			break;
			
		case 4:
			cout << "Elegiste apostar a impar" << endl;
			break;
			
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
		}while (jugadores[i].apuestas[jugadores[i].tlApuestas].tipoApuesta < 1 || jugadores[i].apuestas[jugadores[i].tlApuestas].tipoApuesta > 4);
		
		jugadores[i].tlApuestas++;
		
		
	}
	
}

