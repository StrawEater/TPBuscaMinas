
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


vector<pos> caminosAutomaticos(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);

//La variante profunda de cada funcion llama a su contraparte (arriba/abajo llaman a izquierda/derecha) profunda
void busquedaIzquierda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY, int ejeY);
void busquedaIzquierdaProfunda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);

void busquedaDerecha(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY, int ejeY);
void busquedaDerechaProfunda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);

void busquedaArriba(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);
void busquedaArribaProfunda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);

void busquedaAbajo(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);
void busquedaAbajoProfunda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY);