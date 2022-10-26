//
// Created by clinux01 on 26/10/22.
//

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘

static tablero t1 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

static banderitas banderitasTab1 = {
        pos(2,0),
        pos(4,1),pos(0,1),
        pos(1,4),
};

static jugadas jugadasTab1 = {
        jugada(pos(2, 0), 2), jugada(pos(3, 2), 2), jugada(pos(4, 0), 0),
        jugada(pos(4, 3), 0),
};



//┌───┬───┬───┬───┬───┬───┬───┐
//│ 0 │ 1 │ 1 │ * │ 0 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ 0 │ 2 │ 1 │ * │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ * │ 1 │ 2 │ 0 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ 0 │ 1 │ 2 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 2 │ 2 │ * │ 0 │ 1 │ 0 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 0 │ 1 │ 0 │ * │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 1 │ 0 │ 0 │ 0 │ 0 │
//└───┴───┴───┴───┴───┴───┴───┘
static tablero t2 = {
        { cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA },
        { cVACIA, cMINA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA },
        { cMINA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
};

//┌───┬───┬───┬───┬───┬───┐
//│ 0 │ 0 │ 0 │ 0 │ 1 │ * │
//├───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ * │ 1 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┤
//│ 1 │ 0 │ 2 │ 0 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ * │ 2 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 0 │ 1 │ * │ 1 │
//├───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 0 │ 1 │ 1 │ 1 │
//└───┴───┴───┴───┴───┴───┘
static tablero t3 = {
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA},
        { cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA},
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        { cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA},
        { cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA},
        { cMINA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
};

//┌───┬───┬───┬───┬───┬───┬───┬───┐
//│ 0 │ 1 │ 1 │ 1 │ 1 │ 0 │ 1 │ * │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ 0 │ 1 │ 1 │ * │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 0 │ * │ 1 │ 1 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 0 │ 0 │ 0 │ 0 │ 1 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 1 │ 0 │ 1 │ 0 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ * │ 0 │ 1 │ 0 │ * │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 2 │ 2 │ 1 │ 0 │ 0 │ 0 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ 0 │ 0 │ 0 │ 0 │ 1 │ * │
//└───┴───┴───┴───┴───┴───┴───┴───┘
static tablero t4 = {
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA },
        { cVACIA, cMINA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA },
};

void printTablero(tablero ts){
    for (int i = 0; i < ts.size(); ++i) {
        cout << "//";
        for (int j = 0; j < ts[0].size(); ++j){

            if (j == 0){

                if (i == 0) {
                    cout << "┌";
                }else{
                    cout << "├";
                }
            }else{
                if (i == 0) {
                    cout<<"┬";
                }else{
                    cout << "┼";
                }
            }
            cout<<"───";
        }
        if (i == 0) {
            cout<<"┐";
        }else{
            cout << "┤";
        }
        cout<<"\n";
        cout << "//";
        for (int j = 0; j < ts[0].size(); ++j){
            cout<<"│";
            string minasAdy = ts[i][j] ? "*" : std::to_string(minasAdyacentes(ts,pos(i,j)));
            cout<<" "+ minasAdy + " ";
        }
        cout<<"│";
        cout<<"\n";
    }
    for (int j = 0; j < ts[0].size(); ++j){
        if (j == 0){
            cout << "//";
            cout<<"└";
        }else{
            cout<<"┴";
        }
        cout<<"───";
    }
    cout<<"┘";
    cout<<"\n";


}
/*
TEST(buscarCaminoLibre, imprimirAlgo){
    printTablero(t4);
    ASSERT_TRUE(true);
}
 */
jugadas caminoLibre(){
    return {};
}

bool mismasJugadas(jugadas jugadasEsperadas, jugadas jugadasDevueltas){
    for (int i = 0; i < jugadasEsperadas.size(); ++i) {
        bool encontrada = false;
        for (int j = 0; j < jugadasDevueltas.size(); ++j) {
            if (sonPosIguales(jugadasDevueltas[j].first, jugadasEsperadas[i].first)){
                encontrada = true;
                break;
            }
        }
        if (!encontrada) return false;
    }
    return jugadasEsperadas.size() == jugadasDevueltas.size();
}

bool diferentesJugadas(jugadas jugadasAntiguas, jugadas jugadasDevueltas){
    for (int i = 0; i < jugadasAntiguas.size(); ++i) {
        for (int j = 0; j < jugadasDevueltas.size(); ++j) {
            if (sonPosIguales(jugadasDevueltas[j].first, jugadasAntiguas[i].first)){
                return false;
            }
        }
    }
    return true;
}

bool listaUnica(jugadas jugadasDevueltas){
    for (int i = 0; i < jugadasDevueltas.size(); ++i) {
        for (int j = i+1; j < jugadasDevueltas.size(); ++j) {
            if (sonPosIguales(jugadasDevueltas[i].first, jugadasDevueltas[j].first)){
                return false;
            }
        }
    }
}

bool JugadasValidasSinBanderaSinYaJugada(tablero ts, banderitas b, jugadas jugadasOriginales, jugadas jugadasDevueltas){

    if (!diferentesJugadas(jugadasOriginales,jugadasDevueltas)){
        return false;
    }

    for (int i = 0; i < jugadasDevueltas.size(); ++i) {
        if (getPosIndexEnBanderitas(b,jugadasDevueltas[i].first) != -1){
            return false;
        }
        if (!posicionValida(ts, jugadasDevueltas[i].first)){
            return false;
        }
    }
    return true;
}

TEST(buscarCaminoLibre, tablero1pos_4_0){
    pos posicionJugada = pos(4,0);
    jugadas jugadasEsperadas = {
            jugada(pos(4, 0), 1),
            };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    bool esListaUnica = listaUnica(jugadasDevueltas);
    bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
    bool todasJugadasValidas = JugadasValidasSinBanderaSinYaJugada(t1,banderitasTab1,jugadasTab1,jugadasDevueltas)
    ASSERT_TRUE(esListaUnica && sonMismasJugadas);
}