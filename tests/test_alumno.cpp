// tests/test_alumno.cpp
#include <gtest/gtest.h>
#include "Alumno.h"

TEST(AlumnoTest, CreacionYGetters)
{
    Alumno alumno(101, "Fabricio", "Balarezo", 5);

    // Verificar datos creados
    EXPECT_EQ(alumno.getId(), 101);
    EXPECT_EQ(alumno.getNombres(), "Fabricio");
    EXPECT_EQ(alumno.getApellidos(), "Balarezo");
    EXPECT_EQ(alumno.getGrado(), 5);

    // Verificar funcion virtual
    EXPECT_EQ(alumno.getTipo(), "Alumno");
}