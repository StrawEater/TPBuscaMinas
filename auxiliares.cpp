//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

//Verifica que las coordenadas esten entre el rango de la matriz Tablero, y si lo hacen, devuelve True.
//Que Ninguna de ellas sean negativas. Que la cordY no sea mayor a la cantidad de filas del tablero y
//que la cordX no sea mayor a la cantidad de columnas
bool posicionValida(tablero& t, pos p){
    int coordX = p.second;
    int coordY = p.first;
    bool FilaValida = coordY >= 0 && coordY < t.size();
    bool ColumnaValida = coordX >= 0 && coordX < t[0].size();
    return FilaValida && ColumnaValida;
}

int getPosIndexEnBanderitas(banderitas& b, pos p){
    for (int i = 0; i < b.size(); ++i) {
        pos posBanderita = b[i];
        if (sonPosIguales(posBanderita,p)){
            return i;
        }
    }
    return -1;
}

int getPosIndexEnJugadas(jugadas& j, pos p){

    for (int i = 0; i < j.size(); ++i) {
        pos posJugada = j[i].first;

        if (sonPosIguales(posJugada,p)){
            return i;
        }
    }
    return -1;
}

//Devuelve un vector de tipo Banderita indentico al argumento, excepto por no conterner
//al elemento que se encontraba en indexPosicion
void eliminarPosicionDeBanderita(banderitas& b, int indexPosicion){
    banderitas nuevoVectorBanderitas;
    for (int i = 0; i < b.size(); ++i) {
        if (i != indexPosicion) nuevoVectorBanderitas.push_back(b[i]);
    }
    b = nuevoVectorBanderitas;
}

bool sonPosIguales(pos p1, pos p2){
    int coordYPos1 = p1.first;
    int coordXPos1 = p1.second;

    int coordYPos2 = p2.first;
    int coordXPos2 = p2.second;

    return coordXPos1 == coordXPos2 && coordYPos1 == coordYPos2;
}

bool noBorde(tablero t, pos p){
    return (0<p.first && p.first<t.size()-1)&&(0<p.second && p.second<t.size()-1);
}
bool esJugada(jugadas j,pos p){
    return (getPosIndexEnJugadas(j,p)!=-1);
}

bool noEsBanderita(banderitas b, pos p){
    return (getPosIndexEnBanderitas(b,p)==-1);
}

bool verificoConDePos(tablero t,jugadas j,banderitas b,pos p){
    return posicionValida(t,p) && esJugada(j, p) && (minasAdyacentes(t, p)==1) && noEsBanderita(b,p);
}

bool patronVertical(tablero t, jugadas j,banderitas b,pos p1, pos p2){
    return (verificoConDePos(t, j, b ,p1) && verificoConDePos(t, j, b, p2));
}

bool patronHorizontal(tablero t, jugadas j,banderitas b,pos p3, pos p4){
    return verificoConDePos(t, j, b,p3) && verificoConDePos(t, j, b,p4);
}

bool esValidaYnoBanderitaNiJugada(tablero t,jugadas j, banderitas b, pos p){
    return posicionValida(t,p) && !esJugada(j,p) && noEsBanderita(b,p);
}


bool patron_Y_Asignacion_A_P(tablero t, jugadas j, banderitas b, bool& valor,pos posA, pos &p, pos posAlfa, pos posBeta, pos posCelta,pos posDelta) {
    if (patronVertical(t, j, b,posCelta, posDelta)) {
        if (esValidaYnoBanderitaNiJugada(t,j, b, posAlfa)) {
            p = posAlfa;
            valor = true;
        }
        else if (esValidaYnoBanderitaNiJugada(t,j, b, posBeta)) {
            p = posBeta;
            valor = true;
        } 
        else {}
    } else if (patronHorizontal(t, j, b,posAlfa, posBeta)) {
        if (esValidaYnoBanderitaNiJugada(t,j, b, posCelta)) {
            p = posCelta;
            valor = true;
        }
        else if (esValidaYnoBanderitaNiJugada(t,j, b, posDelta)) {
            p = posDelta;
            valor = true;
        } 
        else {}
    } else {}
}

/*bool jugadaHecha(jugada jugadaChequeada, jugadas juego) {
    for(int i=0;i<juego.size();i++) {
        if(juego[i].first == jugadaChequeada.first) {
            return true;
            break;
        }
    return false;
}
}*/

// JUGAR PLUS 2V
//https://en.wikipedia.org/wiki/Flood_fill
void caminoLibre2V(tablero& t, banderitas& b, pos p, jugadas& j, bool jugadaOriginal){
    if (esValidaYnoBanderitaNiJugada(t,j,b,p) && minasAdyacentes(t,p) == 0){
        j.push_back(jugada(p, minasAdyacentes(t,p)));
        pos celdaDerecha = pos(p.first,p.second+1);
        caminoLibre2V(t,b,celdaDerecha,j, false);
        pos celdaIzquierda = pos(p.first,p.second-1);
        caminoLibre2V(t,b,celdaIzquierda,j, false);
        pos celdaAbajo = pos(p.first+1,p.second);
        caminoLibre2V(t,b,celdaAbajo,j, false);
        pos celdaArriba = pos(p.first-1,p.second);
        caminoLibre2V(t,b,celdaArriba,j, false);
    }
    else if(jugadaOriginal && minasAdyacentes(t,p) > 0){
        j.push_back(jugada(p, minasAdyacentes(t,p)));
    }
}

