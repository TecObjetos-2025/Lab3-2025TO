// src/SistemaGestion.cpp
#include "SistemaGestion.h"

// Iniciar puntero estatico
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

SistemaGestion::SistemaGestion() {}

SistemaGestion::~SistemaGestion()
{
    for (Persona *p : personas)
    {
        delete p;
    }
    for (Tarea *t : tareas)
    {
        delete t;
    }
}