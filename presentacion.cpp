#define _WIN32_WINNT 0x0600
#include "presentacion.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
//Colores
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

//Medidas
const int ANCHO = 207;

// COLORES

// Cambia el color del texto que se imprima de ahora en adelante.
void color(int textoColor) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consola, textoColor);
}
// Cambia color de texto y de fondo al mismo tiempo.
void colorFondo(int textoColor, int fondoColor) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consola, fondoColor * 16 + textoColor);
}
// Vuelve al color normal (texto blanco sobre fondo negro).
void colorNormal() {
	colorFondo(BLANCO, NEGRO);
}

//FUNCIONES DE VENTANA
void tamanioVentana(int columnas, int filas) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// 1) Achicamos la ventana al minimo para poder tocar el buffer
	SMALL_RECT minimo = {0, 0, 1, 1};
	SetConsoleWindowInfo(consola, TRUE, &minimo);
	
	// 2) Ajustamos el buffer (el "papel" donde se escribe)
	COORD buffer;
	buffer.X = columnas;
	buffer.Y = filas;
	SetConsoleScreenBufferSize(consola, buffer);
	
	// 3) Agrandamos la ventana al tamanio pedido
	SMALL_RECT ventana = {0, 0, (SHORT)(columnas - 1), (SHORT)(filas - 1)};
	SetConsoleWindowInfo(consola, TRUE, &ventana);
}

// Cambia el tamanio de la ventana en pixeles y la centra.
void tamanioPixeles(int ancho, int alto) {
	HWND ventana = GetConsoleWindow();
	int pantallaX = GetSystemMetrics(SM_CXSCREEN);
	int pantallaY = GetSystemMetrics(SM_CYSCREEN);
	int x = (pantallaX - ancho) / 2;
	int y = (pantallaY - alto) / 2;
	MoveWindow(ventana, x, y, ancho, alto, TRUE);
}

// Maximiza la ventana de la consola.
void maximizar() {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

// Pantalla completa: simula la combinacion ALT + ENTER.
void pantallaCompleta() {
	keybd_event(VK_MENU,   0, 0, 0);              // ALT abajo
	keybd_event(VK_RETURN, 0, 0, 0);              // ENTER abajo
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU,   0, KEYEVENTF_KEYUP, 0);
	Sleep(300);   // le damos tiempo a la consola a redibujarse
}
// Oculta el cursor parpadeante.
void ocultarCursor() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(consola, &cursor);
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(consola, &cursor);
}

// Vuelve a mostrar el cursor.
void mostrarCursor() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(consola, &cursor);
	cursor.bVisible = TRUE;
	SetConsoleCursorInfo(consola, &cursor);
}
//Utilidades
void esperar(int milisegundos) {
	Sleep(milisegundos);
}

void limpiarPantalla() {
	system("cls");
}
string centrar(string texto, int ancho) {
	int largo = texto.length();
	if (largo >= ancho) return texto;
	int izquierda = (ancho - largo) / 2;
	int derecha = ancho - largo - izquierda;
	return string(izquierda, ' ') + texto + string(derecha, ' ');
}

// Mueve el cursor a la columna x, fila y.
void gotoxy(int x, int y) {
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicion);
}
// Imprime una linea del marco: los bordes en un color y el texto en otro.
void linea(string texto, int colorTexto, int colorMarco) {
	color(colorMarco);   
	cout <<"|";
	color(colorTexto);   
	cout <<centrar(texto, ANCHO);
	color(colorMarco);   
	cout <<"|"<< endl;
}
void borde(int colorMarco) {
	color(colorMarco);
	cout << "+" << string(ANCHO, '=') << "+" << endl;
}
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
	linea("Ingenieria en sistemas Comisión B",AZUL,VERDE);
	linea("Algoritmos y Estructuras de Datos",AZUL,VERDE);
	linea("",BLANCO,VERDE);
	borde(VERDE);
}

	
