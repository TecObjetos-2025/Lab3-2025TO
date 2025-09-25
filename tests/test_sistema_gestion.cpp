// tests/test_sistema_gestion.cpp
#include <gtest/gtest.h>
#include "SistemaGestion.h"
#include "Alumno.h"

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

TEST(SistemaGestionFuncionalidadTest, RegistroYConsultaPersonas)
{
    SistemaGestion *sistema = SistemaGestion::getInstance();

    // Registrar alumnos y profesores
    sistema->registrarAlumno(101, "Fabricio", "Balarezo", 6);
    sistema->registrarProfesor(201, "Maribel", "Guevara");

    // Buscar por ID.
    Persona *personaAlumno = sistema->getPersona(101);
    Persona *personaProfesor = sistema->getPersona(201);

    // Verificar que se encontro con exito
    ASSERT_NE(personaAlumno, nullptr);
    ASSERT_NE(personaProfesor, nullptr);

    // Son del tipo correcto?
    EXPECT_EQ(personaAlumno->getTipo(), "Alumno");
    EXPECT_EQ(personaProfesor->getTipo(), "Profesor");

    // Guia: https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/
    // Acceder a las funciones de la clase derivada
    Alumno *alumno = dynamic_cast<Alumno *>(personaAlumno);
    ASSERT_NE(alumno, nullptr);
    EXPECT_EQ(alumno->getGrado(), 6);
}