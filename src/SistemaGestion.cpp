// src/SistemaGestion.cpp
#include "SistemaGestion.h"
#include "Alumno.h"
#include "Profesor.h"

#include <iostream>

// Iniciar puntero estatico en null
SistemaGestion *SistemaGestion::instance = nullptr;

// Metodo estatico para getInstance()
SistemaGestion *SistemaGestion::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SistemaGestion();
    }
    return instance;
}

// Metodo para reiniciar singleton
void SistemaGestion::resetInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr; // Nulo para el futuro
    }
}

SistemaGestion::SistemaGestion() {}

SistemaGestion::~SistemaGestion()
{
    for (auto &par : personas)
    {
        delete par;
    }
    personas.clear();
    for (Tarea *t : tareas)
    {
        delete t;
    }
}

void SistemaGestion::registrarAlumno(int id, const std::string &nombres, const std::string &apellidos, int grado)
{
    Alumno *nuevoAlumno = new Alumno(id, nombres, apellidos, grado);
    this->personas.push_back(nuevoAlumno);
}

void SistemaGestion::registrarProfesor(int id, const std::string &nombres, const std::string &apellidos)
{
    Profesor *nuevoProfesor = new Profesor(id, nombres, apellidos);
    this->personas.push_back(nuevoProfesor);
}

Persona *SistemaGestion::getPersona(int id) const
{
    // Recorrer vector de punteros
    for (Persona *p : this->personas)
    {
        if (p->getId() == id)
        {
            return p;
        }
    }
    return nullptr; // Si no se encuentra, retornar null
}