/*void caminoLibre(tablero& t, banderitas& b, pos p, bool profunda, string direccion, jugadas& j) {

    //Primero determino en base a la direccion el modo de funcionamiento del algoritmo
    int ejeFijo, ejeVariable, direccionMovimiento, ejeTableroRelevante;
    bool testeoEnRango;
    pair<string,string> direccionAlternativa;
    pos posicionActual, posicionSiguiente;

    if(direccion == "arriba") {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = 1;
        ejeTableroRelevante = t[0].size();
        testeoEnRango = ejeVariable < ejeTableroRelevante;
        pair<string,string> direccionAlternativa("izquierda","derecha");
        pos posicionActual(ejeFijo,ejeVariable);
        pos posicionSiguiente(ejeFijo, ejeVariable+=direccionMovimiento);
    }
    else if(direccion == "abajo") {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = -1;
        ejeTableroRelevante = t[0].size();
        testeoEnRango = ejeVariable > ejeTableroRelevante;
        pair<string,string> direccionAlternativa("izquierda","derecha");
        pos posicionActual(ejeFijo,ejeVariable);
        pos posicionSiguiente(ejeFijo, ejeVariable+=direccionMovimiento);
    }
    else if(direccion == "izquierda") {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = -1;
        ejeTableroRelevante = t.size();
        testeoEnRango = ejeVariable > ejeTableroRelevante;
        pair<string,string> direccionAlternativa("arriba","abajo");
        pos posicionActual(ejeVariable,ejeFijo);
        pos posicionSiguiente(ejeVariable+=direccionMovimiento, ejeFijo);
    }
    else if(direccion == "derecha") {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = 1;
        ejeTableroRelevante = t.size();
        testeoEnRango = ejeVariable < ejeTableroRelevante;
        pair<string,string> direccionAlternativa("arriba","abajo");
        pos posicionActual(ejeVariable,ejeFijo);
        pos posicionSiguiente(ejeVariable+=direccionMovimiento, ejeFijo);
    }


    //Ya tengo las variables del algoritmo determinadas, ahora empiezo a ciclar
    for(;testeoEnRango; ejeVariable+=direccionMovimiento) {
        
        jugada jugadaActual(posicionActual, minasAdyacentes(t, posicionActual));
        //Chequeo que, de ser profunda y...
        //1. Si la siguiente celda es inválida, choca con banderita/adyacentes y no está hecha
        if(!jugadaHecha(jugadaActual, j) && profunda && (ejeVariable+1 == ejeTableroRelevante || minasAdyacentes(t, posicionSiguiente) != 0 || getPosIndexEnBanderitas(b, posicionSiguiente) != -1)) {
            //Cambio la dirección de movimiento, profunda en ambos lados y agrego la jugada al vector
            j.push_back(jugadaActual);
            caminoLibre(t, b, p, true, direccionAlternativa.first, j);
            caminoLibre(t, b, p, true, direccionAlternativa.second, j);
        }

        //2. Si la siguiente celda es válida, no choca con banderita/adyacentes y no está hecha
        else if(!jugadaHecha(jugadaActual, j) && profunda && minasAdyacentes(t, posicionSiguiente) == 0 && getPosIndexEnBanderitas(b, posicionSiguiente) == -1) {
            //Agrego jugada en el vector (falta agregar)
            j.push_back(jugadaActual);
            //Busco hacia direcciones alternativas
            caminoLibre(t, b, p, false, direccionAlternativa.first, j);
            caminoLibre(t, b, p, false, direccionAlternativa.second, j);
        }

        //La búsqueda entonces es no profunda. Me fijo si tengo adyacentes/banderitas
        //3. De haber adyacentes/banderitas, corto la búsqueda
        if(!jugadaHecha(jugadaActual, j) && minasAdyacentes(t, posicionActual) == 0 || getPosIndexEnBanderitas(b, posicionActual) == -1) {
                break;
        }
        else {
        //No hay adyacentes/banderitas, agrego la jugada y sigo
            j.push_back(jugadaActual);
        }
    }
}

void quitarDuplicados(jugadas& origen) {
    //Primero purgo el vector origen de jugadas duplicadas
        //Declaro un vector temporal
        //Me fijo el primer elemento del origen, y si está duplicado no lo agrego al temporal
        //Si no está duplicado, lo agrego al temporal
    jugadas vectorTemporal;
    for(int a=0;a<origen.size()-1;a++) {
        bool duplicado = false;
        for(int b=1;b<origen.size();b++) {
            if(origen[a].first.first == origen[b].first.first && origen[a].first.second == origen[b].first.second) {
                duplicado = true;
                break;
            }
        }
        if(!duplicado)
            vectorTemporal.push_back(origen[a]);
    }
    origen = vectorTemporal;
}*/