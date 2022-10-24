// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

TEST(perdioTEST, todaviaNoPerdio){
    jugadas j = jugadasMitadJuego;
    ASSERT_FALSE(perdio(t, j));
}

TEST(perdioTEST, Perdio){
    jugadas j = jugadasPerdioJuego;
    ASSERT_TRUE(perdio(t, j));
}
