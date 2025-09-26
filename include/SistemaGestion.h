// include/SistemaGestion.h
#ifndef SISTEMA_GESTION_H
#define SISTEMA_GESTION_H

#include <vector>
#include "Persona.h"
#include "Tarea.h"

class SistemaGestion
{
private:
    static SistemaGestion *instance;

    // Privar el constructor (nadie mas puede crear instancias)
    SistemaGestion();

    // Atri. Geestion del Sistema
    std::vector<Persona *> personas;
    std::vector<Tarea *> tareas;

public:
    // Guia:https://refactoring.guru/es/design-patterns/singleton/cpp/example
    // Los singleton no deben ser cloneables
    SistemaGestion(const SistemaGestion &) = delete;
    // Los singleton no deben ser asignables (copiados)
    void operator=(const SistemaGestion &) = delete;

    // Acceso Global
    static SistemaGestion *getInstance();

    // Reiniciar para pruebas de memoria
    static void resetInstance();

    // Destructor
    ~SistemaGestion();

    // Metodos de Gestion
    void registrarAlumno(int id, const std::string &nombres, const std::string &apellidos, int grado);
    void registrarProfesor(int id, const std::string &nombres, const std::string &apellidos);
    Persona *getPersona(int id) const;
    bool asignarAlumnoAProfesor(int idAlumno, int idProfesor);

    // Nuevas funciones de gestion
    void registrarTarea(int id, const std::string &curso, int idAlumno, int idProfesor, const std::string &fecha);
    Tarea *getTarea(int id) const;
    int contarTareasEntregadasDeAlumno(int idAlumno) const;
    int contarAlumnosDeProfesor(int idProfesor) const;
};

#endif