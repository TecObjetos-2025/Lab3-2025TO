// include/Profesor.h

#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"
#include "Observador.h"
#include <vector>
#include <string>

class Alumno;

class Profesor : public Persona, public Observador
{
private:
    std::vector<Alumno *> alumnosACargo;
    int tareasRecibidas = 0;

public:
    // Constructor
    Profesor(int id, const std::string &nombres, const std::string &apellidos);

    // Destructor (Responsabilidad de liberar memoria recae en el SistemaGestion)
    ~Profesor();

    // Gestionar Alumnos
    void agregarAlumno(Alumno *alumno);
    int getCantidadAlumnos() const;

    // Funcion Virtual
    std::string getTipo() const override;

    // Metodos para logica con PATRON OBSERVER
    void actualizar(Tarea *tarea) override;
    int getTareasRecibidas() const;
};

#endif