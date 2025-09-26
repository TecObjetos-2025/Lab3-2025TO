// tests/test_observer_pattern
#include <gtest/gtest.h>
#include "Tarea.h"
#include "Profesor.h"
#include "Observador.h"

// Mock como "doble"
class MockProfesor : public Observador
{
public:
    bool notificado = false;
    int idTareaNotificada = 0;

    void actualizar(Tarea *tarea) override
    {
        notificado = true;
        // Podria guardarse el ID y otra logica, esta es solo prueba
    }
};

TEST(ObserverPatternTest, ProfesorEsNotificadoCuandoSeEntregaLaTarea)
{
    MockProfesor mockProf;
    Profesor *profeReal = new Profesor(201, "Maribel", "Guevara");
    Tarea tarea(1, "Observer Pattern", profeReal, "2025-09-26");

    tarea.agregarObservador(&mockProf);

    ASSERT_FALSE(mockProf.notificado);

    tarea.marcarComoEntregada();

    EXPECT_TRUE(mockProf.notificado);

    delete profeReal;
}