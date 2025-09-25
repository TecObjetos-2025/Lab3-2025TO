// include/Profesor.h

#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"
#include <vector>
#include <string>

class Alumno;

class Profesor : public Persona
{
private:
    std::vector<Alumno *> alumnosACargo;

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
};

#endif