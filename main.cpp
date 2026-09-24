#include <stdlib.h>
#include <windows.h>

#include <iostream>
#include "numero.h"
#include "ruleta.h"
#include "jugador.h"
#include "presentacion.h"

using namespace std;

int main() {
	
	pantallaCompleta();
	ocultarCursor();
	tamanioVentana(207, 30);
	Presentacion();
	
	
	cout<<endl<<centrar("Presione ENTER para continuar...", 207 + 2);
	
	mostrarCursor();
	cin.get();
	limpiarPantalla();
	
	char eleccion;
	bool condicion=false;
	do{
		Selector(condicion);
		cin>>eleccion;
		limpiarPantalla();
		
		switch (eleccion){
		case '1':
			if(!condicion){
				//inicioSesion();
				condicion=true;
			}
			else{
				Mensaje("Ya se ha iniciado sesion");
			}
			break;
		case '2':
			if(condicion){
				//estadoJugadores();
			}
			else{
				Mensaje("Debes iniciar sesion para acceder a esta funcion");
			}
			break;
		case '3':
			if(condicion){
				//historialGiros();
			}
			else{
				Mensaje("Debes iniciar sesion para acceder a esta funcion");
			}
			break;
		case '4':
			if(condicion){
				//estadisticas();
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
			break;
		default:
			Mensaje("Funcion desconocida");
		};
		
		
	}while(eleccion!='x' and eleccion!='X') ;
	
	Despedida();
	
	return 0;
}
