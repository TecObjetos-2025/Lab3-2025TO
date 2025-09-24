// src/Alumno.cpp
#include "Alumno.h"

// Implementacion de constructor
Alumno::Alumno(int id, const std::string &nombres, const std::string &apellidos, int grado)
    : Persona(id, nombres, apellidos), grado(grado) {}

// Implementacion Getter
int Alumno::getGrado() const
{
    return grado;
}

// Metodo virtual
std::string Alumno::getTipo() const
{
    return "Alumno";
}