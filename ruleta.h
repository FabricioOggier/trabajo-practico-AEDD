
#ifndef RULETA_H
#define RULETA_H
#include "numero.h"

void inicializarRuleta(Numero ruleta[37]);
Numero girarRuleta(Numero ruleta[37]);
void escrutinio(Jugador jugadores[], int cant, Numero resultado);

#endif
