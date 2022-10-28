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






/*
Ignorar esto, basura que es mejor no borrar
vector<pos> caminosAutomaticos(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY) {
    vector<pos> caminos;
    //Me falta declarar el vector para que caminosAutomaticos pushee todo, y poder pasarlo como referencia
    busqueda(t, b, p ,j, tamTableroX, tamTableroY, "arriba", true);
    busqueda(t, b, p ,j, tamTableroX, tamTableroY, "abajo", true);
    busqueda(t, b, p ,j, tamTableroX, tamTableroY, "derecha", true);
    busqueda(t, b, p ,j, tamTableroX, tamTableroY, "izquierda", true);
}

//Dado un tablero con banderitas, un set de jugadas, una direccion y el tipo de busqueda (bool profunda), devuelve un vector con los caminos libres
//Profunda determina si al ir en una direccion y dar con un casillero no jugable (bonba adyacente o banderita) el algoritmo entra o no a buscar en otras direcciones a partir del punto de conflicto
void busqueda(tablero& t, banderitas& b, pos p, jugadas& j, int tamTableroX, int tamTableroY, string direccion, bool profunda) {
    int ejeFijo, ejeVariable, direccionMovimiento, tamTableroRelevante;
    pos posicionTesteada;

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
        if(profunda && (minasAdyacentes(t, posicionTesteada) != 0 || getPosIndexEnBanderitas(b, posicionTesteada) == -1)) {
            busqueda(t, b, p ,j ,tamTableroX, tamTableroY, busquedaAlternativa.first, true);
            busqueda(t, b, p ,j ,tamTableroX, tamTableroY, busquedaAlternativa.second, true);
            break;
        }

        //Si no hay minas adyacentes ni banderitas, empiezo a buscar en ambas direcciones
        


        //Si la busqueda es profunda y llego hasta acá, entonces empiezo a buscar los laterales
        if(profunda) {
            busqueda(t, b, p ,j ,tamTableroX, tamTableroY, "izquierda", false);
            busqueda(t, b, p ,j ,tamTableroX, tamTableroY, "derecha", false);
            break;
        }

        //Si hay minas adyacentes o banderitas, corto la búsqueda
        if(!profunda && (minasAdyacentes(t, posicionTesteada) != 0 || getPosIndexEnBanderitas(b, posicionTesteada) == -1)) {
            break;
        }

        //De llegar hasta acá, el casillero no tiene minas adyacentes/banderitas y es seguro de jugar
        if(profunda && (minasAdyacentes(t,posicionTesteada) == 0 ))
        
        //En caso de que subir sea seguro, procedo a liberar todos los casilleros laterales o superioes/inferiores seguros
        busqueda(t, b, posicionTesteada, j, tamTableroX, tamTableroY, busquedaAlternativa.first,false);
        busqueda(t, b, posicionTesteada, j, tamTableroX, tamTableroY, busquedaAlternativa.second, false);


    //Falta implementar el vector que almacena las jugadas hechas, y purgar las jugadas repetidas
    //Falta implementar el proceso a seguir cuando no es profunda y se topa con adyacentes o banderitas
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