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
        jugada(pos(2, 0), 1), jugada(pos(2, 2), 2), jugada(pos(4, 4), 0),
        jugada(pos(4, 3), 1),
};

static jugadas jugadasPerdioJuego = {
        jugada(pos(2, 0), 1), jugada(pos(2, 2), 2), jugada(pos(4, 4), 0),
        jugada(pos(4, 3), 1), jugada(pos(0, 0), 1),
};

static jugadas jugadasValidas = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};

static jugadas jugadasGano = {
        jugada(pos(0, 2), 2),jugada(pos(0, 3), 1),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};

static jugadas aunNoGano = {
        jugada(pos(0, 2), 2),
        jugada(pos(0, 4), 1),jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),
        jugada(pos(1, 4), 1),jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),
        jugada(pos(2, 4), 1),jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),
        jugada(pos(3, 4), 0),jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};

static jugadas noGano = {
        jugada(pos(0, 0), 1),jugada(pos(0, 3), 1),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};

static void printTablero(tablero ts, banderitas banderitasTab, jugadas jugadasTab){
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


//--------------------------------------