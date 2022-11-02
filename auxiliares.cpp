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
//COMPLEJIDAD = 1.
bool posicionValida(tablero& t, pos p){
    int columna = p.second; // Complejidad: 1 (instruccion basica)
    int fila = p.first; // Complejidad: 1 (instruccion basica)
    bool FilaValida = fila >= 0 && fila < t.size(); // Complejidad: 1 (instruccion basica)
    bool ColumnaValida = columna >= 0 && columna < t[0].size(); // Complejidad: 1 (instruccion basica)
    return FilaValida && ColumnaValida; // Complejidad: 1 (instruccion basica)
}

//Dada una Posicion y un Vector de Banderitas, encuentra el index dentro del vector,
// si este no se encuentra en el, devuelve -1.
// COMPLEJIDAD : n
int getPosIndexEnBanderitas(banderitas& b, pos p){
    for (int i = 0; i < b.size(); ++i) { // Complejidad: n (Se hace la verificacion un total de n veces)
        pos posBanderita = b[i]; // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)
        if (sonPosIguales(posBanderita,p)){ // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)
            return i; // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)
        }
    }
    return -1; // Complejidad: 1
}
//Dada una Posicion y un Vector de Jugadas, encuentra el index dentro del vector,
// si este no se encuentra en el, devuelve -1.
// COMPLEJIDAD: n
int getPosIndexEnJugadas(jugadas& j, pos p){

    for (int i = 0; i < j.size(); ++i) { // Complejidad: n (Se hace la verificacion un total de n veces)
        pos posJugada = j[i].first; // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)

        if (sonPosIguales(posJugada,p)){ // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)
            return i; // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)
        }
    }
    return -1; // Complejidad: 1
}

//Devuelve un vector de tipo Banderita indentico al argumento, excepto por no conterner
//al elemento que se encontraba en indexPosicion
// COMPLEJIDAD: n
void eliminarPosicionDeBanderita(banderitas& b, int indexPosicion){
    banderitas nuevoVectorBanderitas; // Complejidad: 1 (Instruccion Basica)
    for (int i = 0; i < b.size(); ++i) { // Complejidad: n (Se hace la verificacion un total de n veces)
        // Si el elemento no se encuentra en el index que quiero eliminar, lo agrego al nuevo Vector
        // Si el index es el mismo, no lo agrego
        if (i != indexPosicion) nuevoVectorBanderitas.push_back(b[i]); // Complejidad: n-1 (La instruccion basica sucede n-1 veces, ya que a la enesima vez i=n y escapa del for)
    }
    //Modifico el vector original por el vector sin el elemento que queria eliminar.
    b = nuevoVectorBanderitas; // Complejidad: 1
}


//Compara dos objetos posiciones y verifica que contenga los mismos valores en la misma posicion
// COMPLEJIDAD: 1
bool sonPosIguales(pos p1, pos p2){
    int coordYPos1 = p1.first; // Complejidad: 1 (Instruccion Basica)
    int coordXPos1 = p1.second; // Complejidad: 1 (Instruccion Basica)

    int coordYPos2 = p2.first; // Complejidad: 1 (Instruccion Basica)
    int coordXPos2 = p2.second; // Complejidad: 1 (Instruccion Basica)

    return coordXPos1 == coordXPos2 && coordYPos1 == coordYPos2; // Complejidad: 1 (Instruccion Basica)
}

bool esJugada(jugadas j,pos p){
    return (getPosIndexEnJugadas(j,p)!=-1); // Complejidad: n + 1 (getPosIndexEnJugadas tiene complejidad n y la comparacion tiene complejida 1)
}

