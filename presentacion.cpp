#define _WIN32_WINNT 0x0600
#include "presentacion.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
/**
* ****************************************************************************************
* Constante: colores

* Descripcion:
* Se utilizan para simplificar los cambios de color de caracteres y fondos
* ****************************************************************************************
*/
const int NEGRO         = 0;
const int AZUL          = 1;
const int VERDE         = 2;
const int AGUAMARINA    = 3;
const int ROJO          = 4;
const int PURPURA       = 5;
const int AMARILLO      = 6;
const int BLANCO        = 7;
const int GRIS          = 8;
const int AZUL_CLARO    = 9;
const int VERDE_CLARO   = 10;
const int CIAN_CLARO    = 11;
const int ROJO_CLARO    = 12;
const int MAGENTA       = 13;
const int AMARILLO_CLARO= 14;
const int BLANCO_BRILL  = 15;

/**
* ****************************************************************************************
* Constante: medidas

* Descripcion:
* Es el ancho configurado para la aplicacion. 
* Se utiliza tanto para centrar.
* ****************************************************************************************
*/
const int ANCHO = 207;

/**
* ****************************************************************************************
* Funcion: color
*
* Parametros:
* - int textoColor.
*
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Cambia el color de fuente a partir de la funcion, hasta que se vuelva a utilizar
* ****************************************************************************************
*/
void color(int textoColor) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consola, textoColor);
}

/**
* ****************************************************************************************
* Funcion: colorFondo
*
* Parametros:
* - int textoColor.
* - int fondoColor.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Cambia el color de fuente y el fondo a partir de la funcion, 
* hasta que se vuelva a utilizar
* ****************************************************************************************
*/
void colorFondo(int textoColor, int fondoColor) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consola, fondoColor * 16 + textoColor);
}

/**
* ****************************************************************************************
* Funcion: colorNormal
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Reestablece el color del texto y del fondo al predeterminado.
* ****************************************************************************************
*/
void colorNormal() {
	colorFondo(BLANCO, NEGRO);
}

/**
* ****************************************************************************************
* Funcion: tamanioVentana
*
* Parametros:
* - int columnas: El ancho al que se quiere cambiar.
* - int filas: El alto al que se quiere cambiar.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Ajusta el tamanio de la ventana para una mejor presentacion.
* ****************************************************************************************
*/
void tamanioVentana(int columnas, int filas) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Reduce la ventana al minimo para poder tocar el buffer
	SMALL_RECT minimo = {0, 0, 1, 1};
	SetConsoleWindowInfo(consola, TRUE, &minimo);
	
	// Ajusta el buffer 
	COORD buffer;
	buffer.X = columnas;
	buffer.Y = filas;
	SetConsoleScreenBufferSize(consola, buffer);
	
	//Agranda la ventana al tamanio necesitado
	SMALL_RECT ventana = {0, 0, (SHORT)(columnas - 1), (SHORT)(filas - 1)};
	SetConsoleWindowInfo(consola, TRUE, &ventana);
}

/**
* ****************************************************************************************
* Funcion: tamanioPixeles
*
* Parametros:
* - int ancho: El ancho al que se quiere cambiar.
* - int alto: El alto al que se quiere cambiar.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Cambia el tamanio de la ventana en pixeles y la centra
* ****************************************************************************************
*/
void tamanioPixeles(int ancho, int alto) {
	HWND ventana = GetConsoleWindow();
	int pantallaX = GetSystemMetrics(SM_CXSCREEN);
	int pantallaY = GetSystemMetrics(SM_CYSCREEN);
	int x = (pantallaX - ancho) / 2;
	int y = (pantallaY - alto) / 2;
	MoveWindow(ventana, x, y, ancho, alto, TRUE);
}
/**
* ****************************************************************************************
* Funcion: maximizar
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Maximiza la ventana de la consola
* ****************************************************************************************
*/
void maximizar() {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

/**
* ****************************************************************************************
* Funcion: pantallaCompleta
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Simula la combinacion ALT + ENTER.
* ****************************************************************************************
*/
void pantallaCompleta() {
	keybd_event(VK_MENU,   0, 0, 0);              // ALT abajo
	keybd_event(VK_RETURN, 0, 0, 0);              // ENTER abajo
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU,   0, KEYEVENTF_KEYUP, 0);
	Sleep(300);   // le damos tiempo a la consola a redibujarse
}

