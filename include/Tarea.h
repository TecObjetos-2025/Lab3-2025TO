// include/Tarea.h
#ifndef TAREA_H
#define TAREA_H

#include <string>
#include "Sujeto.h"

class Profesor;

class Tarea : public Sujeto
{
private:
    int id; // NUEVO! para identificar
    std::string curso;
    std::string fechaPresentacion;
    bool entregada;
    Profesor *profesorACargo; // Puntero para referenciar al profesor.

public:
    // Constructor
    Tarea(int id, const std::string &curso, Profesor *profesor, const std::string &fecha);

    // Destructor por default, no necesita eliminar objetos
    ~Tarea() = default;

    // Getters
    int getId() const;
    std::string getCurso() const;
    std::string getFechaPresentacion() const;
    bool isEntregada() const;
    Profesor *getProfesor() const;

    // Métodos de acción
    void marcarComoEntregada();
};

#endif // TAREA_H