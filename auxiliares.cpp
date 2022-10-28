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