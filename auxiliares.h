
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool posicionValida(tablero& t, pos p);

int getPosIndexEnBanderitas(banderitas& b, pos p);

void eliminarPosicionDeBanderita(banderitas& b, int indexPosicion);

bool sonPosIguales(pos p1, pos p2);


void caminoLibre(tablero& t, banderitas& b, pos p, bool profunda, string direccion, jugadas& j) {