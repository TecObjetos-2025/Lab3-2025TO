// include/Tarea.h
#ifndef TAREA_H
#define TAREA_H

#include <string>

class Profesor;

class Tarea
{
private:
    std::string curso;
    std::string fechaPresentacion;
    bool entregada;
    Profesor *profesorACargo; // Puntero para referenciar al profesor.

public:
    // Constructor
    Tarea(const std::string &curso, Profesor *profesor, const std::string &fecha);

    // Destructor por default, no necesita eliminar objetos
    ~Tarea() = default;

    // Getters
    std::string getCurso() const;
    std::string getFechaPresentacion() const;
    bool isEntregada() const;
    Profesor *getProfesor() const;

    // Métodos de acción
    void marcarComoEntregada();
};

#endif // TAREA_H