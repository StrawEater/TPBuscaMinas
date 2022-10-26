#pragma once   // esta línea es para que el archivo se incluya una sola vez
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"

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
static tablero t = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

static jugadas jugadasMitadJuego = {
        jugada(pos(2, 0), 2), jugada(pos(2, 2), 2), jugada(pos(4, 4), 0),
        jugada(pos(4, 3), 0),
};

static jugadas jugadasPerdioJuego = {
        jugada(pos(2, 0), 2), jugada(pos(2, 2), 2), jugada(pos(4, 4), 0),
        jugada(pos(4, 3), 0), jugada(pos(0, 0), 1),
};



static jugadas jugadasValidas = {
        jugada(pos(1, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};

/*pos ultimaPosicion = pos(4, 4);
jugadas jugadasValidasGano = jugadasValidas;
jugadasValidasGano.push_back(ultimaPosicion);
*/


static jugadas jugadasGano = {
        jugada(pos(2, 0), 1),jugada(pos(3, 0), 1),
        jugada(pos(4, 0), 1),jugada(pos(0, 1), 3),jugada(pos(1, 1), 3),jugada(pos(2, 1), 3),
        jugada(pos(4, 1), 1),jugada(pos(0, 2), 1),jugada(pos(2, 2), 2),jugada(pos(3, 2), 1),
        jugada(pos(4, 2), 1),jugada(pos(0, 3), 2),jugada(pos(1, 3), 3),jugada(pos(2, 3), 2),jugada(pos(3, 3), 1),
        jugada(pos(4, 3), 0),jugada(pos(1, 4), 2),jugada(pos(3, 4), 1),jugada(pos(4, 4), 0),
};

static jugadas aunNoGano = {
        jugada(pos(2, 0), 1),
        jugada(pos(4, 0), 1),jugada(pos(0, 1), 3),jugada(pos(1, 1), 3),jugada(pos(2, 1), 3),
        jugada(pos(4, 1), 1),jugada(pos(0, 2), 1),jugada(pos(2, 2), 2),jugada(pos(3, 2), 1),
        jugada(pos(4, 2), 1),jugada(pos(0, 3), 2),jugada(pos(1, 3), 3),jugada(pos(2, 3), 2),jugada(pos(3, 3), 1),
        jugada(pos(4, 3), 0),jugada(pos(1, 4), 2),jugada(pos(3, 4), 1),jugada(pos(4, 4), 0),
};

static jugadas noGano = {
        jugada(pos(0, 0), 1),jugada(pos(3, 0), 1),
        jugada(pos(4, 0), 1),jugada(pos(0, 1), 3),jugada(pos(1, 1), 3),jugada(pos(2, 1), 3),
        jugada(pos(4, 1), 1),jugada(pos(0, 2), 1),jugada(pos(2, 2), 2),jugada(pos(3, 2), 1),
        jugada(pos(4, 2), 1),jugada(pos(0, 3), 2),jugada(pos(1, 3), 3),jugada(pos(2, 3), 2),jugada(pos(3, 3), 1),
        jugada(pos(4, 3), 0),jugada(pos(1, 4), 2),jugada(pos(3, 4), 1),jugada(pos(4, 4), 0),
};