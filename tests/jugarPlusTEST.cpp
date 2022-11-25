//
// Created by clinux01 on 26/10/22.
//

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

// SIMBOLOGIA:
// - [0,9] = CELDA NO JUGADO CON N BOMBAS ADYACENTES
// - * = CELDA CON BOMBA NO JUGADA
// - b = CELDA CON BANDERITA SIN BOMBA
// - B = CELDA CON BANDERITA Y BOMBA
// - ■ = CELDA JUGADA

// SI EL TABLERO TIENE JUGADAS O BANDERITAS SE AGREGA A LA DERECHA EL TABLERO SIN JUGAR.

#pragma region Tableros

#pragma region Tablero1
//┌───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┐
//│ * │ * │ b │ ■ │ 1 │ //│ * │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┤
//│ b │ 3 │ 3 │ * │ b │ //│ 3 │ 3 │ 3 │ * │ 1 │
//├───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┤
//│ 1 │ * │ 2 │ 1 │ 1 │ //│ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┤
//│ 2 │ 3 │ 2 │ ■ │ 0 │ //│ 2 │ 3 │ 2 │ 1 │ 0 │
//├───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┤
//│ * │ b │ * │ ■ │ 0 │ //│ * │ 2 │ * │ 1 │ 0 │
//└───┴───┴───┴───┴───┘ //└───┴───┴───┴───┴───┘

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
//┌───┬───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ * │ 2 │ ■ │ b │ //│ 0 │ 0 │ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ 1 │ 2 │ 1 │ 2 │ * │ 1 │ //│ 1 │ 1 │ 2 │ 1 │ 2 │ * │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ B │ 1 │ 0 │ 1 │ 1 │ 1 │ //│ 1 │ * │ 1 │ 0 │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 2 │ ■ │ 1 │ 0 │ 0 │ 0 │ //│ 1 │ 2 │ 2 │ 1 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ b │ ■ │ * │ 2 │ 1 │ b │ 0 │ //│ 0 │ 1 │ * │ 2 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ b │ ■ │ 1 │ 2 │ * │ 1 │ 0 │ //│ 1 │ 2 │ 1 │ 2 │ * │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ * │ ■ │ 0 │ 1 │ 1 │ 1 │ 0 │ //│ * │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │
//└───┴───┴───┴───┴───┴───┴───┘ //└───┴───┴───┴───┴───┴───┴───┘
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
//┌───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ 1 │ 1 │ B │ //│ 0 │ 1 │ 1 │ 1 │ 1 │ * │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ B │ 1 │ 1 │ ■ │ //│ 0 │ 1 │ * │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ 0 │ 2 │ 2 │ 2 │ 0 │ 0 │ //│ 0 │ 2 │ 2 │ 2 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ B │ 2 │ 1 │ 1 │ //│ 0 │ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 1 │ 2 │ * │ 1 │ //│ 1 │ 2 │ 1 │ 2 │ * │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 0 │ 1 │ 1 │ 1 │ //│ * │ 1 │ 0 │ 1 │ 1 │ 1 │
//└───┴───┴───┴───┴───┴───┘ //└───┴───┴───┴───┴───┴───┘
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
//┌───┬───┬───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ 0 │ 0 │ 0 │ 1 │ 1 │ b │ B │ //│ 0 │ 0 │ 0 │ 0 │ 1 │ 1 │ 2 │ * │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 1 │ 0 │ 1 │ * │ 2 │ 1 │ //│ 1 │ 1 │ 1 │ 0 │ 1 │ * │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ B │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │ //│ 1 │ * │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ 1 │ 1 │ 0 │ 0 │ 0 │ 0 │ 0 │ //│ 1 │ 1 │ 1 │ 0 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 0 │ 1 │ 1 │ 1 │ 0 │ ■ │ //│ 1 │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 0 │ 1 │ * │ 1 │ 0 │ 0 │ //│ * │ 1 │ 0 │ 1 │ * │ 1 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 0 │ 1 │ 1 │ 1 │ 1 │ 1 │ //│ 1 │ 1 │ 0 │ 1 │ 1 │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ 0 │ 0 │ 0 │ 0 │ 0 │ 1 │ * │ //│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 1 │ * │
//└───┴───┴───┴───┴───┴───┴───┴───┘ //└───┴───┴───┴───┴───┴───┴───┴───┘
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

#pragma region Tablero5

//┌───┬───┬───┬───┬───┐
//│ 0 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┤
//│ 0 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┤
//│ 0 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┤
//│ 0 │ 1 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┤
//│ 0 │ 1 │ * │ 1 │ 0 │
//└───┴───┴───┴───┴───┘

