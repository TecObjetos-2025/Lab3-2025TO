// src/Profesor.cpp

#include "Profesor.h"
#include "Alumno.h"

// Implementar constructor
Profesor::Profesor(int id, const std::string &nombres, const std::string &apellidos)
    : Persona(id, nombres, apellidos) {}

// Destructor (liberando memoria por cada Alumno)
Profesor::~Profesor()
{
    for (Alumno *alumno : alumnosACargo)
    {
        delete alumno;
    }
}

// GESTION DE ALUMNOS
void Profesor::agregarAlumno(Alumno *alumno)
{
    alumnosACargo.push_back(alumno);
}

int Profesor::getCantidadAlumnos() const
{
    return alumnosACargo.size();
}

std::string Profesor::getTipo() const
{
    return "Profesor";
}