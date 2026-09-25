#include "numero.h"
#include "presentacion.h"

/**
* ****************************************************************************************
* Función: guardarGiro
*
* Parámetros:
* - Numero numero[]: Pasaje por referncia al vector numeros.
* - Numero nuevo: Copia del numero al cual guardar en el vector.
* - int pos: Valor numerico de la posision en la que se coloca el numero nuevo.
*
* Retorna:
* - void : No retorna ningun valor.
*
* Descripción:
* Guarda los valores que salieron en el ultimo giro.
* ****************************************************************************************
*/
void guardarGiro(Numero numeros[], Numero nuevo, int pos){
	numeros[pos]=nuevo;
}
/**
* ****************************************************************************************
* Función: mostralHistorial
*
* Parámetros:
* - Numero numeros[]: Pasaje por referncia al vector numeros.
* - int totalGiros: Valor numerico que refiere a la cantidad de giros totales.
*
* Retorna:
* - void : No retorna ningun valor.
*
* Descripción:
* Muestra en pantalla la secuencia numeros ganadores en orden.
* ****************************************************************************************
*/
void mostralHistorial(Numero numeros[],int totalGiros){
	color(15);
	cout<<centrar("Historial de giros",207);
	cout<<endl;
	borde(8);
	colorNormal();
	
	cout<<centrar ("Numero de giro", 51);
	cout<<centrar ("Valor", 51);
	cout<<centrar ("color", 51);
	cout<<centrar ("paridad", 51);
	cout<<endl;
	for(int i=0;i<totalGiros;i++) { 
		string valor= to_string(obtenerValor(numeros[i]));
		char colorN=obtenerColor(numeros[i]);
		int paridad=obtenerParidad(numeros[i]);
		cout<<centrar (to_string(i+1), 51);
		cout<<centrar (valor, 51);
		
		if(colorN=='V'){
			color(2);
			cout<<centrar ("Verde", 51);
			colorNormal();
		}
		else if(colorN=='N'){
			color(15);
			cout<<centrar ("Negro", 51);
			colorNormal();
		}
		else{
			color(4);
			cout<<centrar ("Rojo", 51);
			colorNormal();
		}
		
		if(paridad==0){
			cout<<centrar("No par, no impar", 51);
		}
		else if(paridad==1){
			cout<<centrar("Par", 51);
		}
		else{
			cout<<centrar("Impar", 51);
		}
		cout<<endl;
	}
}
