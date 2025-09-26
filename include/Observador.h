// include/Observador.h
#ifndef OBSERVADOR_H
#define OBSERVADOR_H

class Tarea;

class Observador
{
public:
    virtual ~Observador() = default;
    // Sujeto actualiza al Observador
    virtual void actualizar(Tarea *tarea) = 0;
};

#endif