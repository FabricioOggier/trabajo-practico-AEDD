#include <stdlib.h>
#include <windows.h>

#include <iostream>
#include "numero.h"
#include "ruleta.h"
#include "jugador.h"
#include "presentacion.h"

using namespace std;

int main() {
	//Presentacion
	pantallaCompleta();
	ocultarCursor();
	tamanioVentana(207, 55);
	Presentacion();
	cout<<endl<<centrar("Presione ENTER para continuar...", 207 + 2);
	mostrarCursor();
	cin.get();
	limpiarPantalla();
	
	//Variables
	int cant = 0;
	Jugador jugadores[6];
	Numero ruleta[37];
	char eleccion;
	bool condicion=false;
	Numero registroNumeros[1200];
	int giros = 0;
	do{
		Selector(condicion);
		cin>>eleccion;
		limpiarPantalla();
		
		switch (eleccion){
		case '1':
			if(!condicion){
				inicioSesion(jugadores,cant, ruleta);
				condicion=true;
				limpiarPantalla();
				ejecutarCicloPartidas(ruleta, jugadores, cant, registroNumeros, giros);
			}
			else{
				Mensaje("Ya se ha iniciado sesion");
			}
			break;
		case '2':
			if(condicion){
				mostrarEstadoJugadores(jugadores, cant);
				cin.ignore();
				cin.get();
			}
			else{
				Mensaje("Debes iniciar sesion para acceder a esta funcion");
			}
			break;
		case '3':
			if(condicion){
				mostrarHistorial(registroNumeros,giros);
				cin.ignore();
				cin.get();
			}
			else{
				Mensaje("Debes iniciar sesion para acceder a esta funcion");
			}
			break;
		case '4':
			if(condicion){
				mostrarEstadisticas(registroNumeros,giros);
				cin.ignore();
				cin.get();
			}
			else{
				Mensaje("Debes iniciar sesion para acceder a esta funcion");
			}
			break;
		case '5':
		case '6':
		case '7':
			Mensaje("Funcionalidad en Desarrollo");
			break;
		case 'X':
		case 'x':
			cout<<centrar("¿Estas seguro de que quieres salir?",207)<<endl;
			cout<<centrar("Escribe para confirmar:",207);
			cin>>eleccion;
			break;
		default:
			Mensaje("Funcion desconocida");
		};
		
		limpiarPantalla();
		
	}while(eleccion!='x' and eleccion!='X') ;
	
	Despedida();
	
	return 0;
}
