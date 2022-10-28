
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

int getPosIndexEnJugadas(jugadas& j, pos p);

bool sonPosIguales(pos p1, pos p2);

bool noBorde(tablero t, pos p);

bool esJugada(jugadas j, pos p);

bool verificoConDePos(tablero t, jugadas j, pos p);

bool patronVertical(tablero t, jugadas j, pos p);

bool patronHorizontal(tablero t, jugadas j, pos p);

bool esValidaYnoBanderitaNiJugada(tablero t, jugadas j, banderitas b, pos p);




bool sonPosIguales(pos p1, pos p2);


void caminoLibre(tablero& t, banderitas& b, pos p, bool profunda, string direccion, jugadas& j) {
