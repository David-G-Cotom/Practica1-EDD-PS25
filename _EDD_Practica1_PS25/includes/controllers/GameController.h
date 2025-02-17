//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

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

public:
    GameController();

    void cargarJugadores();

    void barajarTurnos();

    void jugar();

};



#endif //GAMECONTROLLER_H
