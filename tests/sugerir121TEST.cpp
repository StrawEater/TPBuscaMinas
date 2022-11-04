// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

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
//┌───┬───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ * │ 2 │ ■ │ b │ //│ 0 │ 0 │ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ ■ │ ■ │ 2 │ * │ 1 │ //│ 1 │ 1 │ 2 │ 1 │ 2 │ * │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ B │ 1 │ 0 │ 1 │ 1 │ 1 │ //│ 1 │ * │ 1 │ 0 │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ 2 │ ■ │ 1 │ 0 │ 0 │ 0 │ //│ 1 │ 2 │ 2 │ 1 │ 0 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ b │ ■ │ * │ 2 │ 1 │ b │ 0 │ //│ 0 │ 1 │ * │ 2 │ 1 │ 1 │ 0 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ 1 │ ■ │ 1 │ 2 │ * │ 1 │ 0 │ //│ 1 │ 2 │ 1 │ 2 │ * │ 1 │ 0 │
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
        //
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
//┌───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ 1 │ 1 │ B │ //│ 0 │ 1 │ 1 │ 1 │ 1 │ * │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ B │ 1 │ ■ │ ■ │ //│ 0 │ 1 │ * │ 1 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ 0 │ ■ │ 2 │ 2 │ ■ │ 0 │ //│ 0 │ 2 │ 2 │ 2 │ 0 │ 0 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ 0 │ 1 │ B │ 2 │ 2 │ 1 │ //│ 0 │ 1 │ * │ 2 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 2 │ * │ 2 │ * │ //│ 1 │ 2 │ 2 │ * │ 2 │ * │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ * │ 1 │ 1 │ ■ │ ■ │ ■ │ //│ * │ 1 │ 1 │ 1 │ 2 │ 1 │
//└───┴───┴───┴───┴───┴───┘ //└───┴───┴───┴───┴───┴───┘
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
//┌───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┐
//│ ■ │ * │ ■ │ 1 │ 2 │ ■ │ //│ 1 │ * │ 2 │ 1 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ ■ │ ■ │ 2 │ * │ //│ 2 │ 2 │ 3 │ * │ 2 │ * │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ * │ 3 │ 2 │ ■ │ 2 │ //│ 1 │ * │ 3 │ 2 │ 4 │ 2 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 3 │ * │ 2 │ * │ //│ 2 │ 2 │ 3 │ * │ 2 │ * │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ * │ ■ │ ■ │ ■ │ ■ │ //│ 1 │ * │ 2 │ 1 │ 2 │ 1 │
//├───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┤
//│ ■ │ 1 │ 1 │ 0 │ ■ │ 0 │ //│ 1 │ 1 │ 1 │ 0 │ 0 │ 0 │
//└───┴───┴───┴───┴───┴───┘ //└───┴───┴───┴───┴───┴───┘
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
//┌───┬───┬───┐ //┌───┬───┬───┐
//│ ■ │ ■ │ ■ │ //│ 1 │ 2 │ 1 │
//├───┼───┼───┤ //├───┼───┼───┤
//│ * │ ■ │ * │ //│ * │ 2 │ * │
//├───┼───┼───┤ //├───┼───┼───┤
//│ ■ │ ■ │ ■ │ //│ 1 │ 2 │ 1 │
//└───┴───┴───┘ //└───┴───┴───┘
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

#pragma endregion Tablero5

#pragma region Tablero6
//┌───┬───┬───┬───┬───┬───┬───┐ //┌───┬───┬───┬───┬───┬───┬───┐
//│ ■ │ ■ │ ■ │ * │ 2 │ ■ │ b │ //│ 0 │ 0 │ 1 │ * │ 2 │ 1 │ 1 │
//├───┼───┼───┼───┼───┼───┼───┤ //├───┼───┼───┼───┼───┼───┼───┤
//│ ■ │ ■ │ 2 │ ■ │ 2 │ * │ 1 │ //│ 1 │ 1 │ 2 │ 1 │ 2 │ * │ 1 │
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


