// src/Profesor.cpp

#include <iostream>
#include "Profesor.h"
#include "Alumno.h"
#include "Tarea.h"

// Implementar constructor
Profesor::Profesor(int id, const std::string &nombres, const std::string &apellidos)
    : Persona(id, nombres, apellidos) {}

// Destructor (la responsabilidad la tiene el SistemaGestion)
Profesor::~Profesor() {}

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

// Metodos para logica con Patron Observer
void Profesor::actualizar(Tarea *tarea)
{
    std::cout << "PROFESOR " << this->getNombres() << ": Notificado de la tarea del curso " << tarea->getCurso() << std::endl;
    this->tareasRecibidas++;
}

int Profesor::getTareasRecibidas() const
{
    return tareasRecibidas;
}