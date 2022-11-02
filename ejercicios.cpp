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
            //Si la posicion actual es igual a la posicion original, la ignoro
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

// Dado un vector de Banderitas y una posicion, junto con otros parametros, cambia el estado de la posicion dada.
// Si la posicion ya era una banderita, se la elimina del vector banderitas(Deja de ser banderita)
// Si la posicion no era una banderita, se la agrega al vector banderitas(Se convierte en una banderita)
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    //Verifico que la posicion se encontraba en Banderitas
    int indexBanderita = getPosIndexEnBanderitas(b,p);
    //Si no lo hacia, la agrega
    if (indexBanderita == -1){
        b.push_back(p);
    }else{
        // Si lo hacia, la elimino
        eliminarPosicionDeBanderita(b,indexBanderita);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
//Dado un vector de jugadas y un tablero, devuelve si el estado del juego implica que el usuario perdio
// Que un usuario pierda implica que alguna de sus jugadas fue en una celda que contenia una mina
bool perdio(tablero& t, jugadas& j) {
    //recorro todas las jugadas
    for (int i = 0; i < j.size(); ++i) {
        pos posDeJugada = j[i].first;
        int columna = posDeJugada.second;
        int fila = posDeJugada.first;
        //Si la posicion de la celda jugada tiene un bomba, es porque perdi.
        if (t[fila][columna]){
            return true;
        }
    }
    //Si ninguna celda jugada tiene una bomba en ella, aun no perdi.
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
// Dado un tablero, banderitas, jugadas, y la posicion de la celda que el usuario decidio jugar, devuelve el nuevo vector de jugadas
// El nuevo vector de jugadas deberia contener:
// la jugadas que ya se encontraban en el antiguo vector
// la jugada que represente la posicion que el usuario decidio jugar en este momento
// todas las jugadas que representan a las celdas a las que es posible llegar desde la Pos Origal a ella sin pasar por ninguna celda con minas adyacentes
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    caminoLibre2V(t,b,p,j);
    /*
    //Declaro un vector de jugadas y su referencia
    jugadas vectorAuxiliar;
    jugadas & vectorAuxiliarRef = vectorAuxiliar;

    //Llamo al algoritmo que calcula caminos libres desde la posición jugada hacia todas las direcciones, y le paso el vector
    caminoLibre(t, b, p, true, "arriba", vectorAuxiliarRef);
    caminoLibre(t, b, p, true, "abajo", vectorAuxiliarRef);
    caminoLibre(t, b, p, true, "izquierda", vectorAuxiliarRef);
    caminoLibre(t, b, p, true, "derecha", vectorAuxiliarRef);

    //Le agrego al vector de jugadas las jugadas hechas
    j.insert(j.end(), vectorAuxiliar.begin(), vectorAuxiliar.end());
     */
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p){
     bool valor = false;
    for (int i = 0; i < j.size(); i++) {
        pos posA = j[i].first;
        int minasAd = j[i].second;
        if(minasAd==2 && posicionValida(t, posA)){
            pos posAlfa = pos(posA.first, posA.second - 1);
            pos posBeta = pos(posA.first, posA.second + 1);
            pos posCelta = pos(posA.first - 1, posA.second);
            pos posDelta = pos(posA.first + 1, posA.second);
            if (noBorde(t, posA)) {
                patron_Y_Asignacion_A_P(t, j, b, valor, posA, p, posAlfa, posBeta, posCelta, posDelta);
            } else {
                patron_Y_Asignacion_A_P(t, j, b, valor, posA, p, posAlfa, posBeta, posCelta, posDelta);
            }
        } else {}
    }
    return valor;
}
