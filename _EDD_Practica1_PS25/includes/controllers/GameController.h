//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FichasController.h"
#include "PalabrasController.h"
#include "../models/Jugador.h"
#include "../models/Tablero.h"
#include "../structs/Cola.h"
#include "../structs/LinkedList.h"
#include "../structs/Stack.h"


class GameController {

private:
    LinkedList<Jugador> *jugadores;
    Cola<Jugador*> *turnos;
    Stack<std::string> *historialPalabrasEncontradas;
    LinkedList<std::string> *palabrasNoEncontradas;
    LinkedList<std::string> *palabrasIniciales;
    Tablero *tablero;
    long tiempoTotalTurno;
    int totalTurnos;

    PalabrasController *palabrasController;
    FichasController *fichasController;

public:
    GameController();

    void cargarJugadores();

    void barajarTurnos();

    void jugar();

    int calcularPuntuacion(std::string &palabra);

};



#endif //GAMECONTROLLER_H
