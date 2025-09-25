// tests/test_sistema_gestion.cpp
#include <gtest/gtest.h>
#include "SistemaGestion.h"

TEST(SistemaGestionSingletonTest, InstanciaUnica)
{
    // Obtener la instancia
    SistemaGestion *instancia1 = SistemaGestion::getInstance();

    ASSERT_NE(instancia1, nullptr);

    // Obteniendo instancia otra vez
    SistemaGestion *instancia2 = SistemaGestion::getInstance();

    // Si todo va bien, deberia ser la misma direccion de memoria
    EXPECT_EQ(instancia1, instancia2);
}