cmake_minimum_required(VERSION 3.28)
project(_EDD_Practica1_PS25)

set(CMAKE_CXX_STANDARD 23)

add_executable(_EDD_Practica1_PS25 main.cpp
        includes/models/Ficha.h
        src/models/Ficha.cpp
        includes/models/Jugador.h
        src/models/Jugador.cpp
        includes/models/Tablero.h
        src/models/Tablero.cpp
        includes/controllers/PalabrasController.h
        src/controllers/PalabrasController.cpp
        includes/controllers/GameController.h
        src/controllers/GameController.cpp
        includes/controllers/ReportsController.h
        src/controllers/ReportsController.cpp
        includes/controllers/FichasController.h
        src/controllers/FichasController.cpp
        includes/structs/Node.h
        includes/structs/LinkedList.h
        includes/structs/Cola.h
        includes/structs/Stack.h
        includes/Utils.h
        src/Utils.cpp
        includes/models/Casilla.h
        src/models/Casilla.cpp
)