tablero unaSolaMina = {
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cMINA,  cVACIA, cVACIA}, // mina en (4, 2)
};
banderitas b3 {};

#pragma endregion Tablero5

#pragma endregion Tableros

TEST(jugarPlusTest, imprimirAlgo){
    printTablero(unaSolaMina, {}, {});
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
        if (!encontrada){
            return false;
        }
    }
    return jugadasEsperadas.size() == jugadasDevueltas.size();
}

jugadas subVectorJugadas(jugadas vectorJugadas, int inicio, int final){
    jugadas subVectorJ = jugadas();
    for (int i = inicio; i < final; ++i) {
        subVectorJ.push_back(vectorJugadas[i]);
    }
    return subVectorJ;
}



void testJugadasDevueltas(pos posJugada, jugadas jugadasEsperadas, tablero t, banderitas banderitasTablero, jugadas jugadasTablero){
    int cantidadDeJugadasOriginales = jugadasTablero.size();

    jugarPlus(t,banderitasTablero,posJugada,jugadasTablero);
    //jugadasTablero.push_back(jugada(posJugada, minasAdyacentes(t,posJugada)));

    jugadas jugadasNuevas = subVectorJugadas(jugadasTablero,cantidadDeJugadasOriginales,jugadasTablero.size());
    if (minasAdyacentes(t,posJugada) > 0){
        ASSERT_TRUE(jugadasNuevas.size() == 1 && sonPosIguales(jugadasNuevas[0].first, posJugada));
    } else{
        bool sonMismasJugadas = mismasJugadas(jugadasEsperadas, jugadasNuevas);
        ASSERT_TRUE(sonMismasJugadas);
    }
}

#pragma region TestTablero1

TEST(jugarPlusTest, tablero1pos_0_4){
    pos posJugada = pos(0,4);
    jugadas jugadasEsperadas = {
            jugada(pos(0, 4), 1),
            //
            //
            //
            //
    };
    testJugadasDevueltas(posJugada, jugadasEsperadas, t1, banderitasTab1, jugadasTab1);
}

TEST(jugarPlusTest, tablero1pos_4_4){
    pos posJugada = pos(4,4);
    jugadas jugadasEsperadas = {
            //
            //
            jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
            jugada(pos(3, 4), 0),
            jugada(pos(4, 4), 0),
    };
    testJugadasDevueltas(posJugada, jugadasEsperadas, t1, banderitasTab1, jugadasTab1);

}

#pragma endregion TestTablero1

#pragma region TestTablero2
TEST(jugarPlusTest, tablero2pos_6_6){
    pos posJugada = pos(6,6);
    jugadas jugadasEsperadas = {
            //
            jugada(pos(1, 2), 2),jugada(pos(1, 3), 1),jugada(pos(1, 4), 2),
            jugada(pos(2, 2), 1),jugada(pos(2, 3), 0),jugada(pos(2, 4), 1),jugada(pos(2, 5), 1),jugada(pos(2, 6), 1),
            jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),jugada(pos(3, 5), 0),jugada(pos(3, 6), 0),
            jugada(pos(4, 3), 2),jugada(pos(4, 4), 1),jugada(pos(4, 6), 0),
            jugada(pos(5, 5), 1),jugada(pos(5, 6), 0),
            jugada(pos(6, 5), 1),jugada(pos(6, 6), 0),
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t2, banderitasTab2, jugadasTab2);

}

TEST(jugarPlusTest, tablero2pos_6_2){
    pos posJugada = pos(6,2);
    jugadas jugadasEsperadas = {
            //
            //
            //
            //
            //
            jugada(pos(5, 2), 1),jugada(pos(5, 3), 2),
            jugada(pos(6, 2), 0),jugada(pos(6, 3), 1),
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t2, banderitasTab2, jugadasTab2);

}

TEST(jugarPlusTest, tablero2pos_3_0){
    pos posJugada = pos(3,0);
    jugadas jugadasEsperadas = {
            //
            //
            //
            jugada(pos(3, 0), 1),
            //
            //
            //
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t2, banderitasTab2, jugadasTab2);

}

