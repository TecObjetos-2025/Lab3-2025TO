// src/Tarea.cpp

#include <iostream>
#include "Tarea.h"
#include "Profesor.h"

Tarea::Tarea(int id, const std::string &curso, Alumno *alumno, Profesor *profesor, const std::string &fecha)
    : id(id), curso(curso), alumnoAsignado(alumno), profesorACargo(profesor), fechaPresentacion(fecha), entregada(false) {}

// Getters

int Tarea::getId() const
{
    return id;
}

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

Alumno *Tarea::getAlumno() const
{
    return alumnoAsignado;
}

// Acciones de Tarea (Refactor para patron observer)
void Tarea::marcarComoEntregada()
{
    this->entregada = true;
    std::cout << "TAREA " << this->id << ": Ha sido entregada. Notificando..." << std::endl;
    notificarObservadores(this);
}