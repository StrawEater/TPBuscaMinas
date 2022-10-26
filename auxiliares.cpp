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

vector<pos> caminosAutomaticos(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY) {
    vector<pos> caminos;
    //Me falta declarar el vector para que caminosAutomaticos pushee todo, y poder pasarlo como referencia
    busqueda(t, b, p ,j, tamTableroX, tamTableroY, "arriba", true);
    
    busquedaAbajoProfunda(t, b, p ,j, tamTableroX, tamTableroY);
    busquedaArribaProfunda(t, b, p ,j, tamTableroX, tamTableroY);
    busquedaDerechaProfunda(t, b, p ,j, tamTableroX, tamTableroY);
    busquedaIzquierdaProfunda(t, b, p ,j, tamTableroX, tamTableroY);
}

//Dado un tablero con banderitas, un set de jugadas, una direccion y el tipo de busqueda (bool profunda), devuelve un vector con los caminos libres
//Profunda determina si al ir en una direccion y dar con un casillero no jugable (bonba adyacente o banderita) el algoritmo entra o no a buscar en otras direcciones a partir del punto de conflicto
void busqueda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY, string direccion, bool profunda) {
    int ejeFijo, ejeVariable, direccionMovimiento, tamTableroRelevante;
    
    //Un gran "if" para determinar la dirección en la que me voy a mover y la guarda del tablero
    if(direccion == "arriba") {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = -1;
        tamTableroRelevante = t.size();
    }
    else if (direccion == "abajo")
    {
        ejeFijo = p.first;
        ejeVariable = p.second;
        direccionMovimiento = 1;
        tamTableroRelevante = t.size();
    }
    else if (direccion == "izquierda")
    {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = -1;
        tamTableroRelevante = t[0].size();
    }
    else if (direccion == "derecha")
    {
        ejeFijo = p.second;
        ejeVariable = p.first;
        direccionMovimiento = 1;
        tamTableroRelevante = t[0].size();
    }
    
    pos posicionTesteada;

    for(ejeVariable+1;ejeVariable<(tamTableroRelevante-ejeVariable);ejeVariable++) {//Mientras recorro y no me pase del tamaño del tablero...
        pair busquedaAlternativa("","");
        if(direccion == "arriba" || direccion == "abajo") { //Determino la posición donde busco minas adyacentes y banderitas, y en que direccion buscar si la busqueda es profunda
            posicionTesteada = pos(ejeFijo,ejeVariable);
            busquedaAlternativa = pair("izquierda","derecha");
        }
        else if(direccion == "izquierda" || direccion == "derecha") {//Escribo solo para que se entienda mejor
            posicionTesteada = pos(ejeVariable,ejeFijo);
            busquedaAlternativa= pair("arriba","abajo");
        }

        //Si hay minas adyacentes o banderitas en el casillero que testeo hacia arriba y la busqueda es profunda, cambio la direccion de busqueda
        if(minasAdyacentes(t, posicionTesteada) != 0 || getPosIndexEnBanderitas(b, posicionTesteada) == -1) {
            busqueda(t, b, p ,j ,tamTableroX, tamTableroY, "izquierda", true);
            busqueda(t, b, p ,j ,tamTableroX, tamTableroY, "derecha", true);
            break;
        }
        
        //En caso de que subir sea seguro, procedo a liberar todos los casilleros laterales o superioes/inferiores seguros
        busqueda(t, b, posicionTesteada, j, tamTableroX, tamTableroY, busquedaAlternativa.first,false);
        busqueda(t, b, posicionTesteada, j, tamTableroX, tamTableroY, busquedaAlternativa.second, false);

    }
    
}


/*
//Dado un tablero con banderitas y una posición, realiza una busqueda hacia arriba descubriendo todos los caminos rectos libres hacia ambos laterales.
//De toparse con una bomba hacia arriba, cambia el modo de búsqueda a izquierda/derecha profunda
void busquedaArribaProfunda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY) {
    for(int ejeY=p.second+1; ejeY<tamTableroY; ejeY++) { //Mientras recorro hacia arriba y no me pase del tamaño del tablero...
    pos posicionTesteada(p.first,ejeY);

    //Inicializo el vector que almacenara todas las posiciones a jugar
    vector<pos> jugadasFuturas;

        //Si hay minas adyacentes o banderitas en el casillero que testeo hacia arriba, cambio a modo búsqueda en laterales
        if(minasAdyacentes(t, posicionTesteada) != 0 || getPosIndexEnBanderitas(b, posicionTesteada) == -1) {
            busquedaIzquierdaProfunda(t, b, p ,j ,tamTableroX, tamTableroY);
            busquedaDerechaProfunda(t, b, p ,j ,tamTableroX, tamTableroY);
        }

        //En caso de que subir sea seguro, procedo a liberar todos los casilleros a izquierda y derecha seguros
        busquedaIzquierda(t, b, p, j, tamTableroX, tamTableroY, ejeY);
        busquedaDerecha(t, b, p, j, tamTableroX, tamTableroY, ejeY);
    }
}

void busquedaAbajoProfunda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY) {
    for(int ejeY=p.second+1; ejeY<tamTableroY; ejeY++) { //Mientras recorro hacia arriba y no me pase del tamaño del tablero...
    pos posicionTesteada(p.first,ejeY);

    //Inicializo el vector que almacenara todas las posiciones a jugar
    vector<pos> jugadasFuturas;

        //Si hay minas adyacentes o banderitas en el casillero que testeo hacia arriba, cambio a modo búsqueda en laterales
        if(minasAdyacentes(t, posicionTesteada) != 0 || getPosIndexEnBanderitas(b, posicionTesteada) == -1) {
            busquedaIzquierdaProfunda(t, b, p ,j ,tamTableroX, tamTableroY);
            busquedaDerechaProfunda(t, b, p ,j ,tamTableroX, tamTableroY);
        }

        //En caso de que subir sea seguro, procedo a liberar todos los casilleros a izquierda y derecha seguros
        busquedaIzquierda(t, b, p, j, tamTableroX, tamTableroY, ejeY);
        busquedaDerecha(t, b, p, j, tamTableroX, tamTableroY, ejeY);
    }
}

void busquedaIzquierda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY, int ejeY) {
    for(int ejeX=p.first-1; ejeX<tamTableroX;ejeX--) {//Busco hacia la izquierda
        pos posicionTesteada(ejeX,ejeY);
        
        //Si hay minas adyacentes o banderitas, corto la búsqueda hacia la izquierda
        if(minasAdyacentes(t, posicionTesteada) || getPosIndexEnBanderitas(b, posicionTesteada) == -1) {
            break;
        }

    }
}

void busquedaDerecha(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY, int ejeY) {
    for(int ejeX=p.first+1; ejeX<tamTableroX;ejeX++) {//Busco hacia la derecha
        pos posicionTesteada(ejeX,ejeY);

        //Si hay minas adyacentes o banderitas, corto la búsqueda hacia la derecha
        if(minasAdyacentes(t, posicionTesteada) || getPosIndexEnBanderitas(b, posicionTesteada) == -1) {
            break;
        }
    }
}
*/