//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;
/**************Tomamos para el peor caso que jugadas puede tener t² o banderitas puede tener t² en su peor caso como longitudes.
Vamos a tomar t² como n, para facilitar los calculos, siendo t la longitud del tablero y t² es la cantidad total de casillas del mismo.*******/

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
//Dado un vector de jugadas y un tablero, devuelve si el estado del juego implica que el usuario perdió
// Que un usuario pierda implica que alguna de sus jugadas fue en una celda que contenía una mina
//COMPLEJIDAD: 1+n(2+1+1+1+1) = 1+n*6 = 6n+1 = O(n).
bool perdio(tablero& t, jugadas& j) {
    //recorro todas las jugadas
    for (int i = 0; i < j.size(); ++i){ //COMPLEJIDAD(Declaración y asignación de i): 1.
                                        //COMPLEJIDAD(Guarda): n.
                                        //COMPLEJIDAD: 2, dos funciones elementales.
        pos posDeJugada = j[i].first;//COMPLEJIDAD: 1.
        int columna = posDeJugada.second;//COMPLEJIDAD: 1.
        int fila = posDeJugada.first;//COMPLEJIDAD: 1.
        //Si la posición de la celda jugada tiene una bomba, es porque perdí.
        if (t[fila][columna]){//COMPLEJIDAD: 1.
            return true;
        }
    }
    //Si ninguna celda jugada tiene una bomba en ella, aún no perdí.
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
            if(t[a][b]) {                       //Si en algún casillero hay una bomba...
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
// Dado un tablero, banderitas, jugadas, y la posición de la celda que el usuario decidió jugar, devuelve el nuevo vector de jugadas
// El nuevo vector de jugadas debería contener:
// las jugadas que ya se encontraban en el antiguo vector
// la jugada que represente la posición que el usuario decidió jugar en este momento
// todas las jugadas que representan a las celdas a las que es posible llegar desde la Pos Original a ella sin pasar por ninguna celda con minas adyacentes
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
//Devuelve un valor (true o false) dependiendo de si existe o no un patron 121,
//si es true se modifica el p ingresado por uno seguro a jugar y si es false no nos interesa lo que pase con p.
//COMLEJIDAD: n*(12n+25)+1+1 = 12n²+25n+2 = O(n²) = O(t⁴)
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p){
   
    //damos origen a un valor para que devuelva la función.
    bool valor = false; //COMPLEJIDAD: 1.

    //ciclamos en el vector de jugadas para encontrar una posición ya jugada que tenga 2 minas adyacentes y
    // ver si con otras ya jugadas que tengan 1 mina adyacente se tiene un patron 121.

    for (int i = 0; i < j.size(); i++) {//COMPLEJIDAD(Declaración y asignación de i): 1.
                                        //COMPLEJIDAD(Guarda): n.
                                        //COMPLEJIDAD: 2, dos funciones elementales.
                                        
        pos posA = j[i].first;//COMPLEJIDAD: 1
        int minasAd = j[i].second;//COMPLEJIDAD: 1
        if(minasAd==2 && posicionValida(t, posA)){//COMPLEJIDAD: 1 + 4 = 5

            //sacamos las posibles 4 posiciones de los patrones.
            
            //COMPLEJIDAD: calcular las 4 posiciones es 4.
            pos posUp = pos(posA.first - 1, posA.second);
            pos posDown = pos(posA.first + 1, posA.second);
            pos posLeft = pos(posA.first, posA.second - 1);
            pos posRight = pos(posA.first, posA.second + 1);

            patron_Y_Asignacion_A_P(t, j, b, valor, p, posLeft, posRight, posUp, posDown);
            //Verificamos el patron con las posibles posiciones y la encontrada con las 2 minas adyacentes.
            //COMPLEJIDAD: 12n+16
        }
    }
    return valor;
}
