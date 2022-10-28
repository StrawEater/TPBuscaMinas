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
//│ 0 │ 1 │ 1 │ 1 │ 1 │ * │
//├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ * │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┤
//│ 0 │ 2 │ 2 │ 2 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┤
//│ 1 │ 2 │ 1 │ 2 │ * │ 1 │
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

static banderitas banderitasTab3 = {
        pos(0,5),
        pos(1,2),
        pos(3,2),
        //
        //

};

static jugadas jugadasTab3 = {
        jugada(pos(0, 0), 0), jugada(pos (0, 1), 1), jugada(pos (0, 2), 1),
        jugada(pos (1, 5), 1),
        jugada(pos (4, 0), 1), jugada(pos (4, 1), 2)
        //
};

#pragma endregion Tablero3

#pragma region Tablero4
//┌───┬───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ 0 │ 0 │ 0 │ 1 │ 1 │ b │ B │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 1 │ 0 │ 1 │ * │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ B │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ 1 │ 1 │ 0 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 0 │ 1 │ 1 │ 1 │ 0 │ ■ │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 0 │ 1 │ * │ 1 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 0 │ 1 │ 1 │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ 0 │ 0 │ 0 │ 0 │ 0 │ 1 │ * │
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

static banderitas banderitasTab4 = {
        pos(0,0), pos(0,6), pos(0,7),
        //
        pos (2,1)
        //

};

static jugadas jugadasTab4 = {
        jugada(pos(0, 0), 0),
        jugada(pos(2,0), 1),
        jugada(pos(3,0), 1),
        jugada(pos(4,0), 1), jugada(pos(4,1), 1), jugada( pos(4, 7), 0),
        jugada(pos(7,0), 1)
        //
};

#pragma endregion Tablero4

#pragma endregion Tableros

TEST(buscarCaminoLibre, imprimirAlgo){
    printTablero(t4, {banderitasTab4}, {jugadasTab4});
    ASSERT_TRUE(true);
}

bool mismasJugadas(jugadas jugadasEsperadas, jugadas jugadasDevueltas){
    for (int i = 0; i < jugadasEsperadas.size(); ++i) {
        bool encontrada = false;
        for (int j = 0; j < jugadasDevueltas.size(); ++j) {
            if (sonPosIguales(jugadasDevueltas[j].first, jugadasEsperadas[i].first)){
                encontrada = true;
                if (jugadasDevueltas[j].second != jugadasEsperadas[i].second){
                    return false;
                }
                break;
            }
        }
        if (!encontrada) return false;
    }
    return jugadasEsperadas.size() == jugadasDevueltas.size();
}

#pragma region TestTablero1

TEST(buscarCaminoLibre, tablero1pos_0_4){
    pos posJugada = pos(0,4);
    jugadas jugadasEsperadas = {
            jugada(pos(0, 4), 1),
            };
    jugadas jugadasDevueltas = {jugada(pos(0, 4), 1),};
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
            jugada(pos(3, 4), 0),
            jugada(pos(4, 4), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 4), 0), jugada(pos(3, 4), 0)};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

#pragma endregion TestTablero1

