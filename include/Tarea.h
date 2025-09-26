// include/Tarea.h
#ifndef TAREA_H
#define TAREA_H

#include <string>
#include "Sujeto.h"

class Profesor;
class Alumno;

class Tarea : public Sujeto
{
private:
    int id;
    std::string curso;
    std::string fechaPresentacion;
    bool entregada;
    Profesor *profesorACargo; // Puntero para referenciar al profesor.
    Alumno *alumnoAsignado;   // Para funciones de consulta

public:
    // Constructor
    Tarea(int id, const std::string &curso, Alumno *alumno, Profesor *profesor, const std::string &fecha);

    // Destructor por default, no necesita eliminar objetos
    ~Tarea() = default;

    // Getters
    int getId() const;
    std::string getCurso() const;
    std::string getFechaPresentacion() const;
    bool isEntregada() const;
    Profesor *getProfesor() const;
    Alumno *getAlumno() const;

    // Métodos de acción
    void marcarComoEntregada();
};

#endif // TAREA_H