TEST(jugarPlusTest, tablero2pos_2_3){
    pos posJugada = pos(2,3);
    jugadas jugadasEsperadas = {
            //
            jugada(pos(1, 2), 2),jugada(pos(1, 3), 1),jugada(pos(1, 4), 2),
            jugada(pos(2, 2), 1),jugada(pos(2, 3), 0),jugada(pos(2, 4), 1),jugada(pos(2, 5), 1),jugada(pos(2, 6), 1),
            jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),jugada(pos(3, 5), 0),jugada(pos(3, 6), 0),
            jugada(pos(4, 3), 2),jugada(pos(4, 4), 1),jugada(pos(4, 6), 0),
            jugada(pos(5, 5), 1),jugada(pos(5, 6), 0),
            jugada(pos(6, 5), 1),jugada(pos(6, 6), 0),
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t2, banderitasTab2, jugadasTab2);

}

TEST(jugarPlusTest, tablero2pos_2_6){
    pos posJugada = pos(2,6);
    jugadas jugadasEsperadas = {
            //
            //
            jugada(pos(2, 6), 0),
            //
            //
            //
            //
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t2, banderitasTab2, jugadasTab2);

}

#pragma endregion TestTablero2

#pragma region TestTablero3

TEST(jugarPlusTest, tablero3pos_1_0){
    pos posJugada = pos(1,0);
    jugadas jugadasEsperadas = {
            //
            jugada(pos(1, 0), 0), jugada(pos(1, 1), 1),
            jugada(pos(2, 0), 0), jugada(pos(2, 1), 2),
            jugada(pos(3, 0), 0), jugada(pos(3, 1), 1),
            //
            //
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t3, banderitasTab3, jugadasTab3);

}

TEST(jugarPlusTest, tablero3pos_2_5){
    pos posJugada = pos(2,5);
    jugadas jugadasEsperadas = {
            //
            jugada(pos(1, 3), 1),jugada(pos(1, 4), 1),
            jugada(pos(2, 3), 2),jugada(pos(2, 4), 0),jugada(pos(2, 5), 0),
            jugada(pos(3, 3), 2),jugada(pos(3, 4), 1),jugada(pos(3, 5), 1),
            //
            //
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t3, banderitasTab3, jugadasTab3);

}

TEST(jugarPlusTest, tablero3pos_3_3){
    pos posJugada = pos(3,3);
    jugadas jugadasEsperadas = {
            //
            //
            //
            jugada(pos(3, 3), 2),
            //
            //
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t3, banderitasTab3, jugadasTab3);

}

#pragma endregion TestTablero3

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

#pragma region TestTablero4
TEST(jugarPlusTest, tablero4pos_0_1){
    pos posJugada = pos(0,1);
    jugadas jugadasEsperadas = {
            jugada(pos(0,1), 0), jugada(pos(0,2), 0), jugada(pos(0,3), 0), jugada(pos(0,4), 1),
            jugada(pos(1,0), 1), jugada(pos(1,1), 1), jugada(pos(1,2), 1), jugada(pos(1,3), 0), jugada(pos(1,4), 1), jugada(pos(1,6), 2), jugada(pos(1,7),1),
            jugada(pos(2,2), 1), jugada(pos(2,3), 0), jugada(pos(2,4), 1), jugada(pos(2,5), 1), jugada(pos(2,6), 1), jugada(pos(2,7), 0),
            jugada(pos(3,1), 1), jugada(pos(3,2), 1), jugada(pos(3,3), 0), jugada(pos(3,4), 0), jugada(pos(3,5), 0), jugada(pos(3,6), 0), jugada(pos(3,7), 0),
            jugada(pos(4,2), 0), jugada(pos(4,3), 1), jugada(pos(4,4), 1), jugada(pos(4,5), 1), jugada(pos(4,6), 0),
            jugada(pos(5,1), 1), jugada(pos(5,2), 0), jugada(pos(5,3), 1), jugada(pos(5,5), 1), jugada(pos(5,6), 0), jugada(pos(5,7), 0),
            jugada(pos(6,0), 1), jugada(pos(6,1), 1), jugada(pos(6,2), 0), jugada(pos(6,3), 1), jugada(pos(6,4), 1), jugada(pos(6,5), 1), jugada(pos(6,6),1), jugada(pos(6,7),1),
            jugada(pos(7,1), 0), jugada(pos(7,2), 0), jugada(pos(7,3), 0), jugada(pos(7,4), 0), jugada(pos(7,5), 0), jugada(pos(7,6), 1)

    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t4, banderitasTab4, jugadasTab4);

}

