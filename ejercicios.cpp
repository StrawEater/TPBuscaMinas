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
    int coordY = p.first;
    int coordX = p.second;
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
    //El jugador gana si se dan dos condiciones:
    //  1. No se jugó un casillero bomba
    //  2. La cantidad de jugadas es la misma que casilleros sin bomba

    int moduloTablero = 0;  //Un contador eficiente de casilleros del tablero
    
    //Empiezo a recorrer el tablero
    for(int a=0;a<t.size();a++) {
        for(int b=0;b<t[a].size();b++) {
            if(t[a][b]) {                       //Si en algun casillero hay una bomba...
                moduloTablero--;
                pos posicionTablero(a,b);
                for(int c=0;c<j.size();c++) {   //...recorro la lista de jugadas en búsqueda de ese casillero
                    if(sonPosIguales(posicionTablero, j[c].first))
                        return false;           //De haber sido jugado, no gana y retorna false
                }
            }
            moduloTablero++;
        }
    }
    //No toque ninguna bomba, ahora falta que #jugadas = #casillerosNoBomba
    return moduloTablero == j.size();
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    vector<pos> posiblesPos;
    for (int i = 0; i < j.size(); i++) {
        pos posA = j[i].first;
        if (posicionValida(t, posA)) {
            if (minasAdyacentes(t, posA) == 2) {
                pos posAlfa = pos(posA.first, posA.second - 1);
                pos posBeta = pos(posA.first, posA.second + 1);
                pos posCelta = pos(posA.first - 1, posA.second);
                pos posDelta = pos(posA.first + 1, posA.second);
                if (noBorde(t, posA)) {
                    if (patronVertical(t, j, posA)) {
                        if (noBanderitaNiJugada(j, b, posAlfa)) {
                            posiblesPos.push_back(posAlfa);
                        }
                        if (noBanderitaNiJugada(j, b, posBeta)) {
                            posiblesPos.push_back(posBeta);
                        } else {}
                    } else if (patronHorizontal(t, j, posA)) {
                        if (noBanderitaNiJugada(j, b, posCelta)) {
                            posiblesPos.push_back(posCelta);
                        }
                        if (noBanderitaNiJugada(j, b, posDelta)) {
                            posiblesPos.push_back(posDelta);
                        } else {}
                    }
                } else {
                    if (patronVertical(t, j, posA)) {
                        if (noBanderitaNiJugada(j, b, posAlfa)) {
                            posiblesPos.push_back(posAlfa);
                        }
                        if (noBanderitaNiJugada(j, b, posBeta)) {
                            posiblesPos.push_back(posBeta);
                        } else {}
                    } else if (patronHorizontal(t, j, posA)) {
                        if (noBanderitaNiJugada(j, b, posCelta)) {
                            posiblesPos.push_back(posCelta);
                        }
                        if (noBanderitaNiJugada(j, b, posDelta)) {
                            posiblesPos.push_back(posDelta);
                        } else {}
                    } else {}
                }
            } else {}
        }
    }
    return posiblesPos.size() != 0;
}