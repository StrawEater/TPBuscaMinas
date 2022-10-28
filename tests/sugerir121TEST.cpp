// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

#pragma region Tableros

#pragma region Tablero1
//┌───┬───┐
//│ 1 │ * │
//├───┼───┤
//│ 1 │ 1 │
//└───┴───┘

static tablero t1 = {
        { cVACIA, cMINA,},
        { cVACIA, cVACIA,},
};

static banderitas banderitasTab1 = {

};

static jugadas jugadasTab1 = {
        jugada(pos(0, 0), 1),
};

#pragma endregion Tablero1

#pragma region Tablero2
//┌───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ * │ 2 │ ■ │ b │
//├───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ ■ │ ■ │ 2 │ * │ 1 │
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
        jugada(pos(1, 0), 1), jugada(pos(1, 1), 1), jugada(pos(1, 2), 2), jugada(pos(1, 3), 1),
        //
        jugada(pos(3, 2), 2),
        jugada(pos(4, 1), 1),
        jugada(pos(5, 1), 2),
        jugada(pos(6, 1), 1),
};

#pragma endregion Tablero2

#pragma region Tablero3
//┌───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ 1 │ 1 │ B │
//├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ B │ 1 │ ■ │ ■ │
//├───┼───┼───┼───┼───┼───┤
//│ 0 │ ■ │ 2 │ 2 │ ■ │ 0 │
//├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ B │ 2 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 2 │ * │ 2 │ * │
//├───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 1 │ ■ │ ■ │ ■ │
//└───┴───┴───┴───┴───┴───┘
static tablero t3 = {
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA},
        { cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA},
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        { cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA},
        { cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cMINA},
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
        jugada(pos (1, 4), 1),jugada(pos (1, 5), 1),
        jugada(pos (2, 1), 2),jugada(pos (2, 4), 2),
        //
        jugada(pos (4, 0), 1), jugada(pos (4, 1), 2),
        jugada(pos (5, 3), 1), jugada(pos (5, 4), 2), jugada(pos (5, 5), 1),
};

#pragma endregion Tablero3

#pragma region Tablero4
//┌───┬───┬───┬───┬───┬───┐
//│ ■ │ * │ ■ │ 1 │ 2 │ ■ │
//├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ ■ │ ■ │ 2 │ * │
//├───┼───┼───┼───┼───┼───┤
//│ ■ │ * │ 3 │ 2 │ ■ │ 2 │
//├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 3 │ * │ 2 │ * │
//├───┼───┼───┼───┼───┼───┤
//│ ■ │ * │ ■ │ ■ │ ■ │ ■ │
//├───┼───┼───┼───┼───┼───┤
//│ ■ │ 1 │ 1 │ 0 │ ■ │ 0 │
//└───┴───┴───┴───┴───┴───┘
static tablero t4 = {
        { cVACIA, cMINA, cVACIA, cVACIA,cVACIA,cVACIA,},
        { cVACIA, cVACIA, cVACIA, cMINA,cVACIA,cMINA, },
        { cVACIA, cMINA, cVACIA, cVACIA,cVACIA,cVACIA,},
        { cVACIA, cVACIA, cVACIA, cMINA,cVACIA,cMINA,},
        { cVACIA, cMINA, cVACIA, cVACIA,cVACIA,cVACIA,},
        { cVACIA, cVACIA, cVACIA, cVACIA,cVACIA, cVACIA,},
};

static banderitas banderitasTab4 = {


};

static jugadas jugadasTab4 = {

        jugada(pos(0, 0), 1), jugada(pos(0, 2), 2), jugada(pos(0, 5), 1),
        jugada(pos(1, 0), 2), jugada(pos(1, 1), 2), jugada(pos(1, 2), 3), jugada(pos(1, 3), 4),
        jugada(pos(2, 0), 1), jugada(pos(2, 4), 4),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 2),
        jugada(pos(4, 0), 1), jugada(pos(4, 2), 2), jugada(pos(4, 3), 1), jugada(pos(4, 4), 2), jugada(pos(4, 5), 1),
        jugada(pos(5, 0), 1), jugada(pos(5, 4), 0),
};

#pragma endregion Tablero4

#pragma region Tablero5
//┌───┬───┬───┐
//│ ■ │ ■ │ ■ │
//├───┼───┼───┤
//│ * │ ■ │ * │
//├───┼───┼───┤
//│ ■ │ ■ │ ■ │
//└───┴───┴───┘
static tablero t5 = {
        { cVACIA, cVACIA, cVACIA,},
        { cMINA, cVACIA, cMINA,},
        { cVACIA, cVACIA, cVACIA,},

};

static banderitas banderitasTab5 = {


};

static jugadas jugadasTab5 = {

        jugada(pos(0, 0), 1), jugada(pos(0, 1), 2), jugada(pos(0, 2), 1),
        jugada(pos(1, 1), 2),
        jugada(pos(2, 0), 1), jugada(pos(2, 1), 2), jugada(pos(2, 2), 1)

};

#pragma endregion Tablero4

#pragma endregion Tableros

TEST(sugerir121TEST, imprimirAlgo){
    printTablero(t5, banderitasTab5, jugadasTab5);
    ASSERT_TRUE(true);
}

