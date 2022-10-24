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
    //Verifico que todas las posiciones sean iguales y esten en la misma posicion
    for (int i = 0; i < bandOriginal.size(); ++i) {
        if(!sonPosIguales(bandOriginal[i], bandAgregada[i])) return false;
    }
    //Por ultimo verifico que la unica diferencia entre los vectores sea la posicion p, que deberia estar en el ultimo index
    return (bandAgregada.size() == bandOriginal.size() + 1) && sonPosIguales(bandAgregada[bandAgregada.size()-1],p);
}

bool esMismaBanderitaConPosEliminada(banderitas bandOriginal, banderitas bandEliminada, pos p) {
    //Verifico que todas las posiciones sean iguales y esten en la misma posicion a excepcion de la pos eliminada
    for (int i = 0 , j = 0; i < bandOriginal.size(); ++i,++j) {
        if(!sonPosIguales(bandOriginal[i], bandEliminada[j])){
            //Si llego al index de la pos eliminada, retraso al contador de bandEliminada por 1, para sincronizarlo
            //con el contador de bandOriginales
            if (sonPosIguales(bandOriginal[i], bandEliminada[j])){
                j--;
            } else {
                return false;
            }
        }
    }
    //Por ultimo verifico que la unica diferencia entre los vectores sea la posicion p, que deberia estar en el ultimo index
    return (bandOriginal.size() == bandEliminada.size() + 1);
}

TEST(cambiarBanderitasTest, pruebaBoluda){
    banderitas copiaBanderitas = banderitas(b);
    banderitas valorAntiguoBanderitas = banderitas(copiaBanderitas);
    cambiarBanderita(t,jugadasValidas,pos(2,2),copiaBanderitas);

    ASSERT_TRUE(esMismaBanderitaConPosAgregada(valorAntiguoBanderitas,copiaBanderitas, pos(2,3)));
}