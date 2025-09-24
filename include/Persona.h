// include/Persona.h
#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
protected: // Para herencia
    int id;
    std::string nombres;
    std::string apellidos;

public:
    // Constructor
    Persona(int id, const std::string &nombres, const std::string &apellidos)
        : id(id), nombres(nombres), apellidos(apellidos) {}

    // Destructor virtual
    virtual ~Persona() {}

    // Getters
    int getId() const { return id; }
    std::string getNombres() const { return nombres; }
    std::string getApellidos() const { return apellidos; }

    // --- Función Virtual Pura ---
    virtual std::string getTipo() const = 0;
};

#endif // PERSONA_H