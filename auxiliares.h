
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"
#include <string>

bool posicionValida(tablero& t, pos p);

int getPosIndexEnBanderitas(banderitas& b, pos p);

void eliminarPosicionDeBanderita(banderitas& b, int indexPosicion);

int getPosIndexEnJugadas(jugadas& j, pos p);

bool sonPosIguales(pos p1, pos p2);

bool esJugada(jugadas j, pos p);

bool noEsBanderita(banderitas b, pos p);

bool verificoConDePos(tablero t, jugadas j, banderitas b,pos p);

bool patronVertical(tablero t, jugadas j, banderitas b,pos p1, pos p2);

bool patronHorizontal(tablero t, jugadas j, banderitas b,pos p3, pos p4);

bool esValidaYnoBanderitaNiJugada(tablero t, jugadas j, banderitas b, pos p);

bool
patron_Y_Asignacion_A_P(tablero t, jugadas j, banderitas b, bool& valor,pos posA, pos &p, pos posLeft, pos posRight, pos posUp,pos posDown);

bool sonPosIguales(pos p1, pos p2);

void caminoLibre(tablero& t, banderitas& b, pos p, bool profunda, string direccion, jugadas& j);
void caminoLibre2V(tablero& t, banderitas& b, pos p, jugadas& j);

void quitarDuplicados(jugadas& origen);

bool jugadaHecha(jugada jugadaChequeada, jugadas juego);