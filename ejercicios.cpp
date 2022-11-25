//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;
/**************Tomamos para el peor caso que jugadas puede tener t² o banderitas puede tener t² como longitudes.
Vamos a tomar t² como n para facilitar los calculos, siendo t la longitud del tablero y t² es la cantidad total de casillas del mismo.*******/

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/



//Devuelve la cantidad de minas adyacentes a la posición dada
//COMPLEJIDAD: 1 + 1 + 1 + 1 + 4 + 3*(1 + 4 + 3*(1+6+2)) - (6+2) + 1 + 1 = 98 = O(1).
//El peor caso seria una celda con 8 bombas vecinas, ya que se sumaría cantMinasAdy 8 veces.
//Se le resta (6+2) porque i y j llegaran a i=0 y j=0 evitando la ejecucion del segundo if, pero ejecutando el continue.

int minasAdyacentes(tablero& t, pos p) {
    int cantMinasAdyacentes = 0; //COMPLEJIDAD(Declaración y asignación de cantMinasAdyacentes): 1.
    int coordY = p.first; //COMPLEJIDAD(Declaración y asignación de coordY): 1.
    int coordX = p.second; //COMPLEJIDAD(Declaración y asignación de coordX): 1.
    //Recorro las 8 celdas adyacentes a la posicion, como tambien la posicion misma
    for (int i = -1; i <= 1; ++i) { //COMPLEJIDAD(Declaración y asignación de i): 1.
                                    //COMPLEJIDAD(Guarda): 4.
                                    //COMPLEJIDAD(Incremento de i++): 3
        for (int j = -1; j <= 1; ++j) { //COMPLEJIDAD(Declaración y asignación de j): 1.
                                        //COMPLEJIDAD(Guarda): 4.
                                        //COMPLEJIDAD(Incremento de j++): 3
            //Si la posicion actual es igual a la posicion original, la ignoro
            if (i == 0 && j == 0){ //COMPLEJIDAD(Evaluación): 1
                continue; // COMPLEJIDAD(Instrucción Elemental):1
            }
            //En otro caso, verifico que sea una posicion valida y agrego 1 al contador si la posicion tiene mina
            if (posicionValida(t,pos(coordX+i,coordY+j))){ //COMPLEJIDAD(Verificacion y posicionValida): 1 + 5 = 6
                cantMinasAdyacentes += t[coordY+j][coordX+i] ? 1 : 0; //COMPLEJIDAD(Verificacion y Asignacion): 2
            }
        }
    }
    return cantMinasAdyacentes; // COMPLEJIDAD(Instrucción elemental): 1
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

// Dado un vector de Banderitas y una posición, junto con otros parámetros, cambia el estado de la posición dada.
// Si la posición ya era una banderita, se la elimina del vector banderitas(Deja de ser banderita)
// Si la posición no era una banderita, se la agrega al vector banderitas(Se convierte en una banderita)
// COMPLEJIDAD: |b| + 1 + |b|, ya que el peor caso es que quiera eliminar una banderita que este en la última posición de b
// 2|b| + 1, el peor caso de esto sería que todas las celdas del tablero (n) sean banderitas: 2n+1 = O(n).
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    //Verifico que la posicion se encontraba en Banderitas
    int indexBanderita = getPosIndexEnBanderitas(b,p); //COMPLEJIDAD(getPosIndexEnBanderitas + ASIGNACIÓN): |b| + 1
    //Si no lo hacía, la agrega
    if (indexBanderita == -1){ //COMPLEJIDAD(Verificación): 1
        b.push_back(p); //COMPLEJIDAD(Instrucción Elemental): 1
    }else{
        // Si lo hacía, la elimino
        eliminarPosicionDeBanderita(b,indexBanderita); //COMPLEJIDAD(eliminarPosicionDeBanderita): |b|
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
//Dado un vector de jugadas y un tablero, devuelve si el estado del juego implica que el usuario perdió
// Que un usuario pierda implica que alguna de sus jugadas fue en una celda que contenía una mina
//COMPLEJIDAD: 1+|j|(1+1+1+1+1)+1 = 2+|j|*5 = 5|j|+2.
// En el peor de lo casos, j es igual a la longitud del tablero, siendo la complejidad 5n+2 = O(n)
bool perdio(tablero& t, jugadas& j) {
    //recorro todas las jugadas
    for (int i = 0; i < j.size(); i++){ //COMPLEJIDAD(Declaración y asignación de i): 1.
                                        //COMPLEJIDAD(Guarda): |j|.
                                        //COMPLEJIDAD: 1, dos funciones elementales.
        pos posDeJugada = j[i].first;//COMPLEJIDAD: 1.
        int columna = posDeJugada.second;//COMPLEJIDAD: 1.
        int fila = posDeJugada.first;//COMPLEJIDAD: 1.
        //Si la posición de la celda jugada tiene una bomba, es porque perdí.
        if (t[fila][columna]){//COMPLEJIDAD: 1.
            return true;//COMPLEJIDAD: 1.
        }
    }
    //Si ninguna celda jugada tiene una bomba en ella, aún no perdí.
    return false;//COMPLEJIDAD: 1.
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
//Dado un tablero y un conjunto de jugadas, determina si dicho conjunto hace que el jugador gane la partida
//El entero moduloTablero aumenta por cada tablero que se encuentra, y decrementa cuando halla una bomba. De esta forma, logramos contar la cantidad de tableros bomba
//Sea t la cantidad de filas del tablero. El peor caso se da cuando el tablero es cuadrado (tengo que recorrer el primer y segundo ciclo for t veces) y eso lleva la complejidad a O(t²). Luego, cuando llego a una posición me fijo en el vector jugadas si la posición se jugó. En el peor caso, tendría que recorrer un vector jugadas que tenga todas las jugadas del tablero (ninguna bomba) y al final tenga la que estoy buscando. Es decir, recorre t² jugadas, lo que lleva el orden propio de este for a O(t²). Cuando multiplicamos, nos queda una función de orden t⁴. Como estamos calculando la complejidad en cuanto a la cantidad t² = n de casilleros del tablero, el orden de la función es n²
//COMPLEJIDAD: Tgano(n) pertenece a O(n²)
bool gano(tablero& t, jugadas& j) {
    //El jugador gana si se dan dos condiciones:
    //  1. No se jugó un casillero bomba
    //  2. La cantidad de jugadas es la misma que casilleros sin bomba

    int moduloTablero = 0;  //Un contador de casilleros del tablero
    
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
// todas las jugadas que representan a las celdas a las que es posible llegar desde la Pos jugada hasta ella sin pasar por ninguna celda con minas adyacentes
// Complejidad O(n²).
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    caminoLibre2V(t,b,p,j); // Complejidad O(n²)
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
//Devuelve un valor (true o false) dependiendo de si existe o no un patron 121,
//si es true se modifica el p ingresado por uno seguro a jugar y si es false no nos interesa lo que pase con p.
//COMPLEJIDAD: n*(12n+34)+1+1+1 = 12n²+34n+3 = O(n²) = O(t⁴)
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p){
   
    //damos origen a un valor para que devuelva la función.
    bool valor = false; //COMPLEJIDAD: 1.

    //ciclamos en el vector de jugadas para encontrar una posición ya jugada que tenga 2 minas adyacentes y
    // ver si con otras ya jugadas que tengan 1 mina adyacente se tiene un patron 121.

    for (int i = 0; i < j.size(); i++) {//COMPLEJIDAD(Declaración y asignación de i): 1.
                                        //COMPLEJIDAD(Guarda): |j|. en el peor de los casos es n.
                                        //COMPLEJIDAD: 1.
                                        
        pos posA = j[i].first;//COMPLEJIDAD: 1
        int minasAd = j[i].second;//COMPLEJIDAD: 1
        if(minasAd==2 && posicionValida(t, posA)){//COMPLEJIDAD: 1 + 4 = 5

            //sacamos las posibles 4 posiciones de los patrones.
            
            //COMPLEJIDAD: calcular las 4 posiciones es 4 ya que cada una posee complejidad de 1.
            pos posUp = pos(posA.first - 1, posA.second);
            pos posDown = pos(posA.first + 1, posA.second);
            pos posLeft = pos(posA.first, posA.second - 1);
            pos posRight = pos(posA.first, posA.second + 1);

            patron_Y_Asignacion_A_P(t, j, b, valor, p, posLeft, posRight, posUp, posDown);
            //Verificamos el patron con las posibles posiciones y la encontrada con las 2 minas adyacentes.
            //COMPLEJIDAD: 12n+22
        }
    }
    return valor;
    //COMPLEJIDAD: 1.
}
