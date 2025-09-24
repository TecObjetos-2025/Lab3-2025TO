// tests/test_profesor.cpp
#include <gtest/gtest.h>
#include "Profesor.h"
#include "Alumno.h"

// Test para la clase Profesor
TEST(ProfesorTest, CreacionYGetters)
{
    Profesor profe(201, "Maribel", "Guevara");

    EXPECT_EQ(profe.getId(), 201);
    EXPECT_EQ(profe.getNombres(), "Maribel");
    EXPECT_EQ(profe.getApellidos(), "Guevara");
    EXPECT_EQ(profe.getTipo(), "Profesor");
}

TEST(ProfesorTest, GestionDeAlumnos)
{
    Profesor profe(201, "Maribel", "Guevara");

    // Sin alumnos al principio
    EXPECT_EQ(profe.getCantidadAlumnos(), 0);

    // Crear alumnos para que profesor los guarde
    Alumno *alumno1 = new Alumno(102, "Fabricio", "Balarezo", 5);
    Alumno *alumno2 = new Alumno(103, "Juan", "Villagran", 5);

    // Metodo de profesor para agregar alumnos
    profe.agregarAlumno(alumno1);
    profe.agregarAlumno(alumno2);

    // Verificar que se actualizo la cantidad
    EXPECT_EQ(profe.getCantidadAlumnos(), 2);
}
