// tests/test_sistema_gestion.cpp
#include <gtest/gtest.h>
#include "SistemaGestion.h"
#include "Alumno.h"
#include "Profesor.h"

// Guia: https://www.tutorialspoint.com/gtest/gtest-test-fixtures.htm
class SistemaGestionTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        SistemaGestion::resetInstance();
    }

    void TearDown() override
    {
        SistemaGestion::resetInstance();
    }
};

TEST_F(SistemaGestionTest, InstanciaUnica)
{
    // Obtener la instancia
    SistemaGestion *instancia1 = SistemaGestion::getInstance();

    ASSERT_NE(instancia1, nullptr);

    // Obteniendo instancia otra vez
    SistemaGestion *instancia2 = SistemaGestion::getInstance();

    // Si todo va bien, deberia ser la misma direccion de memoria
    EXPECT_EQ(instancia1, instancia2);
}

TEST_F(SistemaGestionTest, RegistroYConsultaPersonas)
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

TEST_F(SistemaGestionTest, DestructorLiberaMemoria)
{
    ASSERT_EQ(Persona::contadorInstancias, 0);

    // Obtener instancias y registrar  personas
    SistemaGestion *sistema = SistemaGestion::getInstance();
    sistema->registrarAlumno(105, "Test", "Memoria1", 1);
    sistema->registrarProfesor(205, "Test", "Memoria2");

    ASSERT_EQ(Persona::contadorInstancias, 2);

    // Verificar destruccion Singleton
    SistemaGestion::resetInstance();

    // El contador deberia ser 0
    EXPECT_EQ(Persona::contadorInstancias, 0);
}

TEST_F(SistemaGestionTest, AsignarAlumnoAProfesor)
{
    SistemaGestion *sistema = SistemaGestion::getInstance();

    sistema->registrarAlumno(101, "Fabricio", "Balarezo", 6);
    sistema->registrarProfesor(201, "Maribel", "Guevara");

    // La asignación debe ser exitosa.
    bool exito = sistema->asignarAlumnoAProfesor(101, 201);
    EXPECT_TRUE(exito);

    // Verificamos que el profesor ahora tiene 1 alumno.
    Profesor *profe = dynamic_cast<Profesor *>(sistema->getPersona(201));
    ASSERT_NE(profe, nullptr);
    EXPECT_EQ(profe->getCantidadAlumnos(), 1);

    // Probamos un caso de fallo (ID de alumno no existe).
    bool fallo = sistema->asignarAlumnoAProfesor(999, 201);
    EXPECT_FALSE(fallo);
}

TEST_F(SistemaGestionTest, ContarTareasEntregadasPorAlumno)
{
    SistemaGestion *sistema = SistemaGestion::getInstance();

    sistema->registrarAlumno(101, "Fabricio", "Balarezo", 6);
    sistema->registrarProfesor(201, "Maribel", "Guevara");

    // Orden de ID (Tarea, Alumno y Profesor)
    sistema->registrarTarea(501, "Matematica Basica", 101, 201, "2025-10-01"); // NUEVO METODO PARA IMPLEMENTAR
    sistema->registrarTarea(502, "Historia del Peru", 101, 201, "2025-10-03");
    sistema->registrarTarea(503, "Ciencia y Tecnologia", 101, 201, "2025-10-05");

    // Marcar una tarea
    Tarea *tareaEntregada = sistema->getTarea(502); // NUEVO METODO A IMPLEMENTAR
    ASSERT_NE(tareaEntregada, nullptr);
    tareaEntregada->marcarComoEntregada();

    int numEntregadas = sistema->contarTareasEntregadasDeAlumno(101); // NUEVO METODO PARA CONSULTA

    EXPECT_EQ(numEntregadas, 1);

    sistema->registrarAlumno(102, "Axel", "Barriga", 6);
    EXPECT_EQ(sistema->contarTareasEntregadasDeAlumno(102), 0);
}