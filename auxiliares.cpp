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

//Dada una Posicion y un Vector de Banderitas, encuentra el index dentro del vector,
// si este no se encuentra en el, devuelve -1.
int getPosIndexEnBanderitas(banderitas& b, pos p){
    for (int i = 0; i < b.size(); ++i) {
        pos posBanderita = b[i];
        if (sonPosIguales(posBanderita,p)){
            return i;
        }
    }
    return -1;
}

//Dada una Posicion y un Vector de Jugadas, encuentra el index dentro del vector,
// si este no se encuentra en el, devuelve -1.
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

//Compara dos objetos posiciones y verifica que contenga los mismos valores en la misma posicion
bool sonPosIguales(pos p1, pos p2){
    int coordYPos1 = p1.first;
    int coordXPos1 = p1.second;

    int coordYPos2 = p2.first;
    int coordXPos2 = p2.second;

    return coordXPos1 == coordXPos2 && coordYPos1 == coordYPos2;
}

//Verifica que la pos no se encuentre en el borde del tablero t
bool noBorde(tablero t, pos p){
    return (0<p.first && p.first<t.size()-1)&&(0<p.second && p.second<t.size()-1);
}
//Verifica si la pos se encuentra dentro del vector de jugadas
bool esJugada(jugadas j,pos p){
    return (getPosIndexEnJugadas(j,p)!=-1);
}

//Verifica si la pos se encuentra dentro del vector de banderitas
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

//Verifica que la posicion Dada no sea una jugada ni una banderita y que se encuentra dentro del tablero
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

bool jugadaHecha(jugada jugadaChequeada, jugadas juego) {
    for(int i=0;i<juego.size();i++) {
        if(juego[i].first == jugadaChequeada.first) {
            return true;
            break;
        }
    return false;
}
}

void caminoLibre(tablero& t, banderitas& b, pos p, bool profunda, string direccion, jugadas& j) {

    //Primero determino en base a la direccion el modo de funcionamiento del algoritmo
    int ejeFijo, ejeVariable, direccionMovimiento, ejeTableroRelevante;
    bool testeoEnRango;
    pair<string,string> direccionAlternativa;
    pos posicionActual, posicionAnterior;

    if(direccion == "arriba") {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = 1;
        ejeTableroRelevante = t[0].size();
        testeoEnRango = ejeVariable < ejeTableroRelevante;
        pair<string,string> direccionAlternativa("izquierda","derecha");
        pos posicionActual(ejeFijo,ejeVariable);
        pos posicionAnterior(ejeFijo, ejeVariable-=direccionMovimiento);
    }
    else if(direccion == "abajo") {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = -1;
        ejeTableroRelevante = t[0].size();
        testeoEnRango = ejeVariable > ejeTableroRelevante;
        pair<string,string> direccionAlternativa("izquierda","derecha");
        pos posicionActual(ejeFijo,ejeVariable);
        pos posicionAnterior(ejeFijo, ejeVariable-=direccionMovimiento);
    }
    else if(direccion == "izquierda") {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = -1;
        ejeTableroRelevante = t.size();
        testeoEnRango = ejeVariable > ejeTableroRelevante;
        pair<string,string> direccionAlternativa("arriba","abajo");
        pos posicionActual(ejeVariable,ejeFijo);
        pos posicionAnterior(ejeVariable-=direccionMovimiento, ejeFijo);
    }
    else if(direccion == "derecha") {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = 1;
        ejeTableroRelevante = t.size();
        testeoEnRango = ejeVariable < ejeTableroRelevante;
        pair<string,string> direccionAlternativa("arriba","abajo");
        pos posicionActual(ejeVariable,ejeFijo);
        pos posicionAnterior(ejeVariable-=direccionMovimiento, ejeFijo);
    }


    //Ya tengo las variables del algoritmo determinadas, ahora empiezo a ciclar
    for(;testeoEnRango; ejeVariable+=direccionMovimiento) {
        
        //Armo la jugada que luego testeo si necesito agregar
        jugada jugadaActual(posicionActual, minasAdyacentes(t, posicionActual));


        //1. Si la celda es profunda y es banderita o mina, le pido que busque a partir de la dirección anterior hacia las direcciones alternativas profundo
        if(profunda && (getPosIndexEnBanderitas(b,posicionActual) || t[posicionActual.first][posicionActual.second] == true)) {
            caminoLibre(t, b, posicionAnterior, true, direccionAlternativa.first, j);
            caminoLibre(t, b, posicionAnterior, true, direccionAlternativa.second, j);
            break;

        //2. Si la celda es banderita o mina (no profunda), corto la bùsqueda
        if(getPosIndexEnBanderitas(b,posicionActual) || t[posicionActual.first][posicionActual.second] == true) {
            break;
        }

        //3. No choca con banderita y no es mina. Agrego la jugada. Si es profunda sigo la búsqueda y busco hacia ambos lados alternativos
        if(!esJugada(j, posicionActual) && profunda) {
            j.push_back(jugadaActual);
            caminoLibre(t, b, p, false, direccionAlternativa.first, j);
            caminoLibre(t, b, p, false, direccionAlternativa.second, j);
        }

        //4. No choca con banderita, no es mina ni profunda. Entonces agrego la jugada
        if(!esJugada(j, posicionActual) && !profunda) {
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
}