//
// Created by clinux01 on 26/10/22.
//

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

#pragma region Tableros

#pragma region Tablero1
//┌───┬───┬───┬───┬───┐
//│ * │ * │ b │ ■ │ 1 │
//├───┼───┼───┼───┼───┤
//│ b │ 3 │ 3 │ * │ b │
//├───┼───┼───┼───┼───┤
//│ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┤
//│ 2 │ 3 │ 2 │ ■ │ 0 │
//├───┼───┼───┼───┼───┤
//│ * │ b │ * │ ■ │ 0 │
//└───┴───┴───┴───┴───┘

static tablero t1 = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

static banderitas banderitasTab1 = {
        pos(0,2),
        pos(1,2),pos(1,4),
        //
        //
        pos(4,1),
};

static jugadas jugadasTab1 = {
        jugada(pos(0, 3), 1),
        //
        jugada(pos(3, 3), 0),
        jugada(pos(4, 3), 1),
};

#pragma endregion Tablero1

#pragma region Tablero2
//┌───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ * │ 2 │ ■ │ b │
//├───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ 1 │ 2 │ 1 │ 2 │ * │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ B │ 1 │ 0 │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 2 │ ■ │ 1 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ b │ ■ │ * │ 2 │ 1 │ b │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ b │ ■ │ 1 │ 2 │ * │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤
//│ * │ ■ │ 0 │ 1 │ 1 │ 1 │ 0 │
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

static banderitas banderitasTab2 = {
        pos(0,6),
        //
        pos(2,1),
        //
        pos(4,0),pos(4,5),
        pos(5,0),
        //

};

static jugadas jugadasTab2 = {
        jugada(pos(0, 0), 0), jugada(pos(0, 1), 0),jugada(pos(0, 2), 1), jugada(pos(0, 5), 1),
        jugada(pos(1, 0), 1),
        //
        jugada(pos(3, 2), 2),
        jugada(pos(4, 1), 1),
        jugada(pos(5, 1), 2),
        jugada(pos(6, 1), 1),
};

#pragma endregion Tablero2

#pragma region Tablero3
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

#pragma endregion Tablero3

#pragma region Tablero4
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

#pragma endregion Tablero4

#pragma endregion Tableros

void printTablero(tablero ts, banderitas banderitasTab, jugadas jugadasTab){
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
            if (getPosIndexEnJugadas(jugadasTab,pos(i,j)) != -1){
                cout<<" ■ ";
            } else if(getPosIndexEnBanderitas(banderitasTab,pos(i,j)) != -1){
                if (ts[i][j]){
                    cout<<" B ";
                } else{
                    cout<<" b ";
                }
            } else if (ts[i][j]){
                cout<<" * ";
            }else{
                string minasAdy = std::to_string(minasAdyacentes(ts,pos(i,j)));
                cout<<" "+ minasAdy + " ";

            }
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


TEST(buscarCaminoLibre, imprimirAlgo){
    printTablero(t2, banderitasTab2, jugadasTab2);
    ASSERT_TRUE(true);
}

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

TEST(buscarCaminoLibre, tablero1pos_4_0){
    pos posJugada = pos(4,0);
    jugadas jugadasEsperadas = {
            jugada(pos(4, 0), 1),
            };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero1pos_4_4){
    pos posJugada = pos(4,4);
    jugadas jugadasEsperadas = {
            jugada(pos(4, 3), 0),
            jugada(pos(4, 4), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero2pos_4_4){
    pos posJugada = pos(4,4);
    jugadas jugadasEsperadas = {
            jugada(pos(4, 3), 0),
            jugada(pos(4, 4), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}