//Verifica si la pos se encuentra dentro del vector de banderitas
// COMPLEJIDAD: n
bool noEsBanderita(banderitas b, pos p){
    return (getPosIndexEnBanderitas(b,p)==-1); // Complejidad: n + 1 (getPosIndexEnJugadas tiene complejidad n y la comparacion tiene complejida 1)
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
//COMPLEJIDAD:n
bool esValidaYnoBanderitaNiJugada(tablero t,jugadas j, banderitas b, pos p){
    return posicionValida(t,p) && !esJugada(j,p) && noEsBanderita(b,p); // Complejidad: 2n + 1
                                                                        // (posicionValida tiene complejidad 1
                                                                        //  esJugada tiene complejidad n
                                                                        //  noEsBanderita tiene complejidad n)
}


bool patron_Y_Asignacion_A_P(tablero t, jugadas j, banderitas b, bool& valor,pos posA, pos &p, pos posLeft, pos posRight, pos posUp,pos posDown) {
    if (patronVertical(t, j, b,posUp, posDown)) {
        if (esValidaYnoBanderitaNiJugada(t,j, b, posLeft)) {
            p = posLeft;
            valor = true;
        }
        else if (esValidaYnoBanderitaNiJugada(t,j, b, posRight)) {
            p = posRight;
            valor = true;
        } 
        else {}
    } else if (patronHorizontal(t, j, b,posLeft, posRight)) {
        if (esValidaYnoBanderitaNiJugada(t,j, b, posUp)) {
            p = posUp;
            valor = true;
        }
        else if (esValidaYnoBanderitaNiJugada(t,j, b, posDown)) {
            p = posDown;
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
// Verifica que la celda en la posicion pasada cumple las condiciones par ser agregada en jugadas
// - No es una Celda Jugada ni una Banerita
// - La posicion es Valida
//
// Si cumple estas condiciones, agrega la nueva jugada a Jugadas
// Si cumple las condiciones y no tiene bombas adyacenes, llama a esta misma funcion en las celdas vecinas.
// De esta manera, la unica forma que una funcion sea verificada por "caminoLibre2V" es si:
// Es la celda en la pos que paso el usuario.
// Es vecina de una celda con 0 bombas adyacentes que la funcion ya verifico
// Si es la segunda opcion, significa que la celda vecina es la pos Original(con 0 bombas adyacentes) o es vecina de otra celda con 0 bombas adyacentes.
// Si es otra vez la segunda opcion, sucede exactamente la misma situacion, hasta que finalmente alguna celda es vecina de la pos Original.
// De Esta forma si la funcion Verifica a la celda es porque:
// -Es la posicion Original jugada
// -Exite un camino de celdas con 0 bombas adyacentes que va desde la pos Original hasta la celda actual.

//COMPLEJIDAD: La complejidad de un solo "ciclo" es n, y el peor caso es un tablero sin bombas
//             donde la funcion deberia pasar por cada una de las celdas, es decir n^2.
//             Entonces la complejidad sera: n * n^2 = n^3
void caminoLibre2V(tablero& t, banderitas& b, pos p, jugadas& j){
    if (esValidaYnoBanderitaNiJugada(t,j,b,p) && minasAdyacentes(t,p) == 0){ // Complejidad: n+1 (esValidaYnoBanderitaNiJugada tiene complejidad n y minasAdyacentes complejidad 1)
        //Agrego la jugada que representa a la celda a Jugadas
        j.push_back(jugada(p, minasAdyacentes(t,p))); // Complejidad: 1 (Instruccion Basica)
        //LLamo a la funcion en las celdas vecinas
        for (int filaOffset = -1; filaOffset <= 1; ++filaOffset) { // Complejidad: 4 (la verificacion sucede extamente 3 veces)
            for (int columnaOffset = -1; columnaOffset <= 1; ++columnaOffset) { //Complejidad: 12 (la verificacion sucede extamente 3 veces por ciclo)
                //Si la posicion actual es igual a la posicion original, la ignoro
                if (filaOffset == 0 && filaOffset == 0) continue; //Complejidad: 9 (Porque sucede 1 vez por cada ciclo y es instruccion basica)
                //En otro caso, verifico que sea una posicion valida y corro a la funcion en la celda vecina
                pos posicionVecina = pos(p.first + filaOffset,p.second+columnaOffset); //Complejidad: 9 (Porque sucede 1 vez por cada ciclo y es instruccion basica )
                if (posicionValida(t,posicionVecina)){ // Complejidad: 9 (Porque sucede 1 vez por cada ciclo y es instruccion basica )
                    caminoLibre2V(t,b,posicionVecina,j); //Complejidad: 9 (Porque sucede 1 vez por cada ciclo y es instruccion basica )
                }
            }
        }
    }
    else if(esValidaYnoBanderitaNiJugada(t,j,b,p) && minasAdyacentes(t,p) > 0){ // Complejidad: n+1 (esValidaYnoBanderitaNiJugada tiene complejidad n y minasAdyacentes complejidad 1)
        //Agrego la jugada que representa a la celda a Jugadas y termino la funcion, ya que tiene bombas adyacentes
        j.push_back(jugada(p, minasAdyacentes(t,p))); // Complejidad: 1 (Instruccion Basica)
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