/**
* ****************************************************************************************
* Funcion: ocultarCursor
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Oculta el cursor parpadeante.
* ****************************************************************************************
*/
void ocultarCursor() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(consola, &cursor);
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(consola, &cursor);
}

/**
* ****************************************************************************************
* Funcion: mostrarCursor
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Vuelve a mostrar el cursor.
* ****************************************************************************************
*/
void mostrarCursor() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(consola, &cursor);
	cursor.bVisible = TRUE;
	SetConsoleCursorInfo(consola, &cursor);
}

/**
* ****************************************************************************************
* Funcion: esperar
*
* Parametros:
* - int milisegundos: Tiempo en milisegundos a esperar.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Espera la cantidad de milisegundos ingresada.
* ****************************************************************************************
*/
void esperar(int milisegundos) {
	Sleep(milisegundos);
}
/**
* ****************************************************************************************
* Funcion: limpiarPantalla
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Elimina todos los elementos en pantalla.
* ****************************************************************************************
*/
void limpiarPantalla() {
	system("cls");
}
/**
* ****************************************************************************************
* Funcion: centrar
*
* Parametros:
* - string texto: El texto a centrar.
* - int ancho: El espacio en el que se centra el texto
* Retorna:
* - string : Retorna el texto centrado.
* Descripcion:
* Se utiliza para centrar el texto en pantalla, para una mejor presentacion.
* ****************************************************************************************
*/
string centrar(string texto, int ancho) {
	int largo = texto.length();
	if (largo >= ancho) return texto;
	int izquierda = (ancho - largo) / 2;
	int derecha = ancho - largo - izquierda;
	return string(izquierda, ' ') + texto + string(derecha, ' ');
}

/**
* ****************************************************************************************
* Funcion: gotoxy
*
* Parametros:
* - int x: La columna a la cual mover el cursor.
* - int y: La fila a la cual mover el cursor.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Mueve el cursor a la columna x, fila y.
* ****************************************************************************************
*/
void gotoxy(int x, int y) {
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicion);
}

/**
* ****************************************************************************************
* Funcion: linea
*
* Parametros:
* - string texto: Texto que esta dentro del recuadro.
* - int colorTexto: Color del texto.
* - int colorMarco: Color del marco.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime una linea del marco, los bordes en un color y el texto en otro.
* ****************************************************************************************
*/
void linea(string texto, int colorTexto, int colorMarco) {
	color(colorMarco);   
	cout <<"|";
	color(colorTexto);   
	cout <<centrar(texto, ANCHO);
	color(colorMarco);   
	cout <<"|"<< endl;
}

/**
* ****************************************************************************************
* Funcion: borde
*
* Parametros:
* - int colorMarco: Color del marco.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime los bordes horizontales.
* ****************************************************************************************
*/
void borde(int colorMarco) {
	color(colorMarco);
	cout << "+" << string(ANCHO, '=') << "+" << endl;
}
/**
* ****************************************************************************************
* Funcion: presentacion
*
* Parametros:
* - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime la presentacion del programa.
* ****************************************************************************************
*/
void Presentacion(){
	borde(VERDE);
	linea("",BLANCO,VERDE);
	linea("",BLANCO,VERDE);
	linea("RRRR  U   U L     EEEE TTTTT EEEE  SSS    CCC      A     ",BLANCO_BRILL,VERDE);
	linea("R   R U   U L     E      T   E    S      C        A A    ",BLANCO_BRILL,VERDE);
	linea("RRRR  U   U L     EEEE   T   EEEE  SSS   C       A   A   ",BLANCO_BRILL,VERDE);
	linea("R  R  U   U L     E      T   E        S  C      AAAAAAA  ",BLANCO_BRILL,VERDE);
	linea("R   R  UUU  LLLLL EEEE   T   EEEE  SSS    CCC  A       A ",BLANCO_BRILL,VERDE);
	linea("",BLANCO,VERDE);
	linea("",BLANCO,VERDE);
	borde(VERDE);
	linea("",BLANCO,VERDE);
	linea("Desarrollado por Cian Federico, Oggier Fabricio y Peresin Lautaro",CIAN_CLARO,VERDE);
	linea("grupo: cout<< \" idea nombre\";",CIAN_CLARO,VERDE);
	linea("",BLANCO,VERDE);
	linea("",BLANCO,VERDE);
	linea("UTN FRSF",AZUL,VERDE);
	linea("Ingenieria en sistemas Comision B",AZUL,VERDE);
	linea("Algoritmos y Estructuras de Datos",AZUL,VERDE);
	linea("",BLANCO,VERDE);
	borde(VERDE);
}

