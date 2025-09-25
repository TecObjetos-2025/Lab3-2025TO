// src/Persona.cpp
#include "Persona.h"

// Contador en 0
int Persona::contadorInstancias = 0;

Persona::Persona(int id, const std::string &nombres, const std::string &apellidos)
    : id(id), nombres(nombres), apellidos(apellidos)
{
    contadorInstancias++;
}

Persona::~Persona()
{
    contadorInstancias--;
}