TEST(jugarPlusTest, tablero4pos_7_1){
    pos posJugada = pos(7,1);
    jugadas jugadasEsperadas = {
            jugada(pos(0,1), 0), jugada(pos(0,2), 0), jugada(pos(0,3), 0), jugada(pos(0,4), 1),
            jugada(pos(1,0), 1), jugada(pos(1,1), 1), jugada(pos(1,2), 1), jugada(pos(1,3), 0), jugada(pos(1,4), 1), jugada(pos(1,6), 2), jugada(pos(1,7),1),
            jugada(pos(2,2), 1), jugada(pos(2,3), 0), jugada(pos(2,4), 1), jugada(pos(2,5), 1), jugada(pos(2,6), 1), jugada(pos(2,7), 0),
            jugada(pos(3,1), 1), jugada(pos(3,2), 1), jugada(pos(3,3), 0), jugada(pos(3,4), 0), jugada(pos(3,5), 0), jugada(pos(3,6), 0), jugada(pos(3,7), 0),
            jugada(pos(4,2), 0), jugada(pos(4,3), 1), jugada(pos(4,4), 1), jugada(pos(4,5), 1), jugada(pos(4,6), 0),
            jugada(pos(5,1), 1), jugada(pos(5,2), 0), jugada(pos(5,3), 1), jugada(pos(5,5), 1), jugada(pos(5,6), 0), jugada(pos(5,7), 0),
            jugada(pos(6,0), 1), jugada(pos(6,1), 1), jugada(pos(6,2), 0), jugada(pos(6,3), 1), jugada(pos(6,4), 1), jugada(pos(6,5), 1), jugada(pos(6,6),1), jugada(pos(6,7),1),
            jugada(pos(7,1), 0), jugada(pos(7,2), 0), jugada(pos(7,3), 0), jugada(pos(7,4), 0), jugada(pos(7,5), 0), jugada(pos(7,6), 1)

    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t4, banderitasTab4, jugadasTab4);

}

TEST(jugarPlusTest, tablero4pos_5_5){
    pos posJugada = pos(5,5);
    jugadas jugadasEsperadas = {
            jugada(pos(5,5), 1)
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t4, banderitasTab4, jugadasTab4);

}

TEST(jugarPlusTest, tablero4pos_3_2){
    pos posJugada = pos(3,2);
    jugadas jugadasEsperadas = {
            jugada(pos(3,2), 1)
    };

    testJugadasDevueltas(posJugada, jugadasEsperadas, t4, banderitasTab4, jugadasTab4);

}

TEST(jugarPlusTest, tablero4pos_4_6){
    pos posJugada = pos(4,6);
    jugadas jugadasEsperadas = {
            jugada(pos(0,1), 0), jugada(pos(0,2), 0), jugada(pos(0,3), 0), jugada(pos(0,4), 1),
            jugada(pos(1,0), 1), jugada(pos(1,1), 1), jugada(pos(1,2), 1), jugada(pos(1,3), 0), jugada(pos(1,4), 1), jugada(pos(1,6), 2), jugada(pos(1,7),1),
            jugada(pos(2,2), 1), jugada(pos(2,3), 0), jugada(pos(2,4), 1), jugada(pos(2,5), 1), jugada(pos(2,6), 1), jugada(pos(2,7), 0),
            jugada(pos(3,1), 1), jugada(pos(3,2), 1), jugada(pos(3,3), 0), jugada(pos(3,4), 0), jugada(pos(3,5), 0), jugada(pos(3,6), 0), jugada(pos(3,7), 0),
            jugada(pos(4,2), 0), jugada(pos(4,3), 1), jugada(pos(4,4), 1), jugada(pos(4,5), 1), jugada(pos(4,6), 0),
            jugada(pos(5,1), 1), jugada(pos(5,2), 0), jugada(pos(5,3), 1), jugada(pos(5,5), 1), jugada(pos(5,6), 0), jugada(pos(5,7), 0),
            jugada(pos(6,0), 1), jugada(pos(6,1), 1), jugada(pos(6,2), 0), jugada(pos(6,3), 1), jugada(pos(6,4), 1), jugada(pos(6,5), 1), jugada(pos(6,6),1), jugada(pos(6,7),1),
            jugada(pos(7,1), 0), jugada(pos(7,2), 0), jugada(pos(7,3), 0), jugada(pos(7,4), 0), jugada(pos(7,5), 0), jugada(pos(7,6), 1)
    };


    testJugadasDevueltas(posJugada, jugadasEsperadas, t4, banderitasTab4, jugadasTab4);

}
#pragma endregion TestTablero4

TEST(jugarPlusTest, juegoSobreUnaMina) {
    jugadas j = {};
    pos posMina = pos(4, 2);
    jugarPlus(unaSolaMina, b3, posMina, j);
    // al pisar la mina no se descubren posiciones adicionales (ademas pierdo, pero eso no lo chequeo en este test)
    ASSERT_EQ(j.size(), 1);
};