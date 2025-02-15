cmake_minimum_required(VERSION 3.28)
project(_EDD_Practica1_PS25)

set(CMAKE_CXX_STANDARD 23)

add_executable(_EDD_Practica1_PS25 main.cpp
        includes/models/Ficha.h
        src/models/Ficha.cpp
        includes/structs/ListaEnlazada/ListaFichas.h
        includes/structs/ListaEnlazada/NodoLista.h
        src/structs/ListaEnlazada/NodoLista.cpp
        src/structs/ListaEnlazada/ListaFichas.cpp
        includes/models/Jugador.h
        src/models/Jugador.cpp
        includes/models/Movimiento.h
        src/models/Movimiento.cpp
        includes/structs/Pila/PilaMovimiento.h
        includes/structs/Pila/NodoPila.h
        src/structs/Pila/PilaMovimiento.cpp
        src/structs/Pila/NodoPila.cpp
        includes/models/Tablero.h
        src/models/Tablero.cpp
        includes/controllers/PalabrasController.h
        src/controllers/PalabrasController.cpp
        includes/controllers/GameController.h
        src/controllers/GameController.cpp
        includes/controllers/ReportsController.h
        src/controllers/ReportsController.cpp
)
