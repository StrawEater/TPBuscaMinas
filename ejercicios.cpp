//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/



//Devuelve la cantidad de minas adyacentes a la posicion dada
int minasAdyacentes(tablero& t, pos p) {
    int cantMinasAdyacentes = 0;
    int coordX = p.first;
    int coordY = p.second;
    //Recorro las 8 celdas adyacentes a la posicion, como tambien la posicion misma
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            //Si la posicion actual es igual a la posicion origina, la ignoro
            if (i == 0 && j == 0) continue;
            //En otro caso, verifico que sea una posicion valida y agrego 1 al contador si la posicion tiene mina
            if (posicionValida(t,pos(coordX+i,coordY+j))){
                cantMinasAdyacentes += t[coordY+j][coordX+i] ? 1 : 0;
            }
        }
    }
    return cantMinasAdyacentes;
}



/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    int indexBanderita = getPosIndexEnBanderitas(b,p);
    if (indexBanderita == -1){
        b.push_back(p);
    }else{
        eliminarPosicionDeBanderita(b,indexBanderita);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    for (int i = 0; i < j.size(); ++i) {
        pos posDeJugada = j[i].first;
        int columna = posDeJugada.first;
        int fila = posDeJugada.second;
        if (t[fila][columna]){
            return true;
        }
    }
    return false;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
