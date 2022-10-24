// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

banderitas b = {pos(2,2),pos(3,1),pos(5,8),pos(3,4),pos(1,2),pos(9,9)};

TEST(cambiarBanderitasTest, pruebaBoluda){
    (cambiarBanderita(t, jugadasValidas, pos(3,1), b));
}