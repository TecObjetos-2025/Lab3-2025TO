// src/Tarea.cpp
#include "Tarea.h"
#include "Profesor.h"

Tarea::Tarea(const std::string &curso, Profesor *profesor, const std::string &fecha)
    : curso(curso), profesorACargo(profesor), fechaPresentacion(fecha), entregada(false) {}

// Getters

std::string Tarea::getCurso() const
{
    return curso;
}

std::string Tarea::getFechaPresentacion() const
{
    return fechaPresentacion;
}

bool Tarea::isEntregada() const
{
    return entregada;
}

Profesor *Tarea::getProfesor() const
{
    return profesorACargo;
}

// Acciones de Tarea
void Tarea::marcarComoEntregada()
{
    entregada = true;
}