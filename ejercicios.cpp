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
    //El jugador gana si se dan dos condiciones:
    //  1. No se jugó un casillero bomba
    //  2. La cantidad de jugadas es la misma que casilleros sin bomba

    int moduloTablero = 0;  //Un contador eficiente de casilleros del tablero
    
    //Empiezo a recorrer el tablero
    for(int a=0;a<t.size();a++) {
        for(int b=0;b<t[a].size();b++) {
            if(t[b][a]) {                       //Si en algun casillero hay una bomba...
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

}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
//faltan las funciones de las guardas y ademas ver si se puede achicar.
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    vector<pos> posiblesPos;
    for(int i=0; i<j.size; i++){
        pos posA=j[i].first;
        if(posicionValida(t, posA)){
            if (minasAdyacentes(t, posA) == 2){
                if(noBorde(t, posA)) {
                    if (esPatronVertical(t, j, posA)) {
                        if(noBanderitaNiJugada(pos(posA.first-1,posA.second),j,b)){
                            posiblesPos.push_back(la posicion de la guarda);
                        }
                        if(noBanderitaNiJugada(pos(posA.first+1,posA.second))){
                            posiblesPos.push_back(la posicion de la guarda);
                        }
                        else {}
                    }
                    else if (esPatronHorizontal(t, j,posA)) {
                        if(noBanderitaNiJugada(pos(posA.first,posA.second-1))){
                            posiblesPos.push_back(la posicion de la guarda);
                        }
                        if(noBanderitaNiJugada(pos(posA.first,posA.second+1))){
                            posiblesPos.push_back(la posicion de la guarda);
                        }
                        else{}
                    }
                } else {//ver bien este caso
                    if(esPatronVertical(t, j, posA)){
                        if(pos(posA.first-1,posA.second) no es jugada ni es bandera y esta en el tablero){
                            posiblesPos.push_back(la posicion de la guarda);
                        }
                        else if(pos(posA.first+1, posA.second) no es jugada ni es bandera y esta en el tablero){
                            posiblesPos.push_back(la posicion de la guarda)
                        } else {}
                    }
                    else if(esPatronHorizontal(t, j, posA)){
                        if(pos(posA.first,posA.second-1) no es jugada ni es bandera y esta en el tablero){
                            posiblesPos.push_back(la posicion de la guarda);
                        }
                        else if(pos(posA.first,posA.second+1) no es jugada ni es bandera y esta en el tablero){
                            posiblesPos.push_back(la posicion de la guarda)
                        } else {}
                    } else {}
                }
            } else {}
        } else {
            return false;
        }
    }
}

bool noBorde(tablero t, pos p){
    return (0<p.first && p.first<t.size()-1)&&(0<p.second && p.second<t.size()-1);
}
bool esJugada(j,p){

}

bool verificoConDePos(tablero t,jugadas j,pos p){
    return esJugada(j, p) && minasAdyacentes(t, p)==1;
}

bool patronVertical(tablero t, jugadas j,pos p){
    pos pos1 = pos (p.first-1,p.second);
    pos pos2 = pos (p.first+1, p.second);
    return verificoConDePos(t, j,pos1 ) && verificoConDePos(t, j,pos2);
}

bool patronHorizontal(tablero t, jugadas j,pos p){
    pos pos3 = pos (p.first,p.second-1);
    pos pos4 = pos (p.first, p.second+1);
    return verificoConDePos(t, j,pos3) && verificoConDePos(t, j,pos4);
}

bool noBanderitaNiJugada(){

}