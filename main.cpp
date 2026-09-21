
#include <iostream>
#include "numero.h"
#include "ruleta.h"
#include "jugador.h"

using namespace std;

int main() {

    Presentacion();
	char eleccion;
	bool condicion=false;
	do{
        Selector();
		cin>>eleccion;
		switch (eleccion){
		case '1':
			if(!condicion){
				inicioSesion();
				condicion=true;
			}
			else{
				cout<<"Ya se ha iniciado sesión"<<endl;
			}
			break;
		case '2':
			if(condicion){
				EstadoJugadores();
			}
			else{
				cout<<"Debes iniciar sesión para acceder a esta función"<<endl;
			}
			break;
		case '3':
		   if(condicion){
			   HistorialGiros();
		   }
		   else{
			   cout<<"Debes iniciar sesión para acceder a esta función"<<endl;
		   }
		   break;
		case '4':
			if(condicion){
				Estadisticas();
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
