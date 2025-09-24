// include/Alumno.h
#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"
#include <string>
class Alumno : public Persona
{
private:
    int grado;

public:
    // Constructor
    Alumno(int id, const std::string &nombres, const std::string &apellidos, int grado);

    // Getter para alumno
    int getGrado() const;

    // Funcion virtual de clase base
    std::string getTipo() const override;
};

#endif