#pragma region TestTablero2
TEST(buscarCaminoLibre, tablero2pos_6_6){
    pos posJugada = pos(6,6);
    jugadas jugadasEsperadas = {
            jugada(pos(6, 6), 0),
            jugada(pos(5, 6), 0),
            jugada(pos(4, 6), 0),
            jugada(pos(3, 6), 0),
            jugada(pos(3, 5), 0),
            jugada(pos(3, 4), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 4), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero2pos_6_2){
    pos posJugada = pos(6,2);
    jugadas jugadasEsperadas = {
            jugada(pos(6, 2), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(6, 2), 0),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero2pos_3_0){
    pos posJugada = pos(3,0);
    jugadas jugadasEsperadas = {
            jugada(pos(3, 0), 1),
    };
    jugadas jugadasDevueltas = {jugada(pos(3, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero2pos_2_3){
    pos posJugada = pos(2,3);
    jugadas jugadasEsperadas = {
            jugada(pos(2, 3), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(2, 3), 0),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero2pos_2_6){
    pos posJugada = pos(2,6);
    jugadas jugadasEsperadas = {
            jugada(pos(2, 6), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(2, 6), 0),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

#pragma endregion TestTablero2

#pragma region TestTablero3

TEST(buscarCaminoLibre, tablero3pos_1_0){
    pos posJugada = pos(1,0);
    jugadas jugadasEsperadas = {
            jugada(pos(1, 0), 0),
            jugada(pos(2, 0), 0),
            jugada(pos(3, 0), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(1, 0), 0),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero3pos_2_5){
    pos posJugada = pos(2,5);
    jugadas jugadasEsperadas = {
            jugada(pos(2, 5), 0),
            jugada(pos(2, 4), 0),
    };
    jugadas jugadasDevueltas = {jugada(pos(2, 5), 0),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero3pos_3_3){
    pos posJugada = pos(3,3);
    jugadas jugadasEsperadas = {
            jugada(pos(3, 3), 2),
    };
    jugadas jugadasDevueltas = {jugada(pos(3, 3), 2),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

#pragma endregion TestTablero3

TEST(buscarCaminoLibre, tablero4pos_0_0){
    pos posJugada = pos(0,0);
    jugadas jugadasEsperadas = {
            jugada(pos(0, 0), 0),
            jugada(pos(0, 1), 0),
            jugada(pos(0, 2), 0),
            jugada(pos(0,3), 0),
            jugada(pos(1,3), 0),
            jugada(pos(2,3), 0),
            jugada(pos(2,7), 0),
            jugada(pos(3,3), 0),
            jugada(pos(3,4), 0),
            jugada(pos(3,5), 0),
            jugada(pos(3,6), 0),
            jugada(pos(3,7), 0),
            jugada(pos(4,6), 0),
            jugada(pos(4,7), 0),
            jugada(pos(5,6), 0),
            jugada(pos(5,7), 0)
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}


TEST(buscarCaminoLibre, tablero4pos_7_0){
    pos posJugada = pos(7,0);
    jugadas jugadasEsperadas = {
            jugada(pos(7,0),0),
            jugada(pos(7, 1), 0),
            jugada(pos(7, 2), 0),
            jugada(pos(7, 3), 0),
            jugada(pos(7, 4), 0),
            jugada(pos(7, 5), 0),
            jugada(pos(6, 2), 0),
            jugada(pos(5, 2), 0),
            jugada(pos(4, 2), 0)

    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}


TEST(buscarCaminoLibre, tablero4pos_5_5){
    pos posJugada = pos(5,5);
    jugadas jugadasEsperadas = {
            jugada(pos(5, 5), 1),
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero4pos_3_2){
    pos posJugada = pos(3,2);
    jugadas jugadasEsperadas = {
            jugada(pos(3,2),1),
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}

TEST(buscarCaminoLibre, tablero4pos_4_7){
    pos posJugada = pos(4,7);
    jugadas jugadasEsperadas = {
            jugada(pos(0, 0), 0),
            jugada(pos(0, 1), 0),
            jugada(pos(0, 2), 0),
            jugada(pos(0,3), 0),
            jugada(pos(1,3), 0),
            jugada(pos(2,3), 0),
            jugada(pos(2,7), 0),
            jugada(pos(3,3), 0),
            jugada(pos(3,4), 0),
            jugada(pos(3,5), 0),
            jugada(pos(3,6), 0),
            jugada(pos(3,7), 0),
            jugada(pos(4,6), 0),
            jugada(pos(4,7), 0),
            jugada(pos(5,6), 0),
            jugada(pos(5,7), 0)
    };
    jugadas jugadasDevueltas = {jugada(pos(4, 0), 1),};
    if (minasAdyacentes(t1,posJugada) > 0){
        ASSERT_TRUE(jugadasDevueltas.size() == 1 && sonPosIguales(jugadasDevueltas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasDevueltas);
        ASSERT_TRUE(sonMismasJugadas);
    }

}