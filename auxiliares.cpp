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
    int coordX = p.first;
    int coordY = p.second;
    bool FilaValida = coordY >= 0 && coordY < t.size();
    bool ColumnaValida = coordX >= 0 && coordX < t[0].size();
    return FilaValida && ColumnaValida;
}

int getPosIndexEnBanderitas(banderitas& b, pos p){
    int coordXPos = p.first;
    int coordYPos = p.second;

    for (int i = 0; i < b.size(); ++i) {
        int coordXBanderita = b[i].first;
        int coordYBanderita = b[i].second;

        if (coordXBanderita == coordXPos && coordYBanderita == coordYPos){
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
    int coordXPos1 = p1.first;
    int coordYPos1 = p1.second;

    int coordXPos2 = p2.first;
    int coordYPos2 = p2.second;

    return coordXPos1 == coordXPos2 && coordYPos1 == coordYPos2;
}

void caminoLibre(tablero& t, banderitas& b, pos p, bool profunda, string direccion, jugadas& j) {

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
        pair direccionAlternativa("izquierda","derecha");
        pos posicionActual(ejeFijo,ejeVariable);
        pos posicionSiguiente(ejeFijo, ejeVariable+=direccionMovimiento);
    }
    else if(direccion == "abajo") {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = -1;
        ejeTableroRelevante = t[0].size();
        testeoEnRango = ejeVariable > ejeTableroRelevante;
        pair direccionAlternativa("izquierda","derecha");
        pos posicionActual(ejeFijo,ejeVariable);
        pos posicionSiguiente(ejeFijo, ejeVariable+=direccionMovimiento);
    }
    else if(direccion == "izquierda") {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = -1;
        ejeTableroRelevante = t.size();
        testeoEnRango = ejeVariable > ejeTableroRelevante;
        pair direccionAlternativa("arriba","abajo");
        pos posicionActual(ejeVariable,ejeFijo);
        pos posicionSiguiente(ejeVariable+=direccionMovimiento, ejeFijo);
    }
    else if(direccion == "derecha") {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = 1;
        ejeTableroRelevante = t.size();
        testeoEnRango = ejeVariable < ejeTableroRelevante;
        pair direccionAlternativa("arriba","abajo");
        pos posicionActual(ejeVariable,ejeFijo);
        pos posicionSiguiente(ejeVariable+=direccionMovimiento, ejeFijo);
    }


    //Ya tengo las variables del algoritmo determinadas, ahora empiezo a ciclar
    for(;testeoEnRango; ejeVariable+=direccionMovimiento) {
        
        //Chequeo que, de ser profunda y...
        //1. Si la siguiente celda es inválida o choca con banderita/adyacentes
        if(profunda && (ejeVariable+1 == ejeTableroRelevante || minasAdyacentes(t, posicionSiguiente) != 0 || getPosIndexEnBanderitas(b, posicionSiguiente) != -1)) {
            //Cambio la dirección de movimiento, profunda en ambos lados y agrego la jugada al vector
            jugada jugadaActual(posicionActual, minasAdyacentes(t, posicionActual));
            j.push_back(jugadaActual);
            caminoLibre(t, b, p, true, direccionAlternativa.first, j);
            caminoLibre(t, b, p, true, direccionAlternativa.second, j);
        }

        //2. Si la siguiente celda es válida y no choca con banderita/adyacentes
        else if(profunda && minasAdyacentes(t, posicionSiguiente) == 0 && getPosIndexEnBanderitas(b, posicionSiguiente) == -1) {
            //Agrego jugada en el vector (falta agregar)
            jugada jugadaActual(posicionActual, minasAdyacentes(t, posicionActual));
            j.push_back(jugadaActual);
            //Busco hacia direcciones alternativas
            caminoLibre(t, b, p, false, direccionAlternativa.first, j);
            caminoLibre(t, b, p, false, direccionAlternativa.second, j);
        }

        //La búsqueda entonces es no profunda. Me fijo si tengo adyacentes/banderitas
        //3. De haber adyacentes/banderitas, corto la búsqueda
        if(minasAdyacentes(t, posicionActual) == 0 || getPosIndexEnBanderitas(b, posicionActual) == -1) {
                break;
        }
        else {
        //No hay adyacentes/banderitas, agrego la jugada y sigo
            jugada jugadaActual(posicionActual, minasAdyacentes(t, posicionActual));
            j.push_back(jugadaActual);
        }
    }
}