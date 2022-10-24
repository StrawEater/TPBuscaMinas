// Tests para la función gano.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

using namespace std;

TEST(ganoTEST, todaviaNoGano){
    jugadas j = jugadasValidas;
    ASSERT_FALSE(gano(t, j));
}
