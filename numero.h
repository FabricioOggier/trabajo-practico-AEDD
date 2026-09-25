
#ifndef NUMERO_H
#define NUMERO_H

struct Numero {
    int valor;
    char color;

};

void inicializarNumero(Numero &n, int valor, char color);
int obtenerValor(Numero n);
char obtenerColor(Numero n);
int obtenerParidad(Numero n);
void guardarGiro(Numero numeros[], Numero nuevo, int pos);
void mostrarHistorial(Numero numeros[],int totalGiros);
void mostrarEstadisticas(Numero numeros[],int totalGiros);
#endif
