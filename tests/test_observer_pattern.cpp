// tests/test_observer_pattern
#include <gtest/gtest.h>
#include "Tarea.h"
#include "Profesor.h"

TEST(ObserverPatternTest, ProfesorEsNotificadoCuandoSeEntregaLaTarea)
{
    Profesor *profe = new Profesor(201, "Maribel", "Guevara");
    Tarea tarea(1, "Tecnologia de Objetos", profe, "2025-09-26");

    tarea.agregarObservador(profe);

    ASSERT_EQ(profe->getTareasRecibidas(), 0);

    tarea.marcarComoEntregada();

    EXPECT_EQ(profe->getTareasRecibidas(), 1);

    delete profe;
}