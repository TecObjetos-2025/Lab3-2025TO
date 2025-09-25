# --- Plantilla de CMakeLists.txt ---

# Versión mínima de CMake requerida.
cmake_minimum_required(VERSION 3.14)

# Definición del proyecto: Nombre y versión.
project(Lab03 VERSION 1.0)

# C++17 como opción moderna y sólida.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Integración de Google Test (GTest) ---
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG    release-1.12.1
)
# GTest disponible para ser usado en el proyecto.
FetchContent_MakeAvailable(googletest)

# --- Definición de Ejecutables ---

# 1. Definición de la librería "core" y el ejecutable principal "mainApp".
add_library(core
  src/Persona.cpp
  src/Alumno.cpp
  src/Profesor.cpp
  src/Tarea.cpp
  src/SistemaGestion.cpp
)

target_include_directories(core PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(mainApp src/main.cpp)

target_link_libraries(mainApp PRIVATE core)

# 2. El ejecutable para las pruebas.
# Habilitar las pruebas para que CTest (el corredor de pruebas de CMake) las reconozca.
enable_testing()

# Crear un ejecutable llamado "runTests" para las pruebas.
add_executable(runTests
    tests/test_main.cpp
    tests/test_alumno.cpp
    tests/test_profesor.cpp
    tests/test_tarea.cpp
    tests/test_sistema_gestion.cpp
)

# Vincular la librería de Google Test  y el core al ejecutable de pruebas.
target_link_libraries(runTests PRIVATE core GTest::gtest_main)

# Final añadir las pruebas al corredor de pruebas de CMake.
# Pruebas automáticas con Google Test.
include(GoogleTest)
gtest_discover_tests(runTests)