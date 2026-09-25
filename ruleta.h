
#ifndef RULETA_H
#define RULETA_H
#include "numero.h"
#include "jugador.h"

void inicializarRuleta(Numero ruleta[37]);
Numero girarRuleta(Numero ruleta[37]);
void escrutinio(Jugador jugadores[], int cant, Numero resultado);
void ejecutarCicloPartidas(Numero ruleta[37], Jugador jugadores[], int cantJugadores, Numero historial[], int &totalGiros);

#endif
