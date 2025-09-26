// include/Sujeto.h
#ifndef SUJETO_H
#define SUJETO_H

#include <vector>
#include "Observador.h"

class Sujeto
{
protected:
    std::vector<Observador *> observadores;

public:
    virtual ~Sujeto() = default;

    void agregarObservador(Observador *o)
    {
        observadores.push_back(o);
    }

    void notificarObservadores(Tarea *tarea)
    {
        for (Observador *o : observadores)
        {
            o->actualizar(tarea);
        }
    }
};

#endif