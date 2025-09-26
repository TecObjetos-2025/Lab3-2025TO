// src/main.cpp
#include <iostream>
#include <string>
#include <limits>

// Sistema principal
#include "SistemaGestion.h"

// --- Funciones auxiliares de la UI ---
void mostrarMenu();
void registrarAlumnoUI();
void registrarProfesorUI();
void registrarTareaUI();
void consultarTareasDeAlumnoUI();
void consultarAlumnosDeProfesorUI();

int main()
{
    SistemaGestion *sistema = SistemaGestion::getInstance();
    int opcion = 0;

    std::cout << "------------------------------------------" << std::endl;
    std::cout << " Sistema de Gestion Academica - v1.0" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // Bucle principal de la aplicación
    do
    {
        mostrarMenu();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        // --- Manejo de Errores de Entrada ---
        if (std::cin.fail())
        {
            std::cout << "\n[ERROR] Entrada invalida. Por favor, ingrese un numero.\n"
                      << std::endl;
            std::cin.clear(); // Limpiar la bandera de error de cin.
            // Ignorar el resto de la línea de entrada incorrecta.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Volver al inicio del bucle.
        }

        // Procesar la opción del usuario
        switch (opcion)
        {
        case 1:
            registrarAlumnoUI();
            break;
        case 2:
            registrarProfesorUI();
            break;
        case 3:
            registrarTareaUI();
            break;
        case 4:
            consultarTareasDeAlumnoUI();
            break;
        case 5:
            consultarAlumnosDeProfesorUI();
            break;
        case 6:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "\n[ERROR] Opcion no valida. Intente de nuevo.\n"
                      << std::endl;
            break;
        }

    } while (opcion != 6);

    // Llamar al reset para buena practica
    SistemaGestion::resetInstance();

    return 0;
}

// --- Implementación de funciones auxiliares ---

void mostrarMenu()
{
    std::cout << "\n===== MENU PRINCIPAL =====" << std::endl;
    std::cout << "1. Registrar Alumno" << std::endl;
    std::cout << "2. Registrar Profesor" << std::endl;
    std::cout << "3. Registrar Tarea" << std::endl;
    std::cout << "4. Consultar tareas entregadas de un Alumno" << std::endl;
    std::cout << "5. Consultar alumnos de un Profesor" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "==========================" << std::endl;
}

void registrarAlumnoUI()
{
    int id, grado;
    std::string nombres, apellidos;

    std::cout << "\n--- Registrar Nuevo Alumno ---" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;

    // --- Validación ---
    if (SistemaGestion::getInstance()->getPersona(id) != nullptr)
    {
        std::cout << "\n[ERROR] Ya existe una persona con el ID " << id << ". No se pudo registrar.\n"
                  << std::endl;
        // Limpiar el buffer de entrada 'Just in case'
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Salir de la función para evitar el registro.
    }

    std::cout << "Nombres: ";
    std::cin.ignore(); // Limpiar el buffer antes de leer una línea completa
    std::getline(std::cin, nombres);
    std::cout << "Apellidos: ";
    std::getline(std::cin, apellidos);
    std::cout << "Grado (1-6): ";
    std::cin >> grado;

    SistemaGestion::getInstance()->registrarAlumno(id, nombres, apellidos, grado);
    std::cout << "\n[INFO] Alumno registrado con exito.\n"
              << std::endl;
}

void consultarTareasDeAlumnoUI()
{
    int idAlumno;
    std::cout << "\n--- Consultar Tareas de Alumno ---" << std::endl;
    std::cout << "Ingrese el ID del Alumno: ";
    std::cin >> idAlumno;

    // Validar que el alumno exista
    if (SistemaGestion::getInstance()->getPersona(idAlumno) == nullptr)
    {
        std::cout << "\n[ERROR] No se encontro un alumno con ese ID.\n"
                  << std::endl;
        return;
    }

    int numTareas = SistemaGestion::getInstance()->contarTareasEntregadasDeAlumno(idAlumno);
    std::cout << "\n[INFO] El alumno con ID " << idAlumno << " ha entregado " << numTareas << " tarea(s).\n"
              << std::endl;
}

void registrarProfesorUI()
{
    int id;
    std::string nombres, apellidos;

    std::cout << "\n--- Registrar Nuevo Profesor ---" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;

    // --- Validación ---
    if (SistemaGestion::getInstance()->getPersona(id) != nullptr)
    {
        std::cout << "\n[ERROR] Ya existe una persona con el ID " << id << ". No se pudo registrar.\n"
                  << std::endl;
        // Limpiar el buffer de entrada 'Just in case'
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Salir de la función para evitar el registro.
    }

    std::cout << "Nombres: ";
    std::cin.ignore(); // Limpiar el buffer antes de leer una línea completa
    std::getline(std::cin, nombres);
    std::cout << "Apellidos: ";
    std::getline(std::cin, apellidos);

    SistemaGestion::getInstance()->registrarProfesor(id, nombres, apellidos);
    std::cout << "\n[INFO] Profesor registrado con exito.\n"
              << std::endl;
}

void registrarTareaUI()
{
    int id;
    int idAlumno;
    int idProfesor;
    std::string curso, fecha;

    std::cout << "\n--- Registrar Nueva Tarea ---" << std::endl;
    std::cout << "ID de Tarea: ";
    std::cin >> id;
    std::cout << "ID del Alumno Asignado: ";
    std::cin >> idAlumno;
    std::cout << "ID del profesor a Cargo: ";
    std::cin >> idProfesor;

    // --- Validación ---
    Persona *alumno = SistemaGestion::getInstance()->getPersona(idAlumno);
    Persona *profesor = SistemaGestion::getInstance()->getPersona(idProfesor);

    if (alumno == nullptr || alumno->getTipo() != "Alumno")
    {
        std::cout << "\n[ERROR] No se encontro un Alumno con el ID " << idAlumno << ". No se pudo registrar la tarea.\n"
                  << std::endl;
        return;
    }
    if (profesor == nullptr || profesor->getTipo() != "Profesor")
    {
        std::cout << "\n[ERROR] No se encontro un Profesor con el ID " << idProfesor << ". No se pudo registrar la tarea.\n"
                  << std::endl;
        return;
    }

    std::cout << "Curso: ";
    std::cin.ignore(); // Limpiar el buffer antes de leer una línea completa
    std::getline(std::cin, curso);
    std::cout << "Fecha (YYYY-MM-DD): ";
    std::getline(std::cin, fecha);

    SistemaGestion::getInstance()->registrarTarea(id, curso, idAlumno, idProfesor, fecha);
    std::cout << "\n[INFO] Tarea registrada con exito.\n"
              << std::endl;
}
void consultarAlumnosDeProfesorUI()
{
    int idProfesor;
    std::cout << "\n--- Consultar Alumnos asignados a Profesor ---" << std::endl;
    std::cout << "Ingrese el ID del Profesor: ";
    std::cin >> idProfesor;

    // --- Validación ---
    Persona *persona = SistemaGestion::getInstance()->getPersona(idProfesor);

    // Verificar que la persona exista Y que sea del tipo correcto.
    if (persona == nullptr || persona->getTipo() != "Profesor")
    {
        std::cout << "\n[ERROR] No se encontro un Profesor con ese ID.\n"
                  << std::endl;
        return;
    }

    int numAlumnos = SistemaGestion::getInstance()->contarAlumnosDeProfesor(idProfesor);
    std::cout << "\n[INFO] El profesor con ID " << idProfesor << " tiene: " << numAlumnos << " registrado(s).\n"
              << std::endl;
}