/**
* ****************************************************************************************
* Funcion: Selector
*
* Parametros:
* - bool condicion: Condicion de acceso.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime el menu de seleccion de opciones.
* ****************************************************************************************
*/
void Selector(bool condicion){
	borde(GRIS);
	linea("",BLANCO,GRIS);
	linea("RULETESCA",BLANCO,GRIS);
	linea("",BLANCO,GRIS);
	borde(GRIS);
	if(!condicion){
		linea("1.- Iniciar nueva sesión de ruleta",CIAN_CLARO,GRIS);
		linea("2.- Consultar estado de jugadores",GRIS,GRIS);
		linea("3.- Mostrar historial de giros",GRIS,GRIS);
		linea("4.- Mostrar estadísticas de la sesion",GRIS,GRIS);
	}
	else{
		linea("1.- Iniciar nueva sesión de ruleta",GRIS,GRIS);
		linea("2.- Consultar estado de jugadores",CIAN_CLARO,GRIS);
		linea("3.- Mostrar historial de giros",CIAN_CLARO,GRIS);
		linea("4.- Mostrar estadísticas de la sesion",CIAN_CLARO,GRIS);
	}
	linea("5.- Ordenar sesiones segun cantidad de giros",GRIS,GRIS);
	linea("6.- Analizar sesiones historicas",GRIS,GRIS);
	linea("7.- Carga de Archivo",GRIS,GRIS);
	linea("X.- Salir de la aplicacion",ROJO,GRIS);
	linea("",BLANCO,GRIS);
	linea("Ingrese una opcion:",BLANCO_BRILL,GRIS);
	gotoxy(114,14);
}
	
/**
* ****************************************************************************************
* Funcion: Mensaje
*
* Parametros:
* - string texto: Texto a imprimir.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime el mensaje centrado, espera un enter y limpia la pantalla.
* ****************************************************************************************
*/
void Mensaje(string texto){
	texto=centrar(texto,ANCHO);
	color(BLANCO_BRILL);
	cout<<texto;
	cin.ignore();
	cin.get();
	limpiarPantalla();
	colorNormal();
}
	
/**
* ****************************************************************************************
* Funcion: Despedida
*
* Parametros:
*  - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime la despedida del programa.
* ****************************************************************************************
*/
	
void Despedida(){
	cout<<endl<<endl;
	color(VERDE);
	cout<<centrar("RRRR  U   U L     EEEE TTTTT EEEE  SSS    CCC      A     ",ANCHO)<<endl;
	cout<<centrar("R   R U   U L     E      T   E    S      C        A A    ",ANCHO)<<endl;
	cout<<centrar("RRRR  U   U L     EEEE   T   EEEE  SSS   C       A   A   ",ANCHO)<<endl;
	cout<<centrar("R  R  U   U L     E      T   E        S  C      AAAAAAA  ",ANCHO)<<endl;
	cout<<centrar("R   R  UUU  LLLLL EEEE   T   EEEE  SSS    CCC  A       A ",ANCHO)<<endl;
	cout<<endl<<endl;
	color(BLANCO_BRILL);
	cout<<centrar("Gracias por jugar :)",ANCHO);
	
}
	
