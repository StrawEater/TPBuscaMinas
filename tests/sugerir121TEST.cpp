// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

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
//│ 1 │ 1 │ 1 │ 2 │ * │ 1 │
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



TEST(sugerir121TEST, SugerirCon1){
    ASSERT_TRUE(sugerirAutomatico121(tablero t3 , banderitas& b, jugadas& j, pos& p));
}
}

#pragma endregion Tablero3

//┌───┬───┬───┬───┬───┬───┬───┬───┐
//│ 0 │ 0 │ 0 │ 0 │ 1 │ 1 │ 1 │ * │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 1 │ 0 │ 1 │ * │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ B │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 1 │ 0 │ 0 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 0 │ 1 │ 1 │ 1 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 0 │ 1 │ * │ 1 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 1 │ 0 │ 1 │ 1 │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┼───┤
//│ * │ 0 │ 0 │ 0 │ 0 │ 0 │ 1 │ * │
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


