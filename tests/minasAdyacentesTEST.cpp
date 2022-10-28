// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"
#include "testDefiniciones.h"

TEST(minasAdyacentesTest, celdaCentro){
    EXPECT_EQ(minasAdyacentes(t, pos(2,2)),2);
}

TEST(minasAdyacentesTest, celdaBorde){
    EXPECT_EQ(minasAdyacentes(t, pos(0,4)),1);
}

TEST(minasAdyacentesTest, celdaConBomba){
    EXPECT_EQ(minasAdyacentes(t, pos(1,3)),0);
}