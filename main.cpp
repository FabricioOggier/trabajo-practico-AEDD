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
	colorNormal();
	mostrarCursor();
	cin.get();
	limpiarPantalla();
	
	char eleccion;
	bool condicion=false;
	do{
		//Selector();
		cin>>eleccion;
		switch (eleccion){
		case '1':
			if(!condicion){
				//inicioSesion();
				condicion=true;
			}
			else{
				cout<<"Ya se ha iniciado sesión"<<endl;
			}
			break;
		case '2':
			if(condicion){
				//estadoJugadores();
			}
			else{
				cout<<"Debes iniciar sesión para acceder a esta función"<<endl;
			}
			break;
		case '3':
			if(condicion){
				//historialGiros();
			}
			else{
				cout<<"Debes iniciar sesión para acceder a esta función"<<endl;
			}
			break;
		case '4':
			if(condicion){
				//estadisticas();
			}
			else{
				cout<<"Debes iniciar sesión para acceder a esta función"<<endl;
			}
			break;
		case '5':
		case '6':
		case '7':
			cout<<"Funcionalidad en Desarrollo"<<endl;
			break;
		case 'X':
		case 'x':
			break;
		default:
			cout<<"Función desconocida"<<endl;
		};
		
		
	}while(eleccion!='x' and eleccion!='X') ;
	
	
	return 0;
}
