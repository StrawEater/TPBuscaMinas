// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

static banderitas b = {
        pos(2,2),pos(3,1),
        pos(5,8),pos(3,4),
        pos(1,2),pos(9,9),
};

bool esMismaBanderitaConPosAgregada(banderitas bandOriginal, banderitas bandAgregada, pos p) {
    for (int i = 0; i < bandOriginal.size(); ++i) {
        if(!sonPosIguales(bandOriginal[i], bandAgregada[i])) return false;
    }
    return bandAgregada.size() == bandAgregada.size() && sonPosIguales(bandAgregada[bandAgregada.size()-1],p);
}

bool esMismaBanderitaConPosEliminada(banderitas b1, banderitas b2, pos p) {

}

TEST(cambiarBanderitasTest, pruebaBoluda){
    banderitas valorAntiguoBanderitas = b.co(b.begin(), b.end(),)
    ASSERT_TRUE(cambiarBanderita(t,jugadasValidas,pos(2,2),b))
}