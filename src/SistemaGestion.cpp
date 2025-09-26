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

bool SistemaGestion::asignarAlumnoAProfesor(int idAlumno, int idProfesor)
{
    Persona *ptrAlumno = getPersona(idAlumno);
    Persona *ptrProfesor = getPersona(idProfesor);

    if (ptrAlumno == nullptr || ptrProfesor == nullptr)
    {
        return false;
    }

    Alumno *alumno = dynamic_cast<Alumno *>(ptrAlumno);
    Profesor *profesor = dynamic_cast<Profesor *>(ptrProfesor);

    // Si el tipo no es el correcto se debe fallar
    if (alumno == nullptr || profesor == nullptr)
    {
        return false;
    }

    // Si todo bien, hacer la asignacion con exito
    profesor->agregarAlumno(alumno);
    return true;
}

// NUEVOS METODOS DE GESTION
void SistemaGestion::registrarTarea(int id, const std::string &curso, int idAlumno, int idProfesor, const std::string &fecha)
{
    Alumno *alumno = dynamic_cast<Alumno *>(getPersona(idAlumno));
    Profesor *profesor = dynamic_cast<Profesor *>(getPersona(idProfesor));
    if (alumno && profesor)
    {
        Tarea *nuevaTarea = new Tarea(id, curso, alumno, profesor, fecha);
        tareas.push_back(nuevaTarea);
    }
}

Tarea *SistemaGestion::getTarea(int id) const
{
    for (Tarea *t : tareas)
    {
        if (t->getId() == id)
        {
            return t;
        }
    }
    return nullptr;
}

int SistemaGestion::contarTareasEntregadasDeAlumno(int idAlumno) const
{
    int contador = 0;
    for (Tarea *t : tareas)
    {
        if (t->getAlumno() != nullptr && t->getAlumno()->getId() == idAlumno)
        {
            if (t->isEntregada())
            {
                contador++;
            }
        }
    }
    return contador;
}

int SistemaGestion::contarAlumnosDeProfesor(int idProfesor) const
{
    Profesor *profesor = dynamic_cast<Profesor *>(getPersona(idProfesor));
    if (profesor)
    {
        return profesor->getCantidadAlumnos();
    }
    return 0; // De momento se maneja el error de manera sencilla
}
