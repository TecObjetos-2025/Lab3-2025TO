// tests/test_tarea.cpp

#include <gtest/gtest.h>
#include "Tarea.h"
#include "Profesor.h"

TEST(TareaTest, CreacionYEstadoInicial)
{
    // Profesor antes de Tarea
    Profesor profe(201, "Maribel", "Guevara");

    // Crear tarea
    Tarea tarea(1, "Matematicas", &profe, "2025-09-30");

    EXPECT_EQ(tarea.getCurso(), "Matematicas");
    EXPECT_EQ(tarea.getFechaPresentacion(), "2025-09-30");

    // Verificar https://crpcut.sourceforge.net/0.8.3/ASSERT_NE.html
    ASSERT_NE(tarea.getProfesor(), nullptr);
    EXPECT_EQ(tarea.getProfesor()->getId(), 201);

    // Tarea no entregada (por defecto)
    EXPECT_FALSE(tarea.isEntregada());
}

TEST(TareaTest, MarcarComoEntregada)
{
    Profesor profe(205, "Juan", "Villar");
    Tarea tarea(2, "Historia", &profe, "2025-10-05");

    EXPECT_FALSE(tarea.isEntregada());

    // Cambiar estado
    tarea.marcarComoEntregada();

    EXPECT_TRUE(tarea.isEntregada());
}