/**
* ****************************************************************************************
* Funcion: generarRuleta
*
* Parametros:
*  - vacio, no lo requiere.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime la ruleta, para su uso en el programa.
* ****************************************************************************************
*/
void generarRuleta(){
	
	color(BLANCO_BRILL);
	cout<<centrar("######",ANCHO)<<endl;
	cout<<centrar("##############################",ANCHO)<<endl;
	cout<<centrar("#######                            #######",ANCHO)<<endl;
	cout<<centrar("#####                                        #####",ANCHO)<<endl;
	cout<<centrar("####                                                ####",ANCHO)<<endl;
	cout<<centrar("###                                                        ###",ANCHO)<<endl;
	cout<<centrar("####                                                            ####",ANCHO)<<endl;
	cout<<centrar("###                                                                  ###",ANCHO)<<endl;
	cout<<centrar("####                                                                      ####",ANCHO)<<endl;
	cout<<centrar("###                                                                          ###",ANCHO)<<endl;
	cout<<centrar("###                                                                              ###",ANCHO)<<endl;
	cout<<centrar("###                                                                                  ###",ANCHO)<<endl;
	cout<<centrar("###                                                                                    ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                          ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                            ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                              ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                  ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                                  ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                                    ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                                    ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                                      ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                                      ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("##                                                RULETESCA                                               ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                                      ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                                      ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                                    ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                                    ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                                  ###",ANCHO)<<endl;
	cout<<centrar("##                                                                                                  ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                                ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                              ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                            ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                          ##",ANCHO)<<endl;
	cout<<centrar("##                                                                                        ##",ANCHO)<<endl;
	cout<<centrar("###                                                                                    ###",ANCHO)<<endl;
	cout<<centrar("###                                                                                  ###",ANCHO)<<endl;
	cout<<centrar("###                                                                              ###",ANCHO)<<endl;
	cout<<centrar("###                                                                          ###",ANCHO)<<endl;
	cout<<centrar("####                                                                      ####",ANCHO)<<endl;
	cout<<centrar("###                                                                  ###",ANCHO)<<endl;
	cout<<centrar("####                                                            ####",ANCHO)<<endl;
	cout<<centrar("###                                                        ###",ANCHO)<<endl;
	cout<<centrar("####                                                ####",ANCHO)<<endl;
	cout<<centrar("#####                                        #####",ANCHO)<<endl;
	cout<<centrar("#######                            #######",ANCHO)<<endl;
	cout<<centrar("##############################",ANCHO)<<endl;
	cout<<centrar("######",ANCHO)<<endl;
	
	colorFondo(BLANCO_BRILL,VERDE_CLARO);
	gotoxy(103,4);
	cout<<"0";
	
	colorFondo(BLANCO_BRILL,ROJO);
	gotoxy(111, 5);
	cout<<"32";
	gotoxy(126, 8);
	cout<<"19";
	gotoxy(137, 12);
	cout<<"21";
	gotoxy(145, 19);
	cout<<"25";
	gotoxy(149, 27);
	cout<<"34";
	gotoxy(146, 35);
	cout<<"27";
	gotoxy(139, 41);
	cout<<"36";
	gotoxy(128, 46);
	cout<<"30";
	gotoxy(115, 49);
	cout<<"23";
	gotoxy(99, 50);
	cout<<"5";
	gotoxy(83, 48);
	cout<<"16";
	gotoxy(71, 44);
	cout<<"1";
	gotoxy(62, 39);
	cout<<"14";
	gotoxy(56, 31);
	cout<<"9";
	gotoxy(56, 23);
	cout<<"18";
	gotoxy(63, 15);
	cout<<"7";
	gotoxy(73, 9);
	cout<<"12";
	gotoxy(87, 6);
	cout<<"3";
	
	colorFondo(BLANCO_BRILL,NEGRO);
	gotoxy(119, 6);
	cout<<"15";
	gotoxy(132, 10);
	cout<<"4";
	gotoxy(142, 15);
	cout<<"2";
	gotoxy(148, 23);
	cout<<"17";
	gotoxy(148, 31);
	cout<<"6";
	gotoxy(143, 38);
	cout<<"13";
	gotoxy(133, 44);
	cout<<"11";
	gotoxy(123, 48);
	cout<<"8";
	gotoxy(107, 50);
	cout<<"10";
	gotoxy(91, 49);
	cout<<"24";
	gotoxy(76, 46);
	cout<<"33";
	gotoxy(66, 42);
	cout<<"20";
	gotoxy(58, 35);
	cout<<"31";
	gotoxy(55, 27);
	cout<<"22";
	gotoxy(58, 19);
	cout<<"29";
	gotoxy(67, 12);
	cout<<"28";
	gotoxy(79, 7);
	cout<<"35";
	gotoxy(95, 5);
	cout<<"26";	
	
}

/**
* ****************************************************************************************
* Funcion: bola
*
* Parametros:
*  - int ganador: El numero en el que finaliza el programa.
* Retorna:
* - void : No retorna ningun valor.
* Descripcion:
* Imprime la bola, y muestra el numero ganador.
* ****************************************************************************************
*/
void bola(int ganador){
	
	srand(time(0));
	int velocidad=100+rand()%100;
	bool condicion=true;
	color(BLANCO_BRILL);
	while(condicion){
		switch(velocidad%37){
		case 0:
			gotoxy(103, 5);   // 0
			cout<<"O";
			if(velocidad<38 and ganador==0){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(103, 5);
				cout<<" ";
			}
			break;
			
		case 1:
			gotoxy(111, 6);   // 32
			cout<<"O";
			if(velocidad<38 and ganador==32){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(111, 6);
				cout<<" ";
			}
			break;
			
		case 2:
			gotoxy(117, 7);   // 15
			cout<<"O";
			if(velocidad<38 and ganador==15){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(117, 7);
				cout<<" ";
			}
			break;
			
		case 3:
			gotoxy(124, 9);   // 19
			cout<<"O";
			if(velocidad<38 and ganador==19){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(124, 9);
				cout<<" ";
			}
			break;
			
		case 4:
			gotoxy(130, 11);   // 4
			cout<<"O";
			if(velocidad<38 and ganador==4){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(130, 11);
				cout<<" ";
			}
			break;
			
		case 5:
			gotoxy(135, 13);   // 21
			cout<<"O";
			if(velocidad<38 and ganador==21){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(135, 13);
				cout<<" ";
			}
			break;
			
		case 6:
			gotoxy(139, 16);   // 2
			cout<<"O";
			if(velocidad<38 and ganador==2){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(139, 16);
				cout<<" ";
			}
			break;
			
		case 7:
			gotoxy(143, 20);   // 25
			cout<<"O";
			if(velocidad<38 and ganador==25){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(143, 20);
				cout<<" ";
			}
			break;
			
		case 8:
			gotoxy(146, 23);   // 17
			cout<<"O";
			if(velocidad<38 and ganador==17){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(146, 23);
				cout<<" ";
			}
			break;
			
		case 9:
			gotoxy(147, 27);   // 34
			cout<<"O";
			if(velocidad<38 and ganador==34){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(147, 27);
				cout<<" ";
			}
			break;
			
		case 10:
			gotoxy(146, 30);   // 6
			cout<<"O";
			if(velocidad<38 and ganador==6){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(146, 30);
				cout<<" ";
			}
			break;
			
		case 11:
			gotoxy(144, 34);   // 27
			cout<<"O";
			if(velocidad<38 and ganador==27){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(144, 34);
				cout<<" ";
			}
			break;
			
		case 12:
			gotoxy(142, 38);   // 13
			cout<<"O";
			if(velocidad<38 and ganador==13){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(142, 38);
				cout<<" ";
			}
			break;
			
		case 13:
			gotoxy(137, 40);   // 36
			cout<<"O";
			if(velocidad<38 and ganador==36){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(137, 40);
				cout<<" ";
			}
			break;
			
		case 14:
			gotoxy(131, 43);   // 11
			cout<<"O";
			if(velocidad<38 and ganador==11){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(131, 43);
				cout<<" ";
			}
			break;
			
		case 15:
			gotoxy(127, 45);   // 30
			cout<<"O";
			if(velocidad<38 and ganador==30){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(127, 45);
				cout<<" ";
			}
			break;
			
		case 16:
			gotoxy(122, 47);   // 8
			cout<<"O";
			if(velocidad<38 and ganador==8){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(122, 47);
				cout<<" ";
			}
			break;
			
		case 17:
			gotoxy(115, 48);   // 23
			cout<<"O";
			if(velocidad<38 and ganador==23){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(115, 48);
				cout<<" ";
			}
			break;
			
		case 18:
			gotoxy(107, 49);   // 10
			cout<<"O";
			if(velocidad<38 and ganador==10){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(107, 49);
				cout<<" ";
			}
			break;
			
		case 19:
			gotoxy(99, 49);   // 5
			cout<<"O";
			if(velocidad<38 and ganador==5){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(99, 49);
				cout<<" ";
			}
			break;
			
		case 20:
			gotoxy(92, 48);   // 24
			cout<<"O";
			if(velocidad<38 and ganador==24){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(92, 48);
				cout<<" ";
			}
			break;
			
		case 21:
			gotoxy(84, 47);   // 16
			cout<<"O";
			if(velocidad<38 and ganador==16){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(84, 47);
				cout<<" ";
			}
			break;
			
		case 22:
			gotoxy(77, 45);   // 33
			cout<<"O";
			if(velocidad<38 and ganador==33){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(77, 45);
				cout<<" ";
			}
			break;
			
		case 23:
			gotoxy(72, 43);   // 1
			cout<<"O";
			if(velocidad<38 and ganador==1){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(72, 43);
				cout<<" ";
			}
			break;
			
		case 24:
			gotoxy(67, 41);   // 20
			cout<<"O";
			if(velocidad<38 and ganador==20){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(67, 41);
				cout<<" ";
			}
			break;
			
		case 25:
			gotoxy(64, 38);   // 14
			cout<<"O";
			if(velocidad<38 and ganador==14){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(64, 38);
				cout<<" ";
			}
			break;
			
		case 26:
			gotoxy(60, 34);   // 31
			cout<<"O";
			if(velocidad<38 and ganador==31){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(60, 34);
				cout<<" ";
			}
			break;
			
		case 27:
			gotoxy(58, 31);   // 9
			cout<<"O";
			if(velocidad<38 and ganador==9){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(58, 31);
				cout<<" ";
			}
			break;
			
		case 28:
			gotoxy(58, 27);   // 22
			cout<<"O";
			if(velocidad<38 and ganador==22){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(58, 27);
				cout<<" ";
			}
			break;
			
		case 29:
			gotoxy(59, 23);   // 18
			cout<<"O";
			if(velocidad<38 and ganador==18){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(59, 23);
				cout<<" ";
			}
			break;
			
		case 30:
			gotoxy(60, 20);   // 29
			cout<<"O";
			if(velocidad<38 and ganador==29){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(60, 20);
				cout<<" ";
			}
			break;
			
		case 31:
			gotoxy(65, 16);   // 7
			cout<<"O";
			if(velocidad<38 and ganador==7){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(65, 16);
				cout<<" ";
			}
			break;
			
		case 32:
			gotoxy(69, 13);   // 28
			cout<<"O";
			if(velocidad<38 and ganador==28){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(69, 13);
				cout<<" ";
			}
			break;
			
		case 33:
			gotoxy(75, 10);   // 12
			cout<<"O";
			if(velocidad<38 and ganador==12){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(75, 10);
				cout<<" ";
			}
			break;
			
		case 34:
			gotoxy(81, 8);   // 35
			cout<<"O";
			if(velocidad<38 and ganador==35){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(81, 8);
				cout<<" ";
			}
			break;
			
		case 35:
			gotoxy(88, 7);   // 3
			cout<<"O";
			if(velocidad<38 and ganador==3){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(88, 7);
				cout<<" ";
			}
			break;
			
		case 36:
			gotoxy(96, 6);   // 26
			cout<<"O";
			if(velocidad<38 and ganador==26){
				condicion=false;
			}
			else{
				esperar(1000/velocidad);
				gotoxy(96, 6);
				cout<<" ";
			}
			break;
		}
		velocidad--;
	}
	esperar(1000);
}
