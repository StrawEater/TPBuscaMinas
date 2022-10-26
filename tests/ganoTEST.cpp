// Tests para la función gano.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

TEST(ganoTEST, Gano){
    jugadas j = jugadasGano;
    ASSERT_TRUE(gano(t, j));
}

TEST(aunNoganoTEST, aunNoGano){
    jugadas j = aunNoGano;
    ASSERT_FALSE(gano(t, j));
}

TEST(noganoTEST, noGano){
    jugadas j = noGano;
    ASSERT_FALSE(gano(t, j));
}