static tablero t6 = {
        { cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA },
        { cVACIA, cMINA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cMINA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cMINA, cVACIA, cVACIA },
        { cMINA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
};

static banderitas banderitasTab6 = {
        pos(0,6),
        //
        pos(2,1),
        //
        pos(4,0),pos(4,5),
        pos(5,0),
        //

};

static jugadas jugadasTab6 = {
        jugada(pos(0, 0), 0), jugada(pos(0, 1), 0),jugada(pos(0, 2), 1), jugada(pos(0, 5), 1),
        jugada(pos(1, 0), 1), jugada(pos(1, 1), 1), jugada(pos(1, 3), 1),
        //
        jugada(pos(3, 2), 2),
        jugada(pos(4, 1), 1),
        jugada(pos(5, 1), 2),
        jugada(pos(6, 1), 1),
};

#pragma endregion Tablero6

#pragma endregion Tableros

int getIndexPos(vector<pos> posiciones, pos posicionAEncontrar){
    for (int i = 0; i < posiciones.size(); ++i) {
        if (sonPosIguales(posiciones[i],posicionAEncontrar)){
            return i;
        }
    }
    return -1;
}

bool validarSugerencia121(tablero t,banderitas banderitasTab,jugadas jugadasTab, bool valorEsperado,vector<pos> posEsperadas){
    pos posDevuelta;
    bool resultadoReal = sugerirAutomatico121(t, banderitasTab, jugadasTab, posDevuelta);
    if (valorEsperado == resultadoReal){
        if (valorEsperado == true){
            return (getIndexPos(posEsperadas,posDevuelta) != -1);
        }else{
            return true;
        }
    }else{
        return false;
    }
}

TEST(sugerir121TEST, imprimirAlgo){
    printTablero(t6, {}, {});
    ASSERT_TRUE(true);
}

TEST(sugerir121TEST, tablero1){
    bool respuestaEsperada = false;
    vector<pos> posicionesEsperadas;
    ASSERT_TRUE(validarSugerencia121(t1,banderitasTab1,jugadasTab1,respuestaEsperada,posicionesEsperadas));
}

TEST(sugerir121TEST, tablero2){
    bool respuestaEsperada = true;
    vector<pos> posicionesEsperadas = {
            //
            //
            pos(2,2),
            //
            //
            pos(5,0),pos(5,2),
            //
    };
    ASSERT_TRUE(validarSugerencia121(t2,banderitasTab2,jugadasTab2,respuestaEsperada,posicionesEsperadas));
}

TEST(sugerir121TEST, tablero3){
    bool respuestaEsperada = true;
    vector<pos> posicionesEsperadas = {
            //
            //
            //
            //
            pos(4,4),
            //
    };
    ASSERT_TRUE(validarSugerencia121(t3,banderitasTab3,jugadasTab3,respuestaEsperada,posicionesEsperadas));
}

TEST(sugerir121TEST, tablero4){
    bool respuestaEsperada = true;
    vector<pos> posicionesEsperadas = {
            //
            //
            //
            pos(3,4),
            //
            //
    };
    ASSERT_TRUE(validarSugerencia121(t4,banderitasTab4,jugadasTab4,respuestaEsperada,posicionesEsperadas));
}

TEST(sugerir121TEST, tablero5){
    bool respuestaEsperada = false;
    vector<pos> posicionesEsperadas;
    ASSERT_TRUE(validarSugerencia121(t5,banderitasTab5,jugadasTab5,respuestaEsperada,posicionesEsperadas));
}

TEST(sugerir121TEST, tablero6){
    bool respuestaEsperada = true;
    vector<pos> posicionesEsperadas = {
            //
            //
            //
            //
            //
            pos(5,2),
            //
    };
    ASSERT_TRUE(validarSugerencia121(t6,banderitasTab6,jugadasTab6,respuestaEsperada,posicionesEsperadas));
}

